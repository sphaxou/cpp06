#include <string>
#include <iostream>
#include "Convertor.hpp"


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (1);
    }
    try
    {
        Convertor a(av[1]);
        if (a.gettype() == 0)
            a.print_from_char();
        if (a.gettype() == 1)
            a.print_from_int();
        if (a.gettype() == 2)
            a.print_from_float();
        if (a.gettype() == 3)
            a.print_from_double();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}