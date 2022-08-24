from fastapi import APIRouter


app = APIRouter()

@app.get("/")
def base_route():
    return { "message" : "welcome"}