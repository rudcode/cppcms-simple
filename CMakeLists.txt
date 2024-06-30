cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME cppcms_simple)

project(${PROJECT_NAME})
add_definitions(-std=c++11)

find_library(LIB_BOOSTER booster)
find_library(LIB_CPPCMS cppcms)

# set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")

find_path(INC_BOOSTER booster/config.h)
find_path(INC_CPPCMS cppcms/config.h)

set(API_SRC
    main.cpp
    includes/controllers/User.cpp
    includes/controllers/Auth.cpp
)

include_directories(${INC_BOOSTER})
include_directories(${INC_CPPCMS})
include_directories(${CMAKE_SOURCE_DIR}/includes)
add_executable(${PROJECT_NAME} ${API_SRC})
target_link_libraries(${PROJECT_NAME}
    ${LIB_BOOSTER}
    ${LIB_CPPCMS}
)
