import requests
from app.models.inshorts import InshortsResponse
from app.models.otherweb import NewsApi
from app.models.common import NewsinDB, ResponseNews

def get_other_web_news():
    """
    Get the other web news
    :return:
    """
    res = requests.get("https://s.valurank.com/api/v1/otherweb/news?query=&sort=recent&category=tech&cutoff=tech:81&source=Reuters&source=WIRED&source=ReutersBiz&source=ReutersScience&source=Gizmodo&source=WorldAndScience&source=iPhone_News&source=NatGeo&source=guardianscience&source=ScienceNews&source=WIREDScience&source=PhysicsWorld&source=WIREDBusiness&source=BBCScienceNews&source=macworld&source=BBCTech&source=gadgetlab&source=BBCBreaking&source=NBCNewsTech&source=ScienceMagazine")
    data = NewsApi(**res.json())
    return [ResponseNews(**item.dict()) for item in data.items]

def get_inshorts_news() -> list[ResponseNews]:
    """
    Get the inshorts news
    :return:
    """

    res = requests.get("https://inshortsv2.vercel.app/news?type=startups&limit=20")
    data = InshortsResponse(**res.json())
    news = []
    for item in data.articles:
        news.append(ResponseNews(headline=item.title, summary=item.description))
    if (len(news) < 20):
        res = requests.get("https://inshortsv2.vercel.app/news?type=technology&limit=10")
        data = InshortsResponse(**res.json())
        for item in data.articles:
            news.append(ResponseNews(headline=item.title, summary=item.description))
    return news