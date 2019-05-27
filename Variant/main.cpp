#include <iostream>

int main()
{

    int N[6] = {6, 4, 7, 5, 3, 2};
    const int b = 135;
   for(int i = 0; i < 6; i ++)
    {N[i] = b % N[i];
    std::cout << i + 1 << " Your variants " << N[i] << std::endl;
    }
    return 0;
}