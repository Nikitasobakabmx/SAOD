#pragma once
template<typename T>
class Node
{
    public:
        Node<T> *next;
        T data;
    
        Node();
        Node(const Node<T> &copy)
        {
            data = copy.data;
        }
        Node(const T &item)
        {
            data = item;
        }
};
