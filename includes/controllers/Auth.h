#ifndef __AUTH_H__
#define __AUTH_H__

#include <cppcms/application.h>
#include <cppcms/service.h>
#include <data/Connection.h>

class Auth : public cppcms::application {
 public:
  Auth(cppcms::service& srv, Connection& connection);

  void login();
  void logout();

 private:
  Connection& connection;
};

#endif