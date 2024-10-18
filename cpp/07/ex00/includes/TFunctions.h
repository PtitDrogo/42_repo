#ifndef TFUNCTIONS_H
# define TFUNCTIONS_H


template <typename T> void swap(T& x, T& y)
{
    T tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template <typename T> T max(const T x, const T y)
{
    if (x == y)
        return y;
    if (x > y)
        return x;
    return y;
}

template <typename T> T min(const T x, const T y)
{
    if (x == y)
        return y;
    if (x < y)
        return x;
    return y;
}

#endif


