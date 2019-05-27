#pragma once
#include "Vertex.h"
template<typename T>
class Tree
{
    private:
        Vertex *begin_ = nullptr;
    public:
        Tree();
        Tree(const T &item):begin_(new Vertex(item)){};
        Tree(const Tree &copy);
        void add(const T &item);
        T &find(const int position?);//?????????
        void find_and_erese(const int pos);//????
        void deleteNode(Vertex &node);
        ~Tree();
}

void Tree::deleteNode(Vertex *node)
{
    if(node->leftChild != nullptr)
        this->deleteNode(node->leftChild);
    if(node->rightChild != nullptr)
        this->deleteNode(node->rightChild);
    delete node;
}


Tree::~Tree()
{
    if(begin_ != nullptr)
        deleteNode(begin_);
}