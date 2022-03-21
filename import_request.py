import request
id = input("inserire input")
f = request.get("http://127.0.0.1:5000/api/v1/resources/books?{id}")
r.jsonify()