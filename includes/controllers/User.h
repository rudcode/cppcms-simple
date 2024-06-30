#ifndef __USER_H__
#define __USER_H__

#include <cppcms/application.h>
#include <cppcms/service.h>

class User : public cppcms::application
{
public:
    User(cppcms::service &srv);

    void getUser();
    void getUserById(std::string id);

};

#endif