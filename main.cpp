#include <iostream>
#include <boost/algorithm/string.hpp>

#include <SQLParser.h>
#include <SQLParserResult.h>
#include <sql/CreateStatement.h>

int main(int argc, char **argv)
{
    std::cout << "Please enter sql command. exit to leave the programm" << std::endl;

    std::string sqlCommand;
    hsql::SQLParserResult sqlParserResult;

    while (true)
    {
        std::getline(std::cin, sqlCommand);
        // boost::to_lower(sqlCommand);

        std::string operation;
        if (sqlCommand == "exit")
        {
            break;
        }

        const auto valid = hsql::SQLParser::parse(sqlCommand, &sqlParserResult);
        if (!valid || !sqlParserResult.isValid())
        {
            std::cout << sqlCommand << std::endl;
            std::cout << sqlParserResult.errorMsg() << std::endl;
            continue;
        }

        const auto &statements = sqlParserResult.getStatements();

        for (const auto *statement : statements)
        {
            if (statement->isType(hsql::kStmtCreate))
            {
                const hsql::CreateStatement *create = static_cast<const hsql::CreateStatement *>(statement);
                std::cout << create->tableName << std::endl;
            }
        }
    }

    return 0;
}
