#include <iostream>
#include <ctime>
#include <cstdlib>

void upToModule(int *array, const int &size);
void makeArray(int *array, const int &size);
void show(int *array, const int &size);
int countZero(int *array, const int &size);

int main()
{
    std::cout << "Insert amount of array" << std::endl;
    int amount = 0;
    std::cin >> amount;
    int array[amount];
    makeArray(array, amount);
    show(array, amount);
    std::cout << "\n0 - make all var up to 0\n1 - count var eaqel 0\n";
    bool tmp;
    std::cin >> tmp;
    if(tmp)
        std::cout << "0 in array = " << countZero(array, amount) << std::endl;
    else
    {
        upToModule(array, amount);   
        show(array, amount); 
    }
    return 0;
}

void upToModule(int *array, const int &size)//O(n)
{
    for(int i = 0; i < size; i++)
        if(array[i] < 0)
            array[i] *= -1;
}

void show(int *array, const int &size)//O(n)
{
    std::cout<< "\tArray\n";
    for(int i = 0; i < size; i++)
        std::cout << array[i] << "  ";
}

void makeArray(int *array, const int &size)//O(n)
{
    std::srand(std::time(nullptr));
    for(int i = 0; i < size; i++)
        array[i] = std::rand() % (size / 2) +(-(size / 2 - 1)); 
}

int countZero(int *array, const int &size)//O(n)
{
    int count = 0;
    for(int i = 0; i < size; i++)
        if(array[i] == 0)
            count++;
    return count;
}