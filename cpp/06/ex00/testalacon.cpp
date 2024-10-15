#include <iostream>

int main(int argc, char const *argv[])
{
    float test;
    char test2;
    test = 42000000.5;

    test2 = static_cast<char>(test);
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    std::cout << static_cast<int>(test2) << std::endl;
    // test = .5;
    return 0;
}
