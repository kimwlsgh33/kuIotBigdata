from flask import Flask
import pymysql

app = Flask(__name__)

host = "localhost"
port = 3306
database = "madangdb"
username = "root"
password = "0000"

# connection
conn = pymysql.connect(host=host, port=port, db=database, user=username, password=password, charset="utf8")

cursor = conn.cursor()
cursor.execute("SELECT * FROM Book")
books = cursor.fetchall()
cursor.close()
conn.close()

@app.route('/')
def index():
    outputStr = str()
    for book in books:
        for c in book:
            outputStr += str(c) + "     "
        outputStr += "<br>"
    return outputStr

# when run `app.py`
if __name__ == '__main__':
    # app.run("0.0.0.0")
    app.run(debug=True)
