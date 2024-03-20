#include <mysql.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;
  char *host = "localhost";
  char *user = "root";
  char *passwd = "0000";
  char *db = "madangdb";
  char query[255];
  int port = 3306;

  strcpy(query, "SELECT * FROM Book;");

  conn = mysql_init(NULL);
  if (mysql_real_connect(conn, host, user, passwd, db, port, NULL, 0)) {
    printf("MySQL 연결 성공\n");
  } else {
    printf("MySQL 연결 실패\n");
  }

  if (mysql_query(conn, query)) {
    printf("쿼리 실패\n");
  }

  res = mysql_store_result(conn);
  while (row = mysql_fetch_row(res)) {
    printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);
  }
  mysql_close(conn);
  return 0;
}
