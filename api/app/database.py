

from app.core.config import settings
from deta import Deta


config_db = Deta(settings.DETA_KEY).Base('config')
news_db = Deta(settings.DETA_KEY).Base('news')

