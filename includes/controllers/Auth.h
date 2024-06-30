#ifndef __AUTH_H__
#define __AUTH_H__

#include <cppcms/application.h>
#include <cppcms/service.h>

class Auth : public cppcms::application
{
public:
    Auth(cppcms::service &srv);

    void login();
    void logout();

};

#endif