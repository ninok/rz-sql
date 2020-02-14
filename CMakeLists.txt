cmake_minimum_required(VERSION 3.0.0)
project(nino-sql VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(nino-sql main.cpp)

find_package(Boost REQUIRED)
target_link_libraries(nino-sql PRIVATE Boost::boost)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
