Research REST API with [CppCMS](http://cppcms.com/wikipp/en/page/main)

[Read more](http://cppcms.com/wikipp/en/page/cppcms_1x#Tutorials)

### How to run on Mac

1. Make sure C++ already active (using XCode)
2. Install cppcms `brew install cppcms`
3. Install cmake `brew install cmake`
4. Run `mkdir build`
5. Run `cmake ..`
6. Run `make`
7. Run `cp ../db.db .` to copy the database example
8. After executable `cppcms_simple` built, then you can run it by command `./cppcms_simple -c ../config.json`

Note:

- CPPDB on the third-party submodules are built with MacOS M1 CPU, if you are run with other Arch maybe return error
- Make sure your database connection is correct on the file `config.json`

If those steps are not working due to cppdb dynamic libs, do this workaround to run the application.
1. Clone the repository https://github.com/saypulung/cppdb
2. In the terminal, go to the directory cppdb source code. For example **/Users/pulung/cppdb**
3. Run `mkdir build && cd build`
4. Run `cmake ..`
5. Run `make`
6. Edit CMakeList.txt file in the line 30. Replace `link_directories(${THIRD_PARTY_DIR}/cppdb/lib)` to `link_directories(/Users/pulung/cppdb/build)`. (Note: /Users/pulung/cppdb is the directory that you located the cppdb library
7. Go to `cppcms-simple` directory and rebuild the apps, once you've success to compile, it should be run propperly.

### How to run on Linux

1. Install cppcms http://cppcms.com/wikipp/en/page/cppcms_1x_build
2. Install cmake
3. Run `mkdir build`
4. Run `cmake ..`
5. Run `make -j$(( $(nproc)-1))`
6. Run `cp ../db.db .` to copy the database example
7. After executable `cppcms_simple` built, then you can run it by command `./cppcms_simple -c ../config.json`

### How to run on Windows

- TODO LIST

### Debugging

- Run the project first by `How to run on Mac` section (if you are using Mac OS M1) and replace command at step 5 with `cmake -DCMAKE_BUILD_TYPE=Debug ..`
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
Request body:
```
{
  "User": {
    "LoginId": "admin",
    "Password": "admin1234"
  }
}
```
- `localhost:8080/auth/logout`
