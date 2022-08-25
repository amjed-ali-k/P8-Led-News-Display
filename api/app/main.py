from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

from app.core.config import settings
from app.routes.base import app as route


def get_application():
    _app = FastAPI(title="News API")
    _app.include_router(route)
    # _app.add_middleware(
    #     CORSMiddleware,
    #     allow_origins=[str(origin) for origin in settings.BACKEND_CORS_ORIGINS],
    #     allow_credentials=True,
    #     allow_methods=["*"],
    #     allow_headers=["*"],
    # )

    return _app


