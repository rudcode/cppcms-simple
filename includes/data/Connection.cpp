#include "Connection.h"

#include <cppcms/json.h>

Connection::Connection(connectionStruct c) {
  _database_initalization(c.dbConnectionString);
}

void Connection::_database_initalization(std::string connectionString) {
  sql.open(connectionString);
}