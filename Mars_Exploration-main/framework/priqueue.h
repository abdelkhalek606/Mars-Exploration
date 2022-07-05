#pragma once
#include"priNode.h"

template <typename T>
class priqueue
{

	priNode <T>* Head= nullptr;
		priNode <T>*  rare= nullptr;


public:
	bool isEmpty() {
		return (Head == nullptr);
	}
	priqueue() {
		
			rare = nullptr;
			Head = nullptr;

		
	}
	~priqueue() {
	T i;
	    while (dequeue(i));
		
			
	}
	priqueue(const priqueue<T>& LQ)
	{
		priNode<T>* NodePtr = LQ.Head;
		if (!NodePtr) //LQ is empty
		{
			Head = rare = nullptr;
			return;
		}

		//insert the first node
		priNode<T>* ptr = new priNode<T>(NodePtr->getItem(), NodePtr->getsignificant());
		Head = rare = ptr;
		NodePtr = NodePtr->getNext();

		//insert remaining nodes
		while (NodePtr)
		{
			priNode<T>* ptr = new priNode<T>(NodePtr->getItem(), NodePtr->getsignificant());
			rare->setNext(ptr);
			rare = ptr;
			NodePtr = NodePtr->getNext();
		}
	}
	priqueue operator = (priqueue p) {
		
		priNode<T>* itrator = p.Head;
		priqueue<T> pr;
		while (itrator)
		{
		
			pr.enqueue(itrator->getItem(), itrator->getsignificant());
				itrator = itrator->getNext();
		}
		return pr;
	}
	bool enqueue(const T& newitem, int sig) {
		bool b=true; 
		priNode<T>* newNodePtr = new priNode<T>(newitem, sig);
		priNode<T>* itrator = Head;
		if (isEmpty() || sig > Head->getsignificant())
		{
			newNodePtr->setNext(Head);
			Head = newNodePtr;
		}
		else
		{
			itrator = Head;
			while (itrator &&itrator->getNext() && itrator->getNext()->getsignificant() >= sig)
			
				itrator = itrator->getNext();
			if (itrator)
			{
				newNodePtr->setNext(itrator->getNext());
				itrator->setNext(newNodePtr);
			}
			else {
				newNodePtr->setNext(nullptr);
				rare->setNext(newNodePtr);
			}
		}
		
		return true;
	}
	bool dequeue(T& hd)
	{
		if (isEmpty())
			return false;
		if (Head == nullptr)
			return false;
		priNode<T>* Deletednode = Head;
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

		hd = Head->getItem();
		return true;
	}
};

