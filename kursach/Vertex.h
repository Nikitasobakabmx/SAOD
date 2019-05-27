#pragma once

template<typeneme T>
class Vertex
{
    public:
        T item;
        Vertex *leftChild = nullptr;
        Vertex *rightChild = nullptr;

        Vertex();
        Vertex(const T& item): this->item(item){};
}