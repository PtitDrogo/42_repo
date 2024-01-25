#include <unistd.h>

unsigned char reversebits(unsigned char octet)
{
    unsigned char r;
    r = 0;
    int byte_len = 8;
    while (byte_len > 0)
    {
        r = (r << 1) |(octet & 1);
        octet >>= 1;
        byte_len--;
    }
    return (r);
}

void printbits(unsigned char octet)
{
    unsigned char reference = 0b10000000;

    while (reference)
    {
        if (reference & octet)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        reference >>= 1;
    }
    write(1, "\n", 1);
}
unsigned char   swapbits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

int main(void)
{
    unsigned char test = 121;
    printbits(test);
    printbits(reversebits(test));
    printbits(swapbits(test));
}