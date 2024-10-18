#include "iter.h"
#include <iostream>

#define MAGENTA "\033[1;35m"
#define END     "\033[0m"



int main()
{
    int array[5] = {1, 2, 3, 4, 5};

    std::cout << MAGENTA << "Using my template on int array" << END << std::endl; 
    iter(array, 5, &printl);
    iter(array, 5, &increment);
    std::cout << MAGENTA << "after increment, array is now" << END << std::endl;
    iter(array, 5, &printl);
    
    char array2[10] = {'a', 'b', 'c', 'A', 'B', 'C'};
    std::cout << MAGENTA << "Using my template on char array" << END << std::endl; 
    iter(array2, 5, &printl);
    iter(array2, 5, &incrementchar);
    std::cout << MAGENTA << "after increment, array2 is now" << END << std::endl;
    iter(array2, 5, &printl);

    return 0;
}


