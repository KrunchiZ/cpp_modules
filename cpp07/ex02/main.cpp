#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i;
        numbers[i] = value;
    }
    std::cout << "numbers: " << numbers << "\n\n";
    {
        std::cout << "Copying numbers to tmp.\n";    
        Array<int> tmp = numbers;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != numbers[i])
            {
                std::cerr << "tmp copy assignment failed.\n";
                return (1);
            }
        }
        std::cout << "tmp: " << tmp << "\n\n";
    }
    try
    {
        std::cerr << "Accessing number[-2]: ";
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cerr << "Accessing number[MAX_VAL]: ";
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}