#include "easyfind.h"
#include <vector>
#include <list>

#define MAGENTA "\033[1;35m"
#define END     "\033[0m"


template <typename T>
static void check_iterator(T& container, typename T::iterator result)
{
    if (result == container.end())
        std::cout << "Couldn't find the number" << std::endl;
    else
        std::cout << "Number " << *result << " was found at index " << std::distance(container.begin(), result) << std::endl;
}

int main()
{
    std::cout << MAGENTA << "Let's test with a Vector of Int" << END << std::endl;
    std::vector<int> vector_container;
    for (int i = 0; i < 10; i++)
    {
        vector_container.push_back(i * 10);
    }
    check_iterator(vector_container, easyFind(vector_container, 60));
    check_iterator(vector_container, easyFind(vector_container, 9999));


    std::cout << MAGENTA << "Let's test with a linked list of Int" << END << std::endl;
    std::list<int> list_container;
    for (int i = 0; i < 10; i++)
    {
        list_container.push_back(i * 10);
    }
    check_iterator(list_container, easyFind(list_container, 60));
    check_iterator(list_container, easyFind(list_container, 9999));

    return 0;
}


