

from app.core.config import settings
from deta import Deta


config_db = Deta(settings.DETA_PROJECT_KEY).Base('config')
news_db = Deta(settings.DETA_PROJECT_KEY).Base('news')

