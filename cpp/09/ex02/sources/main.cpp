#include "PmergeMe.h"
#include "PmergeMeList.h"
#include <cstdlib>
#include <limits.h>
#include <ctime>

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
    std::clock_t start = std::clock();
    A.epicSortWrapper();
    std::clock_t end = std::clock();
    double elapsed = (end - start) / (double)(CLOCKS_PER_SEC * 100);
    std::cout << "Time to process a range of undefined" << " elements with std::vector: " << elapsed << " us" << std::endl;
    delete[] array_result;
    return 0;
}

/*
 std::clock_t start = std::clock();
        std::cout << "before: ";
        gamberge.printArray(array);
        gamberge.algorithm(array, 0, array.size() - 1);
        std::cout << "after: ";
        gamberge.printArray(array);
        std::clock_t end = std::clock();
        double elapsed = double(end - start);
        std::cout << "Time to process a range of " << array.size() << " elements with std::vector: " << elapsed << " us" << std::endl;
        
        start = std::clock();
        gamberge1.algorithm(array1, 0, array.size() - 1);
        end = std::clock();
        elapsed = double(end - start);
        std::cout << "Time to process a range of " << array1.size() << " elements with std::deque: " << elapsed << " us" << std::endl;*/

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
