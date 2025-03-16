#ifndef __USER_H__
#define __USER_H__

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <data/Connection.h>

class User : public cppcms::application {
 public:
  User(cppcms::service& srv, Connection& connection);

  void getUser();
  void getUserById(std::string id);

 private:
  Connection& connection;
};

#endif