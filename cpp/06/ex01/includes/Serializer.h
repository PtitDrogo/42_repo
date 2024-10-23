#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>
#include <stdint.h>
#include "Data.h"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);;
};


#endif