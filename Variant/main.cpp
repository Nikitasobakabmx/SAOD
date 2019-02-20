#include <iostream>

int main()
{
    int N,b;
    std::cout << "Insert variant" << std::endl;
    std::cin >> N;
    std::cout << "insert zachetku" << std::endl;
    std::cin >> b;
    N = b % N;
    std::cout << "Your variant " << N;
    return 0;
}