#include "Serializer.h"
#include "Data.h"
#include <iostream>



int main(void)
{
    Data importantdata;
    uintptr_t raw_ptr;

    std::cout << "The address of my data is : " << &importantdata << std::endl;
    raw_ptr = Serializer::serialize(&importantdata);
    std::cout << "My raw ptr is : " << raw_ptr << std::endl;

    Data *test = Serializer::deserialize(raw_ptr);
    
    std::cout << "My deserialized ptr is : " << test << std::endl;
    std::cout << "The address of my data is : " << &importantdata << std::endl;

    std::cout << test->getFood() << " is the amount of food I have, I can still use the pointer, neat !" << std::endl;
    std::cout << importantdata.getFood() << " is the amount of food I have, I can still use the data, neat !" << std::endl;
    return 0;
}
