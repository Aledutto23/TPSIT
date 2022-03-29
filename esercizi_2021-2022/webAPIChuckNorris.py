import requests
import json
import flask
from flask import jsonify, request

app = flask.Flask(__name__)
app.config["DEBUG"] = True

@app.route("api/ChuckNorris", methods=["GET"])
def home():
    if "joke" in request.args:
        joke = str(request.args["joke"])
    data = requests.get(f)
    tt = json.loads(data.text)
    
    print(tt["value"]["joke"])

chuck()