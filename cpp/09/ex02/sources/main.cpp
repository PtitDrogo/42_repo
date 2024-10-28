#include "PmergeMe.h"
#include "PmergeMeList.h"
#include <cstdlib>
#include <limits.h>

static const int* parseArgs(int argc, char **argv);

int main(int argc, char *argv[])
{
    PmergeMe A;
    PmergeMeList B;


    const int *array_result = NULL; 
    try
    {
        array_result = parseArgs(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;  
        delete []array_result;
        return (1);
    }
    
    
    std::cout << array_result << std::endl;
    delete []array_result;
    //Your wonderful code here
    return 0;
}

//The parsing is independant of the implementation of each class so we will do it first.
//once I have an array of int, perhaps i can look into method to add it all at once to the
//containers ?


static const int* parseArgs(int argc, char **argv)
{
    if (argc <= 1)
        throw std::runtime_error("Too few arguments");
    int *array_result = new int[argc -1];
    double tmp;
    char    *end_check;

    for (int i = 1; i < argc; i++)
    {
        tmp = strtod(argv[i], &end_check);
        if (*end_check != '\0')
            throw std::runtime_error("Argument is not a number");
        if (tmp > INT_MAX || tmp < INT_MIN)
            throw std::runtime_error("Number doesn't fit in an Int");
        array_result[i - 1] = atoi(argv[i]);
        // std::cout << array_result[i - 1] << std::endl;
    }
    return(array_result);
}
