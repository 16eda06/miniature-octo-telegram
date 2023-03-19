#include"sqlite3.h"
#include<stdio.h>
int main() {
	// pointer to the db
	sqlite3 *db;
	// return code
	int rc;

	// SQL statements
	char* create_echo_table_sql = "create table echo_files (path text, content text)";


	rc = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE, NULL);
	if (rc != SQLITE_OK) {
		printf("Can't open the database : error = %s\n", sqlite3_errmsg(db));
	} else {
		printf("Opened an in-memory database\n");
	}
	sqlite3_close_v2(db);
}

