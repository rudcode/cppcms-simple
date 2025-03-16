
#include <controllers/Auth.h>
#include <controllers/User.h>
#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/http_request.h>
#include <cppcms/http_response.h>
#include <cppcms/service.h>
#include <cppcms/url_mapper.h>
#include <data/Connection.h>

#include <iostream>
#include <map>

class hello : public cppcms::application {
 public:
  hello(cppcms::service &srv) : cppcms::application(srv) {
    connection = new Connection((connectionStruct){
        .dbConnectionString =
            settings().get<std::string>("cppcms_simple.connection_string")});

    attach(new User(srv, *connection), "users", "/users/{1}", "/users(/(.*))?",
           1);
    attach(new Auth(srv, *connection), "auth", "/auth/{1}", "/auth(/(.*))?", 1);
    mapper().root("/");
  }

 private:
  Connection *connection;
};

int main(int argc, char **argv) {
  try {
    cppcms::service srv(argc, argv);
    srv.applications_pool().mount(cppcms::applications_factory<hello>());
    srv.run();
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }
}
