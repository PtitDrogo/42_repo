#include "PmergeMe.h"
#include "PmergeMeList.h"
#include <cstdlib>
#include <limits.h>

static const int *parseArgs(int argc, char **argv);

int main(int argc, char *argv[])
{
    PmergeMe A;
    PmergeMeList B;

    const int *array_result = parseArgs(argc, argv);
    if (array_result == NULL)
    {    
        std::cerr << "Invalid Arguments" << std::endl;
        return (1);
    }
    // std::cout << array_result << std::endl;
    
    A.fillVector(array_result, argc - 1);
    A.epicSortWrapper();
    delete[] array_result;
    return 0;
}

// The parsing is independant of the implementation of each class so we will do it first.
// once I have an array of int, perhaps i can look into method to add it all at once to the
// containers ?

static const int *parseArgs(int argc, char **argv)
{
    if (argc <= 1)
        return NULL;
    int *array_result = new int[argc - 1];
    double tmp;
    char *end_check;

    for (int i = 1; i < argc; i++)
    {
        tmp = strtod(argv[i], &end_check);
        if (*end_check != '\0')
        {    
            delete[] array_result;
            return NULL;
        }
        if (tmp > INT_MAX || tmp < 0)
        {    
            delete[] array_result;
            return NULL;
        }
        array_result[i - 1] = atoi(argv[i]);
    }
    return (array_result);
}
