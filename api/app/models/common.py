from typing import List
from pydantic import BaseModel, validator
import re

class ResponseNews(BaseModel):
    headline: str
    summary: str

    @validator('summary')
    def remove_linebreaks(cls, v: str):
        return "".join(re.findall(r"[A-z0-9,*' \-.]", v.replace("\n", ' ').replace('\\"', '"')))

    @validator('headline')
    def remove_linebreaks_from_headline(cls, v: str):
        return "".join(re.findall(r"[A-z0-9,*' \-.]", v.replace("\n", ' ').replace('\\"', '"')))

class NewsinDB(BaseModel):
    updated: str
    key: str
    items: List[ResponseNews]