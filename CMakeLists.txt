cmake_minimum_required(VERSION 3.0.0)
project(nino-sql VERSION 0.1.0)

include(CTest)

#FIXME: Create cmake files for sql-parser
execute_process(COMMAND "make" "mode=release" "static=yes"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/lib/sql-parser
    RESULT_VARIABLE SQL_PARSER_MAKE_RESULT)

add_library( sql-parser STATIC IMPORTED )
set_target_properties( sql-parser PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/sql-parser/libsqlparser.a )

add_executable(nino-sql main.cpp )

target_include_directories(nino-sql PRIVATE ${PROJECT_SOURCE_DIR}/lib/sql-parser/src)

find_package(Boost REQUIRED)
target_link_libraries(nino-sql PRIVATE Boost::boost)
target_link_libraries(nino-sql PRIVATE sql-parser)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
