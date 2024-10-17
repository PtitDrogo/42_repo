#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer
{
private:
    Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);;
};


#endif