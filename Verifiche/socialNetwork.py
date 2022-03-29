
from re import U
import flask as fl
import sqlite3
import string
import random

from flask import Flask, render_template, redirect, url_for, request, make_response


app = Flask(__name__)
nickname = ""
token = ""
for _ in range(10):
    token += random.choice(string.ascii_letters)

def validate(username, password):
    completion = False
    con = sqlite3.connect('C:/Users/aledu/Desktop/Scuola/TPSIT/verifica_Dutto/socialNetwork.db')
    cur = con.cursor()
    cur.execute("SELECT * FROM USERS")
    rows = cur.fetchall()
    for row in rows:              
        dbUser = row[0]
        dbPass = row[1]
        if dbUser==username:
            completion=check_password(dbPass, password)
    con.close() 
    return completion 


def check_password(hashed_password, user_password):
    return hashed_password == user_password


@app.route('/', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        nickname = username
        print(nickname)
        completion = validate(username, password)
        if completion ==False:
            error = 'la password o il nome utente sono errati'
        else:
            resp = make_response(render_template('login.html', error=error))
            resp.set_cookie("username", username)
            return redirect(url_for('main'))
    return render_template('login.html', error=error)       


@app.route(f'/{token}', methods =['GET', 'POST'])
def main():
    if request.method == 'POST':
        print(nickname)
        con = sqlite3.connect('C:/Users/aledu/Desktop/Scuola/TPSIT/verifica_Dutto/socialNetwork.db')
        cur = con.cursor()
        stato = fl.request.form["stato"][:80] # interrompo la lunghezza della stringa a  un massimo di 80 caratteri
        cur.execute(f"INSERT INTO Stato (Stato, NomeUtente) VALUES ('{stato}', '{token}');")
        con.commit()
        con.close()
    return render_template('socialNetwork.html')

if __name__== "__main__":
    app.run(debug=True)