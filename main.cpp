#include <iostream>
#include <boost/algorithm/string.hpp>

int main(int argc, char **argv)
{
    std::cout << "Please enter sql command. exit to leave the programm" << std::endl;

    std::string command;

    while (true)
    {
        std::cin >> command;
        boost::to_lower(command);
        std::stringstream commandstr(command);

        std::string operation;
        if (command == "exit")
        {
            break;
        }
        else if (command == "create")
        {
        }
    }

    return 0;
}
