import flask
import sqlite3
import socket as sck

serverweb = flask.Flask(__name__)

@serverweb.route("/", methods=["POST", "GET"])
def index():

    conn = sqlite3.connect("./data.db")
    curs = conn.cursor()

    socket = sck.socket(sck.AF_INET, sck.SOCK_STREAM)

    if flask.request.method == "POST":        
        ip = flask.request.form.get("ip")
        min_port = int(flask.request.form.get("min_port"))
        max_port = int(flask.request.form.get("max_port"))

        print(f"id:{ip}, min:{min_port}, max:{max_port}")

        for port in range(min_port, max_port):
            print(port)
            ris = socket.connect_ex((ip, port))
            print(ris)
            #connect ex ritorna 0 es funziona
            if ris:
                print("non fatta")
                
            else:
                serviceName = sck.getservbyport(port, "tcp")
                print(serviceName)

            curs.execute("INSERT INTO ip VALUES (?,?,?,?)", (None, port, ip, "disponibile" if ris else "occupata"))
            conn.commit()
            
        return flask.render_template('scanned.html')
    conn.close()
    socket.close()

    return flask.render_template('index.html')
    

if __name__ == "__main__":
    serverweb.run(debug=True, host="127.0.0.1")