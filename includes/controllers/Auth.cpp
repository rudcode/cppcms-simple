#include "Auth.h"
#include <cppcms/service.h>  
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppdb/frontend.h>
#include <booster/locale/conversion.h>
#include <cppcms/http_request.h>

// constructor
Auth::Auth(cppcms::service &srv) : Master(srv)
{
    dispatcher().assign("/login", &Auth::login, this);
    mapper().assign("/login");

    dispatcher().assign("/logout", &Auth::logout, this);
    mapper().assign("/logout");
}

// method login
void Auth::login()
{
    std::string req_method = request().request_method();
    if (req_method.compare("POST") != 0) {
        response().out() << "Method does not allowed";
        return;
    }
    cppdb::result res = sql() << "SELECT * FROM users WHERE usrsLoginId = ?" << request().post("login_id");

    if(res.next()) {
        int colFirstName = res.find_column("usrsFirstName");
        std::string firstName;
        res.fetch(colFirstName, firstName);
        std::cout << "First name : " << firstName << std::endl;
    }
    response().out() <<"User not found";
}

// method logout
void Auth::logout()
{
    response().out() <<"Logout API ";
}
