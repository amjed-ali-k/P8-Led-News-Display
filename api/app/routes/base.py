
from fastapi import APIRouter
import requests, datetime, random

from app.models.otherweb import NewsApi, NewsinDB, ResponseNews
from app.database import news_db

app = APIRouter()

def fetch_new_news():
    print('Hit new fetch')
    res = requests.get("https://s.valurank.com/api/v1/otherweb/news?query=&sort=recent&category=tech&cutoff=tech:81&source=Reuters&source=WIRED&source=ReutersBiz&source=ReutersScience&source=Gizmodo&source=WorldAndScience&source=iPhone_News&source=NatGeo&source=guardianscience&source=ScienceNews&source=WIREDScience&source=PhysicsWorld&source=WIREDBusiness&source=BBCScienceNews&source=macworld&source=BBCTech&source=gadgetlab&source=BBCBreaking&source=NBCNewsTech&source=ScienceMagazine")
    data = NewsApi(**res.json())
    news =  [ResponseNews(**item.dict()) for item in data.items]
    news_db.put(NewsinDB(items=news, updated=str(datetime.datetime.now().timestamp()), key='latest').dict())
    return news

def get_latest_news():
    latest = news_db.get('latest')
    if(latest is None):
        return fetch_new_news()
    news_list = NewsinDB(**latest)
    updated_time = datetime.datetime.fromtimestamp(float(news_list.updated))
    time_diff = (datetime.datetime.now() - updated_time)
    print(f'Cached for {time_diff.seconds}')
    if time_diff.seconds > 1 * 30 * 60:
        return fetch_new_news()
    return news_list.items

@app.get("/")
def base_route():
    return { "message" : "welcome"}

@app.get("/latest")
def fetch_latest_news():
    return get_latest_news()
    
@app.get("/random")
def get_random_news():
    return random.choice(get_latest_news())
