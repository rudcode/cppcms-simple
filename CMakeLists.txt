cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME cppcms_simple)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

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
    includes/data/Connection.cpp
)

include_directories(${INC_BOOSTER})
include_directories(${INC_CPPCMS})
include_directories(${CMAKE_SOURCE_DIR}/includes)
include_directories(${THIRD_PARTY_DIR}/cppdb/include)
include_directories(${THIRD_PARTY_DIR}/picojson)
link_directories(${THIRD_PARTY_DIR}/cppdb/lib)
add_executable(${PROJECT_NAME} ${API_SRC})
target_link_libraries(${PROJECT_NAME}
    ${LIB_BOOSTER}
    ${LIB_CPPCMS}
    cppdb
)
