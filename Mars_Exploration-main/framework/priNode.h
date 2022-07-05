#pragma once
template <typename T>

class priNode
{

	T item;
	int significant;
	priNode<T>* next;
public:

	priNode()
	{
		next = nullptr;
	}

	priNode(T newItem,int s)
	{
		item = newItem;
		next = nullptr;
		significant = s;

	}
	void setsignificant(int s)
	{
		significant = s;
	}
	int getsignificant()
	{
		return significant;
	}
	void setItem(T newItem)
	{
		item = newItem;
	}

	void setNext(priNode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}

	priNode<T>* getNext() const
	{
		return next;
	}

};

