#include <stdlib.h>
#include <stdio.h>

int inspect_bits(unsigned int number)
{
    for (int i = 0; i < 32; ++i)
    {
        int consecutive = 0;
        if (number & (1 << i))  // if bit i is set
        {
            printf("Bits match");
            consecutive++;
        }
        else
        {
            printf("Bits dont match");
            consecutive = 0;
        }
        if (consecutive > 1) {
            printf("Two consecutive");
            return 1;
        }
    }
    return 0;
}

#ifndef RunTests
int main ()
{
    printf("%d", inspect_bits(13));
}
#endif