import pymysql

def main():
    host = "localhost"
    port = 3306
    database = "madangdb"
    username = "root"
    password = "0000"

    # connection
    conflag=True

    try:
        conn = pymysql.connect(host=host, port=port, db=database, user=username, password=password, charset="utf8")
        print("connection success")
    except Exception as e:
        print("connection failed")
        conflag=False

    if conflag:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM Book")
        books = cursor.fetchall()
        for book in books:
            print(book)
        cursor.close()
        conn.close()

if __name__ == "__main__":
    main()
