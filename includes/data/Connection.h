#ifndef __CONNECTION__
#define __CONNECTION__

#include <cppcms/application.h>
#include <cppdb/frontend.h>

struct connectionStruct {
  std::string dbConnectionString;
};

class Connection {
 public:
  Connection(connectionStruct c);
  cppdb::session sql;

 private:
  void _database_initalization(std::string connectionString);
};

#endif