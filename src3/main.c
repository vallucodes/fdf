#include <stdio.h>
#include <stdint.h>

int check_endianness()
{
    // Create a 2-byte integer with a known value
    unsigned short int num = 0x1;

    // Cast the address of num to a pointer to a byte (char *)
    unsigned char *byte_ptr = (unsigned char*)&num;

    // Check the first byte
    if (*byte_ptr == 0x1)
        return 1;
}

int main()
{
    int a = check_endianness();
    printf("%i\n", a);
}
