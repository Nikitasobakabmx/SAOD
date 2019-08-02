#pragma once 
#include <ostream>
#include <iostream> 
#include "except.h"

template<typename T, typename Y>
class HeshTable
{
    private:
        const int _TableSize = 30;
        Y **_array = nullptr; 
        int _size = 0;//not null
        int hashAt(const T &key);
        int hashAd(const T &key);
        
    public:
        HeshTable();
        HeshTable(const T& key, const Y& item);
        HeshTable(const HeshTable<T, Y> &copy);
        Y& at(const T &key);
        Y& operator [](const T& key);
        bool rm(const T& key);
        bool rm();
        int size()
        {
            return _size;
        }
        void operator=(const HeshTable<T, Y> &copy);
        bool add(const T &key, const Y& item);
        friend std::ostream& operator<<(std::ostream &os, const HeshTable<T,Y> &item)
        {
            int count = 0;
            for(int i = 0; (i < item._TableSize) ; i++ || count++)
            {
                if(item._array[i] != nullptr)
                    os << *item._array[i] << "\t" <<  i << std::endl;
                if((count > item._size))
                    break;
            }
            return os;
        }
        ~HeshTable();
};
template<typename T, typename Y>
int HeshTable<T,Y>::hashAt(const T &key)
{
    int hesh = key % _TableSize;
    int tmp = hesh;
    int i = -1;
    while(_array[tmp] != nullptr && _array[tmp]->key() != key  || (_array[tmp] == nullptr && tmp < _TableSize))
    {
        ++i;
        tmp = (hesh + i * i) % _TableSize;
        if (i > _TableSize)
            throw except((char*)"Error index");
    }
    std::cout << "hashish" << std::endl;
    hesh = tmp; 
    return hesh;
}

template<typename T, typename Y>
int HeshTable<T,Y>::hashAd(const T &key)
{
    int hesh = key % _TableSize;
    int tmp = hesh;
    int i = -1;
    while(_array[tmp] != nullptr && _array[tmp]->key() != key)
    {
        i++;
        tmp = (hesh + i * i) % _TableSize;
    }
    hesh = tmp;
    return hesh;

}

template<typename T, typename Y>
HeshTable<T,Y>::HeshTable()
{
    _array = new Y*[_TableSize];
    for(int i = 0; i < _TableSize; i++)
        _array[i] = nullptr;
}

template<typename T, typename Y>
HeshTable<T,Y>::HeshTable(const T& key, const Y &item)
{
    _array = new Y*[_TableSize];
    for(int i = 0; i < _TableSize; i++)
        _array[i] = nullptr;
    add(key, item);
}

template<typename T, typename Y>
HeshTable<T,Y>::HeshTable(const HeshTable<T, Y> &copy)
{
    (*this) = copy;
}

template<typename T, typename Y>
Y& HeshTable<T,Y>::at(const T &key)
{
    int hesh = hashAt(key);
    return *_array[hesh];
}

template<typename T, typename Y>
Y& HeshTable<T,Y>::operator [](const T& key)
{
    return at(key);
}

template<typename T, typename Y>
bool HeshTable<T,Y>::rm(const T& key)
{
    int hesh = hashAt(key);
    delete _array[hesh];
    _array[hesh] = nullptr;
    --_size;
    return true;
}

template<typename T, typename Y>
bool HeshTable<T,Y>::rm()
{
    for(int i = 0; i < _TableSize; i++)
        delete [] _array[i];
    delete [] _array;
    for(int i = 0; i < _TableSize; i++)
        _array[i] = nullptr;
    _size = 0;
    return true;
}

template<typename T, typename Y>
void HeshTable<T,Y>::operator=(const HeshTable<T, Y> &copy)
{
    rm();
    for(int i = 0; i < _TableSize; i++)
        _array[i] = copy._array[i];
    _size = copy._size;
}

template<typename T, typename Y>
bool HeshTable<T,Y>::add(const T &key, const Y& item)
{
    int hesh = hashAd(key);
    if(_array[hesh] != nullptr)
        delete _array[hesh];
    else
        ++_size;
    _array[hesh] = new Y(item);
    return true;
}

template<typename T, typename Y>
HeshTable<T,Y>::~HeshTable()
{
    rm();
}