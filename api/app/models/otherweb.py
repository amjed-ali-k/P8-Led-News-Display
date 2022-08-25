from typing import List
from pydantic import BaseModel, validator


class Item(BaseModel):
    category: str
    created_at: str
    headline: str
    id: str
    informative: float
    similar_childs: List[str]
    similar_parent: str
    source_name: str
    source_url: str
    source_username: str
    summary: str


class NewsApi(BaseModel):
    items: List[Item]
    search_after: str
    total: int


class ResponseNews(BaseModel):
    headline: str
    summary: str

    @validator('summary')
    def remove_linebreaks(cls, v):
        return v.replace("\n", ' ').replace('\\"', '"')

class NewsinDB(BaseModel):
    updated: str
    key: str
    items: List[ResponseNews]