Research REST API with [CppCMS](http://cppcms.com/wikipp/en/page/main)

[Read more](http://cppcms.com/wikipp/en/page/cppcms_1x#Tutorials)

### How to run on Mac

1. Make sure C++ already active (using XCode)
2. Install cppcms `brew install cppcms`
3. Install cmake `brew install cmake`
4. Run `mkdir build`
5. Run `cmake ..`
6. Run `make`
7. After executable `cppcms_simple` built, then you can run it by command `./cppcms_simple -c ../config.json`

Note:

- CPPDB on the third-party submodules are built with MacOS M1 CPU, if you are run with other Arch maybe return error
- Make sure your database connection is correct on the file `config.json`

### How to run on Linux

- TODO LIST

### How to run on Windows

- TODO LIST

### Debugging

- Replace command at step 5 with `cmake -DCMAKE_BUILD_TYPE=Debug ..`
- Set Breakpoint which you want to debug like this (User.cpp:24)
![Set breakpoint](/screenshots/breakpoint.png)
- On the VSCode, you can run by click Play Button at **Run and Debug** section
- Then, after you are ran the application and accessing the URL target method, program will paused at the breakpoint
![Paused](/screenshots/paused.png)

### Available endpoints
At file includes/controllers/User.h
- `localhost:8080/users/1`
- `localhost:8080/users`

At file includes/controllers/Auth.h
- `localhost:8080/auth/login`
- `localhost:8080/auth/logout`
