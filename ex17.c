#include <stdio.h> // FILE rewind?
#include <errno.h> // errno
#include <stdlib.h> // exit
#include <string.h> //strncpy

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};

void Database_close(struct Connection *conn);

void die(const char *message, struct Connection *conn) {
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  if(conn) Database_close(conn);

  exit(1);
}

void Address_print(struct Address *addr) {
  printf("%d %s %s\n",
      addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {

  // now we want to read:
  //  1 Database
  //  db->num_rows * Address
  //  db->num_rows * db->max_data_size * 2 (1 for name, another for email)
  //

  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to load databse.", conn);
}

struct Connection *Database_open(const char *filename, char mode) {
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn) die("Memory error", conn);

  conn->db = malloc(sizeof(struct Database));
  if(!conn->db) die("Memory error", conn);

  // got to malloc the rest of the required memory (so that file can be loaded)
  // this means:
  //  db->rows
  //  for each row
  //    address->name
  //    address->email
  //

  if(mode == 'c') {
    conn->file = fopen(filename, "w");
  } else {
    conn->file = fopen(filename, "r+");

    if(conn->file) {
      Database_load(conn);
    }
  }

  if(!conn->file) die("Failed to open the file", conn);

  return conn;
}

void Database_close(struct Connection *conn) {
  if(conn) {
    if(conn->file) fclose(conn->file);
    if(conn->db) free(conn->db);

    // also have to free
    //  each addresses name and email
    //  each address

    free(conn);
  }
}

void Database_write(struct Connection *conn) {
  rewind(conn->file);

  // same size as in open

  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to write to database", conn);

  rc = fflush(conn->file);
  if(rc == -1) die("Cannot flush database", conn);
}

void Database_create(struct Connection *conn) {
  int i = 0;

  // I think everything is now built and connected, should just be able to substitute MAX_ROWS

  for(i=0; i<MAX_ROWS; i++) {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = 0};
    // then just assign it
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
  struct Address *addr = &conn->db->rows[id];
  if(addr->set) die("Already set, delete it first", conn);

  addr->set = 1;
  // WARNING: bug, read "How to Break It" and fix this
  char *res = strncpy(addr->name, name, MAX_DATA);
  // if name or email > MAX_DATA, terminating '\0' gets truncated
  //  this results in data loss
  //
  //  Soln still results in data loss, but not in overflow.
  //  To prevent dataloss, we could check before, and die if name or email length > MAX_DATA
  //

  addr->name[MAX_DATA-1] = '\0';
  if(!res) die("Name copy failed", conn);

  res = strncpy(addr->email, email, MAX_DATA);
  addr->email[MAX_DATA-1] = '\0';
  if(!res) die("Email copy failed", conn);
}

void Database_get(struct Connection *conn, int id) {
  struct Address *addr = &conn->db->rows[id];

  if(addr->set){
    Address_print(addr);
  } else {
    die("ID is not set", conn);
  }
}

void Database_delete(struct Connection *conn, int id) {
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
  int i = 0;
  struct Database *db = conn->db;

  // change ths for db->max_rows
  for(i=0; i < MAX_ROWS; i++) {
    struct Address *cur = &db->rows[i];

    if(cur->set) Address_print(cur);
  }
}


int main(int argc, char *argv[]) {
  if(argc < 5) die("USAGE: ex17 <dbfile> <max_rows> <max_data> <action> [action params]", NULL);

  char *filename = argv[1];
  int max_rows = atoi(argv[2]);
  int max_data = atoi(argv[3]);
  char action = argv[4][0];
  //printf("max_rows: %d, max_data: %d, action: %c\n", max_rows, max_data, action);

  // this will have to also take max_rows and max_data
  struct Connection *conn = Database_open(filename, action);
  int id =0;

  if(argc > 5) id = atoi(argv[5]);
  if(id > MAX_ROWS) die("There are not that many records", conn);

  switch(action) {
    case 'c':
      Database_create(conn);
      Database_write(conn);
      break;

    case 'g':
      if(argc !=6) die("Need an ID to get", conn);

      Database_get(conn, id);
      break;

    case 's':
      if(argc != 8) die("Need ID, name, email to set", conn);

      char *name = argv[6];
      char *email = argv[7];
      Database_set(conn, id, name, email);
      Database_write(conn);
      break;

    case 'd':
      if(argc != 6) die("Need an ID to delete", conn);

      Database_delete(conn, id);
      Database_write(conn);
      break;

    case 'l':
      Database_list(conn);
      break;

    default:
      die("Invalid action (only c - create, g - get, s - set, d - delete, l - list)", conn);
      
  }

  Database_close(conn);

  return 0;
}
