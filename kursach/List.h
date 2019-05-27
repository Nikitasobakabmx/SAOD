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
	List();
	List(const T &item);
	List(const List<T> &copy);
	void operator= (const List<T> &copy);
	T at(int pos) const;
	void push_back(const T& item) noexcept;
	void push_front(const T& item) noexcept;
	int getSize() const noexcept;
	void find_and_erase(T value);
	void sort();
	~List();
};
template<typename T>
List<T>::List()
{
}

template<typename T>
List<T>::List(const T &item)
{
	begin_ = new Node<T>(item);
	end_ = begin_;
	size_++;
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

	size_ = copy.size_;
	int tSize = 0;
	tmp = copy.begin_;
	while(tmp != nullptr)
	{
		this->push_back(tmp->data);
		tmp = tmp->next;
		tSize++;
	}
	if(size_ != tSize)
		throw except((char*) "Huiovi list!\n");
}

template<typename T>
int List<T>::getSize() const noexcept
{
	return size_;
}

template<typename T>
T List<T>::at(int pos) const
{
	if (pos > size_)
		throw except("You out of range!");
	if(pos == size_)
		return end_->data;
	Node<T> *tmp = begin_;
	for (int i = 0; i < pos + 1; i++)
		tmp = tmp->next;
	return tmp->data;
}

template<typename T>
void List<T>::push_back(const T& item) noexcept
{
	if(begin_ = nullptr)
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
			throw except("List haven't this element!");
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
	for(int i = 0; i < size_; i++)
	{
		T tmp = at(0);
		for(int j = 0; j < size_ - i; i++)
			if(at(i) > tmp)
				tmp = at(i);
		this->find_and_erase(tmp);
		listTmp->push_back(tmp);
	}
	*(this) = *(listTmp);	
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