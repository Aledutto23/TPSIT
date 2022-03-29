import flask 
from flask import jsonify, request
import sqlite3

app = flask.Flask(__name__)
app.config["DEBUG"] = True
@app.route('/', methods=['GET'])
def home():
    return "<h1>Biblioteca online </h1><p>Prototipo di web API.</p>"


                                    #instanza classe AlphaBot



@app.route('/api/v1/resources/books/all', 
methods=['GET'])
def api_all():
    con = sqlite3.connect("webAPI2.db")
    cur = con.cursor()                                                #creazione oggetto cursore            
    while True:    
        for row in cur.execute("SELECT * FROM Libri").fetchall():
            print (row)



@app.route('/api/v1/resources/books', methods=['GET'])
def api_id():
    if 'id' in request.args:
        id = int(request.args['id'])
    else:
        return "Error: No id field provided. Please specify an id."
    results = []

    for book in books:
        if book['id'] == id:
            results.append(book)

    return jsonify(results)

app.run()

