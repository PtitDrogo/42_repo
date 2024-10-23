#ifndef ITHER_H
# define ITHER_H

#include <string>
#include <iostream>

template <typename T> void iter(T *array_address, size_t array_len, void (*f)(T&))
{
    for (size_t i = 0; i < array_len; i++)
    {
        f(array_address[i]);
    }
    return ;
}

template <typename T> void printl(T toprint)
{
    std::cout << toprint << std::endl;
}

template <typename T> void alphabet_power(T& c)
{
    static char tmp = 'a';
    c = tmp;
    tmp++;
    if (tmp > 'z')
        tmp = 'a';
}
void increment(int &i) { i++;}
void incrementchar(char &i){ i++;}

#endif