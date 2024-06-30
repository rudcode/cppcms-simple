#include "Auth.h"
#include <cppcms/service.h>  
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/http_response.h>

// constructor
Auth::Auth(cppcms::service &srv) : cppcms::application(srv)
{
    dispatcher().assign("/login", &Auth::login, this);
    mapper().assign("/login");

    dispatcher().assign("/logout", &Auth::logout, this);
    mapper().assign("/logout");
}

// method login
void Auth::login()
{
    response().out() <<"login API";
}

// method logout
void Auth::logout()
{
    response().out() <<"Logout API ";
}
