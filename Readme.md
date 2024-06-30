Research REST API with [CppCMS](http://cppcms.com/wikipp/en/page/main)

[Read more](http://cppcms.com/wikipp/en/page/cppcms_1x#Tutorials)

### How to run on Mac

- Make sure C++ already active (using XCode)
- Install cppcms `brew install cppcms`
- Install cmake `brew install cmake`
- Run `mkdir build`
- Run `cmake ..`
- Run `make`
- After executable `cppcms_simple` built, then you can run it by command `./cppcms_simple -c ../config.json`

### Available endpoints
At file includes/controllers/User.h
- `localhost:8080/users/1`
- `localhost:8080/users`

At file includes/controllers/Auth.h
- `localhost:8080/auth/login`
- `localhost:8080/auth/logout`