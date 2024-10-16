#include <iostream>

int main(int argc, char const *argv[])
{
    float test;
    float test2;
    test = 420000.5f;

    test2 = test / 1;
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    // std::cout << static_cast<int>(test2) << std::endl;
    // test = .5;
    return 0;
}
