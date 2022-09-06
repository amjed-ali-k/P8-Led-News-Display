from typing import List

from pydantic import BaseModel


class Article(BaseModel):
    title: str
    description: str
    author_name: str
    source_name: str
    source_url: str
    image_url: str
    created_at: int
    inshorts_url: str


class InshortsResponse(BaseModel):
    total: int
    articles: List[Article]
