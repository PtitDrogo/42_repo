#include <iostream>
#include "Array.h"
#include "iter.h"
#include "Data.h"

#define MAX_VAL 750


#define MAGENTA "\033[1;35m"
#define END     "\033[0m"

int main(int, char**)
{
    //subject main test;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;


    //My test;
    std::cout << MAGENTA << "TIME FOR MY OWN TESTS" << END << std::endl;
    Array<char> new_numbers(10);

    std::cout << "Using some Iter function from previous exercises to modify the content of my array then print it" << std::endl;
    
    iter(new_numbers.getFirstElem(), new_numbers.size(), &alphabet_power);
    iter(new_numbers.getFirstElem(), new_numbers.size(), &printl);

    std::cout << "Testing assignement between two arrays" << std::endl;

    Array<char> new_numbers2(1); //Its too small of an array !
    new_numbers2 = new_numbers;
    iter(new_numbers2.getFirstElem(), new_numbers2.size(), &printl);

    //using a custom class from a previous module;
    Array<Data> custom_class_array(10);
    std::cout << MAGENTA << "I have " << custom_class_array.size() << " elements in my custom class array, let's print them" << END << std::endl;
    iter(custom_class_array.getFirstElem(), custom_class_array.size(), &printl);

    return 0;
}
