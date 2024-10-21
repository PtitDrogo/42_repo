#include "easyfind.h"
#include <vector>

int main()
{
    std::vector<int> vector_container;
    
    for (int i = 0; i < 10; i++)
    {
        vector_container.push_back(i * 10);
    }
    try 
    {
        easyFind(vector_container, 30);
    }
    catch (const std::exception& e)
    {
        e.what();
    }
    //Your wonderful code here
    return 0;
}
