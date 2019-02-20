#include <iostream>
#include "except.h"
#include <ostream>

template<typename T>
struct Node
{
    T value;
    Node<T> *next = nullptr;
    Node<T> *previous = nullptr;
    Node(const T &value);
    ~Node();
};

template<typename T>
Node<T>::Node(const T &value)
{
    this->value = value;
}

template<typename T>
Node<T>::~Node()
{
    delete next;
    delete previous;
}

template<typename T>
struct List
{
private:
    Node<T> *start = nullptr;
    Node<T> *end = nullptr;
    int size = 0;
public:
    List();
    List(List &copy);
    void pushBack(const T &value);
    void pushFront(const T &value);
    void reverse();
    T at(int pos) const;
    List<T>* cut(const T &value);
    void show();
    ~List();
};


template<typename T>
List<T>::List()
{

}

template<typename T>
List<T>::List(List &copy)
{
    size = copy.size;
    if(copy.start == nullptr) 
        return;
    start = new Node<T>(copy.at(0));
    end = start;
    for(int i = 1; i < size; i++)
    {
        end->next = new Node<T>(copy.at(i));
        Node<T> *tmp = end;
        end = end->next;
        end->previous = tmp;//?
    }
}

template<typename T>
void List<T>::pushBack(const T &value)
{
    if(end == nullptr)
    {
        start = new Node<T>(value);
        end = start;
        size++;
        return;
    }
    end->next = new Node<T>(value);
    Node<T> *tmp = end;
    end = end->next;
    end->previous = tmp;//?
    size++;
    return;
}

template<typename T>
void List<T>::pushFront(const T &value)
{
    if(start == nullptr)
    {
        start = new Node<T>(value);
        end = start;
        size++;
        return;
    }
    Node<T> *tmp = new Node<T>(value);
    tmp->next = start;
    start->previous = tmp;//?
    start = tmp;
    size++;
    return;
}

template<typename T>
void List<T>::reverse()
{
    if(start == nullptr)
        throw except((char*)"Youooo!\nList is empty!");
    Node<T> *tmp = start;
    start = end;
    end = tmp;
    for(int i = 0; i < size; i++)
    {
        Node<T> *tmp1 = tmp->next;
        tmp->next = tmp->previous;
        tmp->previous = tmp1;
        tmp = tmp1;
    }
}

template<typename T>
T List<T>::at(int pos) const
{
    if(start == nullptr)
        throw except((char*)"Youooo!\nList is empty!");
    Node<T> *tmp = start;
    for(int i = 0; i < pos+1; i++)
        tmp = tmp->next;
    return tmp->value;
}

template<typename T>
List<T> *List<T>::cut(const T &value)//ok
{
    if(start == nullptr)
        throw except((char*) "Meow!");
    Node<T> *tmp = start;
    int tmpSize = 0;
    while(true)
    {
        if(tmp->value == value)
            break;
        if(tmp->next == nullptr)
            throw except((char*)"Gav!");
        tmpSize++;
        tmp = tmp->next;        
    }
    List<T> *tmpList = new List<T>();
    tmpList->size = size - tmpSize;
    tmpList->start = new Node<T>(tmp->value);
    tmpList->start->next = tmp->next;
    tmpList->end = end;
    end = tmp->previous;
    end->next = nullptr;
    size = tmpSize;    
    return tmpList;
}

template<typename T>
void List<T>::show()
{
    if(start == nullptr)
        throw except((char*) "Yoooo!, List is empty!");
    Node<T> *tmp = start;
    for(int i = 0; i < size; i++)
    {
        std::cout << tmp->value << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}


template<typename T>
List<T>::~List()
{
    while(start != nullptr)
    {
        start = start->next;
        delete start->previous; 
    }
}
 
int main(int argc, char **argv)
{
    std::cout << "Yoooo\nInsert array\nIf you want stop insert 0\n";
    List<int>* listOne = new List<int>();
    int chek;
    while (true)
    {
        std::cin >> chek;
        if(chek == 0)
            break;
        listOne->pushBack(chek);
    }
    std::cout << "Yooo, now insert value from array\n";
    std::cin >> chek;
    try
    {
        List<int> *listTwo = listOne->cut(chek);
        listTwo->show();       
        listOne->reverse();
        listOne->show();
    }
    catch(except ex)
    {
        std::cout << ex.what();
    }
    return 0;
}