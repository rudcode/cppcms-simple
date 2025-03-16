#include "Master.h"

#include <cppcms/json.h>
#include <cppdb/frontend.h>

namespace database {

Master::Master(cppcms::service &srv) : cppcms::application(srv) {
  conn_str_ = settings().get<std::string>("cppcms_simple.connection_string");
  sql_.reset(new cppdb::session(conn_str_));
}

Master::~Master() {}

cppdb::session &Master::sql() {
  if (!sql_->is_open()) sql_->open(conn_str_);
  return *sql_;
}

}  // namespace database