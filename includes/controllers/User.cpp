#include "User.h"

#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

#ifndef PICOJSON_USE_INT64
#define PICOJSON_USE_INT64
#endif
#include <picojson.h>

// constructor
User::User(cppcms::service& srv, Connection& connection)
    : cppcms::application(srv), connection(connection) {
  dispatcher().assign("", &User::getUser, this);
  mapper().assign("");

  dispatcher().assign("/(\\d+)", &User::getUserById, this, 1);
  mapper().assign("/{1}");
}

void User::getUser() {
  try {
    cppdb::result res =
        connection.sql
        << "SELECT usrsId, usrsFirstName, usrsLastName, "
           "usrsCreatedTime, usrsUpdatedTime, usrsIsBlocked FROM users";

    picojson::array users;

    int usrsId;
    std::string usrsFirstName, usrsLastName, usrsCreatedTime, usrsUpdatedTime;
    int usrsIsBlocked;
    picojson::object user;
    while (res.next()) {
      res >> usrsId >> usrsFirstName >> usrsLastName >> usrsCreatedTime >>
          usrsUpdatedTime >> usrsIsBlocked;

      user["usrsId"] = picojson::value((int64_t)usrsId);
      user["usrsFirstName"] = picojson::value(usrsFirstName);
      user["usrsLastName"] = picojson::value(usrsLastName);
      user["usrsCreatedTime"] = picojson::value(usrsCreatedTime);
      user["usrsUpdatedTime"] = picojson::value(usrsUpdatedTime);
      user["usrsIsBlocked"] = picojson::value((bool)usrsIsBlocked);
      users.push_back(picojson::value(user));
    }

    response().content_type("application/json");
    response().out() << picojson::value(users).serialize();
  } catch (std::exception const& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
}

void User::getUserById(std::string id) {
  try {
    cppdb::result res = connection.sql
                        << "SELECT usrsId, usrsFirstName, usrsLastName, "
                           "usrsCreatedTime, usrsUpdatedTime, usrsIsBlocked "
                           "FROM users WHERE usrsId = ?"
                        << id;

    if (res.next()) {
      int usrsId;
      std::string usrsFirstName, usrsLastName, usrsCreatedTime, usrsUpdatedTime;
      int usrsIsBlocked;
      res >> usrsId >> usrsFirstName >> usrsLastName >> usrsCreatedTime >>
          usrsUpdatedTime >> usrsIsBlocked;

      picojson::object user;
      user["usrsId"] = picojson::value((int64_t)usrsId);
      user["usrsFirstName"] = picojson::value(usrsFirstName);
      user["usrsLastName"] = picojson::value(usrsLastName);
      user["usrsCreatedTime"] = picojson::value(usrsCreatedTime);
      user["usrsUpdatedTime"] = picojson::value(usrsUpdatedTime);
      user["usrsIsBlocked"] = picojson::value((bool)usrsIsBlocked);

      response().content_type("application/json");
      response().out() << picojson::value(user).serialize();
      return;
    }

    response().status(404);
    response().out() << "User not found";
  } catch (std::exception const& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
}
