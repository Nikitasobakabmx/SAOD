#pragma once
#include <iostream>
#include <ostream>
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
        friend std::ostream& operator<<(std::ostream &os, Node<T> &item)
        {
            os << item.data;
            return os;
        }
        static void replace(Node<T> *tmp1, Node<T> *tmp2)
	    {
		    T tmp = tmp2->data;
            tmp2->data = tmp1->data;
            tmp1->data = tmp;
            std::cout << tmp << "\t" << tmp1->data << "\t" << tmp2->data << std::endl;
        } 
};
