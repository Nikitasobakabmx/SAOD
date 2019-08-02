#pragma once
#include "BinaryNode.h"
#include "except.h"
#include <ostream>
#include <iostream>
template<typename T>
class Tree
{
    private:
        BinaryNode<T> *begin_ = nullptr;
        int size_ = 0;
        void deleteNode(BinaryNode<T> *node);
        T moveUp(BinaryNode<T> *node);
        short height(BinaryNode<T> *node) const noexcept;
        short bfactor(BinaryNode<T> *node) const noexcept;
        void fixHeight(BinaryNode<T> *node);
        BinaryNode<T>* rightRotate( BinaryNode<T> *node) noexcept;
        BinaryNode<T>* leftRotate( BinaryNode<T> *node) noexcept;
        BinaryNode<T>* balance(BinaryNode<T>* node);
        BinaryNode<T>* add(BinaryNode<T> *node, const T &item);

    public:
        Tree(){};//
        Tree(const T &item):begin_(new BinaryNode<T>(item)), size_(1){};//
        Tree(const Tree &copy);
        void add(const T &item);
        //T &at(const int position);
        //T &at(const int *position);
        //T find_and_erese(const int pos);//????
        //T find_and_erese(const T item);//????
        //T& operator[](int position)
        friend std::ostream& operator<<(std::ostream &os,const Tree &item)
        {
            if(item.begin_ == nullptr)
                throw except((char*)"Tree is empty!");
            os << item.begin_ << std::endl;
            //item.fixHeight(item.begin_);
            std::cout << item.bfactor(item.begin_);
            std::cout << item.height(item.begin_);
            return os;
        }
        ~Tree();
};
//setting function // hiding
template<typename T>
void Tree<T>::deleteNode(BinaryNode<T> *node)
{
    //backwards
    if(node->leftChild != nullptr)
        this->deleteNode(node->leftChild);
    if(node->rightChild != nullptr)
        this->deleteNode(node->rightChild);
    delete node;
    --size_;
}

template <typename T>
T Tree<T>::moveUp(BinaryNode<T> *node)
{
    while(node->rightChild != nullptr)
        node = node->rightChild;
    T tmp = node->item;
    if(node->leftChild != nullptr)
        node->item = moveUp(node->leftChild);
    else
    {
        delete node;
        node = nullptr;
        --size_;
    }
    return tmp;
}

template<typename T>
short Tree<T>::height(BinaryNode<T> *node) const noexcept
{
    return (node != nullptr)?node->high:0;
}

template<typename T>
short Tree<T>::bfactor(BinaryNode<T> *node) const noexcept
{
    return height(node->rightChild) - this->height(node->leftChild);
}

template<typename T>
void Tree<T>::fixHeight(BinaryNode<T> *node)
{
    short left = height(node->leftChild);
    short right = height(node->rightChild);
    node->high = (left>right? left: right) + 1;
}

template<typename T>
BinaryNode<T>* Tree<T>::rightRotate( BinaryNode<T> *node) noexcept
{
    std::cout << "right";
    BinaryNode<T> *tmp = node->leftChild;
    node->leftChild = tmp->rightChild;
    tmp->rightChild = node;
    this->fixHeight(node);
    this->fixHeight(tmp);
    return tmp;
}

template<typename T>
BinaryNode<T>* Tree<T>::leftRotate(BinaryNode<T> *node) noexcept
{
    std::cout << "left";
    BinaryNode<T> *tmp = node->rightChild;
    node->rightChild = tmp->leftChild;
    tmp->leftChild = node;
    this->fixHeight(node);
    this->fixHeight(tmp);
    return tmp;
}

template<typename T>
BinaryNode<T>* Tree<T>::balance(BinaryNode<T>* node)
{
    fixHeight(node);
    if(bfactor(node) == 2)
    {
        if(bfactor(node->rightChild) < 0)
            node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }
    if(bfactor(node) == -2)
    {
        if(bfactor(node->leftChild) > 0)
            node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }
    return node;
}

// template <typename T>
// T& Tree::at(const int position)
// {
//     if(begin_ == nullptr)
//         throw except((char*)"Tree is empty!");
//     T item(position);    
//     BinaryNode<T> *tmp = begin_;
//     while(true)
//     {
//         if(item < tmp->item)
//         {
//             if(tmp->leftChild == nullptr)
//                 throw except((char*)"Hasn't this value!");
//             tmp = tmp->leftChild;
//         }
//         if(item > tmp->item)
//         {
//             if(tmp->rightChild == nullptr)
//                 throw except((char*)"Hasn't this value!");
//             tmp = tmp->rightChild;
//         }
//         if(item == tmp->item)
//             return (*tmp);
//     }
// }




// template <typename T>
// T Tree::find_and_erese(const int pos)
// {
//     T item(pos);
//     return this->find_and_erese(item);
// }

// template <typename T>
// T Tree::find_and_erese(const T item)
// {
//     if(begin_ == nullptr)
//         throw except((char*)"Tree is empty!");
//     BinaryNode<T> *tmp = begin_;
//     while(true)
//     {
//         if(item < tmp->item)
//         {
//             if(tmp->leftChild == nullptr)
//                 throw except((char*)"Hasn't this value!");
//             tmp = tmp->leftChild;
//         }
//         if(item > tmp->item)
//         {
//             if(tmp->rightChild == nullptr)
//                 throw except((char*)"Hasn't this value!");
//             tmp = tmp->rightChild;
//         }
//         if(item == tmp->item)
//             return moveUp(tmp);
//     }
// }


template <typename T>
void Tree<T>::add(const T &item)
{
    // if(begin_ == nullptr)
    // {
    //     begin_ = new BinaryNode<T>(item);
    //     ++size_;
    //     return;
    // }
    // BinaryNode<T> *tmp = begin_;
    // while(true)
    // {
    //     if(item < tmp->item)
    //     {
    //         if(tmp->leftChild == nullptr)
    //         {
    //             tmp->leftChild = new BinaryNode<T>(item);
    //             //tmp = tmp->leftChild;
    //             size_++;
    //             break;
    //         }
    //         else
    //             tmp = tmp->leftChild;
    //     }
    //     else{
    //         if(tmp->rightChild == nullptr)
    //         {
    //             tmp->rightChild = new BinaryNode<T>(item);
    //             //tmp = tmp->rightChild;
    //             ++size_;
    //             break;
    //         }
    //         else
    //             tmp = tmp->rightChild;
    //     }
    // }
    // balance(tmp);
    begin_ = add(begin_, item);
}

template<typename T>
BinaryNode<T>* Tree<T>::add(BinaryNode<T> *node, const T &item)
{
    if(node == nullptr)
        return new BinaryNode<T>(item);
    if(item < node->item)
        node->leftChild = add(node->leftChild, item);
    else
        node->rightChild = add(node->rightChild, item);
    return balance(node);
}


template<typename T>
Tree<T>::~Tree()
{
    if(begin_ != nullptr)
        deleteNode(begin_);
}