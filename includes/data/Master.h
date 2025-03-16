#ifndef __MASTER_H__
#define __MASTER_H__

#include <cppcms/application.h>

namespace cppdb {
class session;
}

namespace database {
class Master : public cppcms::application {
 public:
  Master(cppcms::service& srv);
  ~Master();

 protected:
  cppdb::session& sql();

 private:
  std::auto_ptr<cppdb::session> sql_;
  std::string conn_str_;
};
}  // namespace database
#endif