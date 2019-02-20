#include <stdio.h>
#include <cstdint>

class hui
{
    public:
    int a;
    int b;
};

int main()
{
    int64_t x = 0xFFFFFFFFF;
    hui you;
    *((int*)&you) = x;
    printf("a is %i\nb is %i", you.a, you.b);
    return 0;
}