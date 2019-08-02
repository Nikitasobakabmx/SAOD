#pragma once
#include "BinaryNode.h"
#include "except.h"
#include <ostream>
#include <iostream>
#define elif else if
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
        BinaryNode<T>* min(BinaryNode<T> *node);
        BinaryNode<T>* removeMin(BinaryNode<T> *node);
        BinaryNode<T>* remove(BinaryNode<T> *node, const T &item);
        void copy(BinaryNode<T> *node, BinaryNode<T> *copyNode);
        BinaryNode<T>* at(BinaryNode<T>* node, const T &item);

    public:
        Tree(){};//
        Tree(const T &item):begin_(new BinaryNode<T>(item)), size_(1){};//
        Tree(const Tree &copy);
        void add(const T &item);
        T &at(const char* key);
        T &at(const T& item);
        BinaryNode<T>* find_and_erese(const char* key);
        BinaryNode<T>* find_and_erese(const T& item);
        int size();
        T& operator[](const char* key);
        T& operator[](const T& item);
        Tree<T>& operator=(const Tree<T> &copy);
        friend std::ostream& operator<<(std::ostream &os,const Tree &item)
        {
            if(item.begin_ == nullptr)
                throw except((char*)"Tree is empty!");
            os << item.begin_;
            return os;
        }
        ~Tree();
};
template<typename T>
Tree<T>::Tree(const Tree &copy)
{
    (*this) = copy;
}

template<typename T>
Tree<T>& Tree<T>::operator=(const Tree<T> &copy)
{
    if(begin_ != nullptr)
        deleteNode(begin_);
    size_ = copy.size_;
    if(size_ != 0)
    {
        begin_ = new BinaryNode<T>;
        this->copy(begin_, copy.begin_);
    }
}


//setting function // hiding
template<typename T>
BinaryNode<T>* Tree<T>::at(BinaryNode<T>* node, const T &item)
{
    if(node == nullptr)
        throw except((char*)"Tree hasn't this element!");
    if(item < node->item)
        return balance(at(node->leftChild, item));
    elif(item > node->item)
        return balance(at(node->rightChild, item));
    else
        return balance(node);
};

template<typename T>
int Tree<T>::size()
{
    return size_;
}


template<typename T>
void Tree<T>::copy(BinaryNode<T> *node, BinaryNode<T> *copyNode)
{

    if(copyNode->leftChild != nullptr)
    {
        node->leftChild = new BinaryNode<T>;
        copy(node->leftChild, copyNode->leftChild);
    }
    node->item = copyNode->item;
    if(copyNode->rightChild != nullptr)
    {
        node->rightChild = new BinaryNode<T>;
        copy(node->rightChild, copyNode->rightChild);
    }
}


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
    std::cout << node <<std::endl;

        BinaryNode<T> *rubish = node;
        node = nullptr;
        delete rubish;
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
    node->high = (left>right? left : right) + 1;
}

template<typename T>
BinaryNode<T>* Tree<T>::rightRotate( BinaryNode<T> *node) noexcept
{
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

template<typename T>
BinaryNode<T>* Tree<T>::add(BinaryNode<T> *node, const T &item)
{
    if(node == nullptr)
        return new BinaryNode<T>(item);
    if(item < node->item)
        node->leftChild = add(node->leftChild, item);
    else
        node->rightChild = add(node->rightChild, item);
    size_++;
    return balance(node);
}

template<typename T>
BinaryNode<T>* Tree<T>::min(BinaryNode<T> *node)
{
    return node->leftChild?node->leftChild:node;
}

template<typename T>
BinaryNode<T>* Tree<T>::removeMin(BinaryNode<T> *node)
{
    if(node->leftChild == nullptr)
        return node->rightChild;
    node->leftChild = removeMin(node->leftChild);
    return balance(node);
}

template<typename T>
BinaryNode<T>* Tree<T>::remove(BinaryNode<T> *node, const T &item)
{
    if(node == nullptr) 
        return nullptr;
    if(item < node->item)
        node->leftChild = remove(node->leftChild, item);
    elif(item > node->item)
        node->rightChild = remove(node->rightChild, item);
    else
    {
        BinaryNode<T>* leftTmp = node->leftChild;
        BinaryNode<T>* rightTmp = node->rightChild;
        delete node;
        --size_;
        if(rightTmp == nullptr)
            return leftTmp;
        BinaryNode<T>* minTmp = min(rightTmp);
        minTmp->rightChild = removeMin(rightTmp);
        minTmp->leftChild = leftTmp;
        return balance(minTmp);
    }
    return balance(node);
}

template <typename T>
T& Tree<T>::at(const char* key)
{
    return at((*new T(key)));    
}

template <typename T>
T& Tree<T>::at(const T& item)
{
    if(begin_ == nullptr)
        throw except((char*)"Tree is empty!");
    // BinaryNode<T> *tmp = begin_;
    // balance(tmp);
    // while(true)
    // {
    //     if(item < tmp->item)
    //     {
    //         if(tmp->leftChild == nullptr)
    //             throw except((char*)"Hasn't this value!");
    //         tmp = tmp->leftChild;
    //     }
    //     if(item > tmp->item)
    //     {
    //         if(tmp->rightChild == nullptr)
    //             throw except((char*)"Hasn't this value!");
    //         tmp = tmp->rightChild;
    //     }
    //     if(item == tmp->item)
    //     {
    //         balance(tmp);
    //         return tmp->item;
    //     }
    //     balance(tmp);
    // }
    return at(begin_, item)->item;
}
template <typename T>
T& Tree<T>::operator[](const T& item)
{
    return at(item);
}

template <typename T>
T& Tree<T>::operator[](const char* key)
{
    return at(key);
}


template <typename T>
BinaryNode<T>* Tree<T>::find_and_erese(const char* key)
{
    T item(key);
    return this->find_and_erese(item);
}

template <typename T>
BinaryNode<T>* Tree<T>::find_and_erese(const T& item)
{
    if(begin_ == nullptr)
        throw except((char*)"Tree is empty!");
    return begin_ = remove(begin_, item);
}

template <typename T>
void Tree<T>::add(const T &item)
{
    begin_ = add(begin_, item);
}

template<typename T>
Tree<T>::~Tree()
{
    if(begin_ != nullptr)
        deleteNode(begin_);
}