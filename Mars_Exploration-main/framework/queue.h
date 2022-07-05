#pragma once
#include"Node.h"
template <typename T>
class queue
{
	
	Node <T>* Head;
	Node <T>* rare;

public:
	queue() {
		Head = nullptr;
		 rare = nullptr;
	}
	~queue() {
		T i;
		while (dequeue(i));
	}
	queue(const queue<T>& LQ)
	{
		Node<T>* NodePtr = LQ.Head;
		if (!NodePtr) //LQ is empty
		{
			Head = rare = nullptr;
			return;
		}

		//insert the first node
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		Head = rare = ptr;
		NodePtr = NodePtr->getNext();

		//insert remaining nodes
		while (NodePtr)
		{
			Node<T>* ptr = new Node<T>(NodePtr->getItem());
			rare->setNext(ptr);
			rare = ptr;
			NodePtr = NodePtr->getNext();
		}
	}
	bool isEmpty() {
		return (Head == nullptr);
	}
	bool enqueue(const T& newitem) {

		Node<T>* newNodePtr = new Node<T>(newitem);
		
		if (isEmpty())	
			Head = newNodePtr; 
		else
			rare->setNext(newNodePtr); 

		rare = newNodePtr; 
		return true;
	}
	bool dequeue(T& hd)
	{
		if (isEmpty())
			return false;
		if (Head == nullptr)
			return false;
		Node<T>* Deletednode = Head;
		hd = Head->getItem();
		Head = Head->getNext();
		
		if (Deletednode == rare)
		{
			rare = nullptr;
			Head = nullptr;
		}
		
		delete Deletednode;

		return true;
	}
	bool peak(T& hd) {
		if (isEmpty())
			return false;

		hd =Head->getItem();
		return true;
	}
};

