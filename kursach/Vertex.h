#pragma once

template<typeneme T>
class BinaryNode
{
    public:
        T item;
        BinaryNode *leftChild = nullptr;
        BinaryNode *rightChild = nullptr;

        BinaryNode();
        BinaryNode(const T& item): this->item(item){};
}