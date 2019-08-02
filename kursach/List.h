#pragma once
#include "Node.h"
#include "except.h"
#include <iostream>

template<typename T>
class List
{
private:
	Node<T> *begin_ = nullptr;
	Node<T> *end_ = nullptr;//reduct
	int size_ = 0;//reduct
public:
	List(void){};
	List(const T &item);
	List(const List<T> &copy);
	void operator= (const List<T> &copy);
	T& at(int pos);
	Node<T>* atNode(int pos);
	T& operator[](int pos);
	void push_back(const T& item) noexcept;
	void push_front(const T& item) noexcept;
	int getSize() const noexcept;
	void find_and_erase(T value);
	void sort();
	friend std::ostream& operator <<(std::ostream &os, List<T> &item)
	{
		Node<T> *tmp = item.begin_;
		for(int i = 0; i < item.size_; i++)
		{
			os << *tmp << " : ";
			tmp = tmp->next;
		}
		return os;
	}
	
	~List();
};


template<typename T>
List<T>::List(const T &item)
{
	end_ = new Node<T>(item);
	begin_ = end_;
	size_++;
	//std::cout << *begin_ << std::endl;
}

template<typename T>
List<T>::List(const List<T> &copy)
{
	*(this) = (copy);
}

template<typename T>
void List<T>::operator= (const List<T> &copy)
{
	Node<T> *tmp;
	while (begin_ != nullptr)
	{
		tmp = begin_;
		delete tmp;
		begin_ = begin_->next;
	}
	size_ = 0;
	tmp = copy.begin_;
	while(tmp != nullptr)
	{
		this->push_back(tmp->data);
		tmp = tmp->next;
	}
	if(size_ != copy.size_)
		throw except((char*) "Huiovi list!\n");
}

template<typename T>
int List<T>::getSize() const noexcept
{
	return size_;
}

template<typename T>
T& List<T>::at(int pos)
{
	return atNode(pos)->data;
}

template<typename T>
Node<T>* List<T>::atNode(int pos)
{
	if (pos > size_)
		throw except((char*)"You out of range!");
	if(pos == size_)
		return end_;
	Node<T> *tmp = begin_;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp;
}


template<typename T>
T& List<T>::operator[](int pos)
{
	return this->at(pos);
}

template<typename T>
void List<T>::push_back(const T& item) noexcept
{
	if(begin_ == nullptr)
	{
		begin_ = new Node<T>(item);
		end_ = begin_;
		size_++;
		return;
	}
	end_->next = new Node<T>(item);
	end_ = end_->next;
	size_++;
	return;
}

template<typename T>
void List<T>::push_front(const T& item) noexcept
{
	if(begin_ == nullptr)
	{
		begin_ = new Node<T>(item);
		end_ = begin_;
		size_++;
		return;
	}
	Node<T> *tmp = new Node<T>(item);
	tmp->next = begin_;
	begin_ = tmp;
	size_++;
	return;
}

template<typename T>
void List<T>::find_and_erase(T value)//reduct
{
	Node<T> *tmp = begin_;
	if (begin_->data == value)
	{
		begin_ = tmp->next;
		delete tmp;
		size_--;
		return;
	}
	while (tmp->next->data != value)
	{
		tmp = tmp->next;
		if (tmp->next == nullptr)
			throw except((char*)"List haven't this element!");
	}
	Node<T> *tmpOne = tmp->next;
	tmp->next = tmpOne->next;
	size_--;
	delete tmpOne;
}

template<typename T>
void List<T>::sort()
{
	if(size_ == 0)
		throw except((char*)"List is empty");
	if(size_ == 1)
		return;
	List<T> *listTmp = new List<T>();
	//std::cout << size_ << std::endl;
	for(int i = 0; i < size_; i++)
	{
		Node<T> *tmp = atNode(0);
		for(int j = 0; j < size_ - i; j++)
		{
			if(at(j) > tmp->data)
			{
				std::cout << size_ << std::endl;
				tmp = atNode(j);
			}
		}
		Node<T>::replace(atNode(size_-i), tmp);
	}
}

template<typename T>
List<T>::~List()
{
	Node<T> *tmp;
	while (begin_ != nullptr)
	{
		tmp = begin_;
		begin_ = begin_->next;
		delete tmp;
	}
}
