#include "Auth.h"
#include <cppcms/service.h>  
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>
#include <cppdb/frontend.h>

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
    cppdb::result res = sql() << "SELECT id,n,f,t,name FROM test";

    while(res.next()) {
        double f=-1;
        int id,k;
        std::tm atime;
        std::string name;
        res >> id >> k >> f >> atime >> name;
        std::cout <<id << ' '<<k <<' '<<f<<' '<<name<<' '<<asctime(&atime)<< std::endl;
    }
    response().out() <<"login API";
}

// method logout
void Auth::logout()
{
    response().out() <<"Logout API ";
}
