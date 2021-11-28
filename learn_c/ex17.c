#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DATA 512
#define MAX_ROWS 100
struct Address {
		int id;
		int set;
		char email[MAX_DATA];
		char name[MAX_DATA];
};
struct DataBase {
		struct Address rows[MAX_ROWS];
};
struct Connetion {
		FILE* file;
		struct DataBase* db;
};
void die(const char* message)
{
		if (errno) {
				perror(message);
		} else {
				printf("ERROR:%s\n", message);
		}
		exit(-1);
}
void address_print(struct Address* addr)
{
		printf("%d %s %s\n", addr->id, addr->email, addr->name);
}
//fread(void*ptr,size_t size,size_t nnumb,FILE *stream)-> read thing from file and put thing the block of memory pointed by
//the ptr
//load -> it is saying that load data to the database from the file
void DataBase_load(struct Connetion* conn)
{
		//read date from file and put data to db(database)
		int rc = fread(conn->db, sizeof(struct DataBase), 1, conn->file);
		//check condition
		if (rc != 1) {
				die("Failed to load database");
		}
}
struct Connetion* DataBase_open(const char* filename, char mode)
{
		//here we create a new connection with db created
		struct Connetion* conn = malloc(sizeof(struct Connetion));
		if (!conn) {
				die("Memory error");
		}
		conn->db =malloc(sizeof(struct DataBase));
		//check the mode and do the relative thing
		if (mode == 'c') {
				conn->file = fopen(filename, "w");
		} else {
				conn->file = fopen(filename, "r+");

				if (conn->file) {
						DataBase_load(conn);
				}
		}
		if (!conn->file) {
				die("Failed to open the file");
		}
		return conn;
}
void Database_close(struct Connetion* conn)
{
		if (conn) {
				if (conn->file) {
						fclose(conn->file);
				}
				//why we here needn't free up the array,it is on the stack ?
				if (conn->db) {
						free(conn->db);
				}
		}
}
void DataBase_write(struct Connetion* conn)
{
		//rewind the cursor
		rewind(conn->file);
		int rc = fwrite(conn->db, sizeof(struct DataBase), 1, conn->file);
		if (rc != 1) {
				die("Failed to write the database");
		}
		rc = fflush(conn->file);
		if (rc == -1) {
				die("cannot flush the database");
		}
}
void DataBase_create(struct Connetion* conn)
{
		//cram up the addres to this db
		for (int i = 0; i < MAX_ROWS; i++) {
				struct Address addr = {.id = i, .set = 0 };
				conn->db->rows[i] = addr;
		}
}
//set the name and email according to the id
void DataBase_set(struct Connetion* conn, int id, char* name, char* email)
{
		if (!conn) {
				die("DataBase is not connected ");
		}
		struct Address* addr = &conn->db->rows[id];
		if (addr->set == 1) {
				die("Already set,Please delete it first");
		}
		addr->set=1;
		char* res = strncpy(addr->name, name, MAX_DATA);
		if (!res) {
				die("Name copyed failed");
		}
		res = strncpy(addr->email, email, MAX_DATA);
		if (!res) {
				die("Email copyed failed ");
		}
}
void DataBase_get(struct Connetion* conn, int id)
{
		struct Address* addr = &conn->db->rows[id];
		if (addr->set) {
				address_print(addr);
		} else {
				die("ID is not set");
		}
}
void DataBase_delete(struct Connetion* conn, int id)
{
		struct Address addr = {.id = id, .set = 0 };
		conn->db->rows[id] = addr;
}
void DataBase_list(struct Connetion* conn)
{
		struct DataBase* db = conn->db;
		for (int i = 0; i < MAX_ROWS; i++) {
				struct Address* cur = &db->rows[i];
				if (cur->set) {
						address_print(cur);
				}
		}
}
int main(int argc, char* argv[])
{
		if (argc < 3) {
				die("Usage :./ex17 <dbfile><action>[action params]");
		}
		//open the database
		char* filename = argv[1];
		char action = argv[2][0];
		struct Connetion* conn = DataBase_open(filename, action);
		//get the id and check the corner base
		int id = 0;
		if (argc > 3) {
				id = atoi(argv[3]);
		}
		if (id > MAX_ROWS) {
				die("There is not that many records");
		}
		//use a switch to choose the relative action
		switch (action) {
		case 'c':
				DataBase_create(conn);
				DataBase_write(conn);
				break;
		case 'g':
				if (argc != 4) {
						die("need a id ");
				}
				DataBase_get(conn, id);
				break;
		case 's':
				if (argc != 6) {
						die("need name and email to set ");
				}
				DataBase_set(conn, id, argv[4], argv[5]);
				DataBase_write(conn);
				break;
		case 'd':
				if (argc != 4) {
						die("need a id to delete");
				}
				DataBase_delete(conn, id);
				break;
		case 'l':
				DataBase_list(conn);
				break;
		default:
				die("Undefined behavior:only s=set,d=delete,l=list,g=get");
		}
		Database_close(conn);
		return 0;
}
