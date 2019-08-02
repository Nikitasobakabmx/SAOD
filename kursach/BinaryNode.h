#pragma once
#include <ostream>

template<typename T>
class BinaryNode
{
    public:
        T item;
        BinaryNode<T> *leftChild = nullptr;
        BinaryNode<T> *rightChild = nullptr;
        short high = 1;

        BinaryNode(){};
        BinaryNode(const T& item){this->item = item;};
        friend std::ostream& operator<<(std::ostream &os, const BinaryNode<T> *item)
        {
            if(item->leftChild != nullptr)
                os << item->leftChild;
            os << item->item << " ";
            if(item->rightChild != nullptr)
                os << item->rightChild;
            return os;
        }
};