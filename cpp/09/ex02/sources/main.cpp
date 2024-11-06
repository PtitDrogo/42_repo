#include "PmergeMe.h"
#include <cstdlib>
#include <limits.h>
#include <ctime>
#include <iomanip>
#include <deque>

static const int *parseArgs(int argc, char **argv);

int main(int argc, char *argv[])
{
    PmergeMe<std::vector<int> > A;
    PmergeMe<std::deque<int> > B;

    const int *array_result = parseArgs(argc, argv);
    if (array_result == NULL)
    {    
        std::cerr << "Invalid Arguments" << std::endl;
        return (1);
    }

    A.fillContainer(array_result, argc - 1);
    B.fillContainer(array_result, argc - 1);
    std::cout << "Before : "; printContainer(A.getContainer());

    std::clock_t start = std::clock();
    A.epicSortWrapper();
    std::clock_t end = std::clock();
    double elapsed = (double(end - start) / CLOCKS_PER_SEC) * 1000000;
    
    start = std::clock();
    B.epicSortWrapper();
    end = std::clock();
    double elapsed2 = (double(end - start) / CLOCKS_PER_SEC) * 1000000;


    std::cout << "After : "; printContainer(B.getContainer());
    std::cout << "Time to process a range of " << A.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << elapsed << " us" << std::endl;
    std::cout << "Time to process a range of " << B.size() << " elements with std::deque : " << std::fixed << std::setprecision(3) << elapsed2 << " us" << std::endl;

    delete[] array_result;
    return 0;
}

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
        if (*argv[i] == '\0' || *end_check != '\0')
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
