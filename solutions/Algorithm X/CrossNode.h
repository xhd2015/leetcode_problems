/*
 * CrossNode.h
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */

#ifndef SOLUTIONS_ALGORITHM_X_CROSSNODE_H_
#define SOLUTIONS_ALGORITHM_X_CROSSNODE_H_

#include <string>
#include <List.h>
#include <StringUtils.h>
#include <vector>
#include <iostream>
#include <queue>

namespace x2
{

/**
 * 规定指向自身为空
 */
template <class T>
class CrossNode : public TreeNode<T>
{
public:
	typedef TreeNode<T> Father;
	typedef CrossNode<T> This;
public:
	CrossNode(int i=0,int j=0);
	~CrossNode();


	CrossNode<T>*	removeCol();
	CrossNode<T>* removeRow();
	CrossNode<T>* removeThis();
	void		restoreCol();
	void		restoreRow();
	void		restoreThis();

	AS_MACRO CrossNode<T> *getNext();
	AS_MACRO CrossNode<T> *getPrevious();
	AS_MACRO CrossNode<T> *getSon();
	AS_MACRO CrossNode<T> *getFather();


	CrossNode<T>*	getNth(int n);
	CrossNode<T>*	getNthPrevious(unsigned int n);
	CrossNode<T>*	getNthNext(unsigned int n);

	CrossNode<T>*	getFirstFather();
	CrossNode<T>*	getLastSon();

	std::string toString();
	std::string toDetailedString();

	int i,j;

//	CrossNode<T> *up,*down,*left,*right;
//	T data;//existence is true
};
template <class T>
class CrossNodeHead:public CrossNode<T>{

public:
	CrossNodeHead();
	CrossNodeHead *getMinNum();
	AS_MACRO CrossNodeHead<T> *getNext();
	AS_MACRO CrossNodeHead<T> *getPrevious();
	AS_MACRO CrossNode<T> *getSon();
	AS_MACRO CrossNode<T> *getFather();

	AS_MACRO CrossNodeHead<T>* removeCol();
	AS_MACRO void				restoreCol();

	std::string toString();
	int num;  //number
};

template <class T>
class CrossList{
public:
	CrossList();
	CrossList(T *A,int rowsz,int colsz);

	std::string toString()const;

public:
	CrossNodeHead<T> *head;
};

//===============template syntax
template <class T>
CrossNode<T>::CrossNode(int i,int j):
i(i),j(j)
{

}
template <class T>
CrossNode<T>* CrossNode<T>::removeCol()
{
	CrossNode<T> *p=this->getFirstFather();
	while(p)
	{
		CrossNode<T> *P=p->getPrevious(),*N=p->getNext();
		if(P)P->next=N;
		if(N)N->previous=P;
		p=p->getSon();
	}
	return this;
}

/**
 * previous & next will not be modified
 */
template <class T>
CrossNode<T>* CrossNode<T>::removeRow()
{
	//this->father=F this->son=S this->next=N this->previous=P
	CrossNode<T> *p=(CrossNode<T>*)this->getFirst();
	while(p)
	{
		CrossNode<T> *F=p->getFather(),*S=p->getSon();
		if(F)F->son=S;
		if(S)S->father=F;
		((CrossNodeHead<T>*)p->getFirstFather())->num--;
		p=p->getNext();
	}
	return this;
}
template <class T>
CrossNode<T>* CrossNode<T>::removeThis()
{
	CrossNode<T> *F=(CrossNode<T>*)this->father,*S=(CrossNode<T>*)this->son,*N=(CrossNode<T>*)this->next,*P=(CrossNode<T>*)this->previous;
	if(F)F->son=S;
	if(S)S->father=F;
	if(P)P->next=N;
	if(N)N->previous=P;
	return this;
}
template <class T>
void CrossNode<T>::restoreCol()
{
//	std::cout << "restoring col" << this->toDetailedString() << std::endl;
	CrossNode<T> *p=this->getFirstFather();
	while(p)
	{
		CrossNode<T> *P=p->getPrevious(),*N=p->getNext();
		if(P)P->next=p;
		if(N)N->previous=p;
		p=p->getSon();
	}
}
template <class T>
void CrossNode<T>::restoreRow()
{
//	std::cout << "restoring row " << this->toDetailedString() << std::endl;
	CrossNode<T> *p=(CrossNode<T>*)this->getFirst();
//	std::cout << "first is " << p->toDetailedString() << std::endl;
	while(p)
	{
		CrossNode<T> *F=p->getFather(),*S=p->getSon();
		if(F)F->son=p;
		if(S)S->father=p;
		((CrossNodeHead<T>*)p->getFirstFather())->num++;
		p=p->getNext();
	}
}
/**
 * It does not have to be a truely restore(means that it must be removed before)
 *
 * restore 和 remove必须配对
 */
template <class T>
void CrossNode<T>::restoreThis()
{
	CrossNode<T> *S=(CrossNode<T>*)this->son,*F=(CrossNode<T>*)this->father,*P=(CrossNode<T>*)this->previous,*N=(CrossNode<T>*)this->next;
	if(S)S->father=this;
	if(F)F->son=this;
	if(N)N->previous=this;
	if(P)P->next=this;
}
template <class T>
CrossNode<T>* CrossNode<T>::getNth(int n)
{
	return n>0?getNthNext((unsigned int)n):getNthPrevious((unsigned int)n);
}
template <class T>
CrossNode<T>* CrossNode<T>::getNthPrevious(unsigned int n)
{
	CrossNode<T> *p=this;
	while(p && n>0)
	{
		p=(CrossNode<T>*)p->previous;n--;
	}
	return p;
}
template <class T>
CrossNode<T>* CrossNode<T>::getNthNext(unsigned int n)
{
	CrossNode<T> *p=this;
	while(p && n>0)
	{
		p=(CrossNode<T>*)p->next;n--;
	}
	return p;
}
template <class T>
CrossNode<T>* CrossNode<T>::getFirstFather()
{
	CrossNode<T> *p=this;
	while(p->hasFather())
		p=p->getFather();
	return p;
}
template <class T>
CrossNode<T>* CrossNode<T>::getLastSon()
{
	CrossNode<T> *p=this;
	while(p->hasSon())
		p=p->getSon();
	return p;
}
template <class T>
std::string CrossNode<T>::toString()
{
	return std::string("<")+x2::toString(i)+","+x2::toString(j)+","+x2::toString(this->data)+">";
}
template <class T>
std::string CrossNode<T>::toDetailedString()
{
	std::string s;
	CrossNode<T> *pnode=this;
	s+=pnode->toString();
	s+="\tFather:";
	if(pnode->hasFather())
	{
		s+=pnode->getFather()->toString();
	}else{
		s+="NULL";
	}
	s+="\t";
	s+="Previous:";
	if(pnode->hasPrevious())
	{
		s+=pnode->getPrevious()->toString();
	}else{
		s+="NULL";
	}
	s+="\t";
	s+="Next:";
	if(pnode->hasNext())
	{
		s+=pnode->getNext()->toString();
	}else{
		s+="NULL";
	}
	s+="\t";
	s+="Son:";
	if(pnode->hasSon())
	{
		s+=pnode->getSon()->toString();
	}else{
		s+="NULL";
	}
	return s;
}
//=======class CrossNodeHead
template <class T>
CrossNodeHead<T>::CrossNodeHead():
num(0)
{

}
template <class T>
CrossNodeHead<T> *CrossNodeHead<T>::getMinNum()
{
	CrossNodeHead<T> *minNode=this,*p=(CrossNodeHead<T>*)this->next;
	while(p)
	{
		if(minNode->num > p->num)minNode=p;
		p=(CrossNodeHead<T>*)p->next;
	}
	return minNode;
}
template <class T>
std::string CrossNodeHead<T>::toString()
{
	return std::string("<head:")+x2::toString(num)+">@";//+std::to_string();
}

//========class CrossList
template <class T>
CrossList<T>::CrossList():
head(NULL)
{
}
template <class T>
CrossList<T>::CrossList(T *A,int rowsz,int colsz)
{
	this->head = new CrossNodeHead<T>;
	this->head->num = colsz;

	CrossNodeHead<T>*			curColLast=this->head;

	for(int j=0;j<colsz;j++)
	{
		CrossNodeHead<T>*   nextHead=new CrossNodeHead<T>;
		curColLast->insertNext(nextHead);
		curColLast = nextHead;
	}

	for(int i=0;i<rowsz;i++)
	{
		CrossNode<T> *curRowLast = NULL;
		CrossNodeHead<T>*	curCol=this->head->getNext();
		for(int j=0;j<colsz;j++)
		{
			if(A[i*colsz + j]!=0)
			{
				CrossNode<T> *thisnode=new CrossNode<T>(i,j);
				thisnode->setData( A[i*colsz + j]);
				if(curRowLast)
				{
					curRowLast->insertNext(thisnode);
//					std::cout << "rowLast is " << curRowLast->toString() << std::endl;
				}else{
//					std::cout << "rowLast is NULL" << std::endl;
				}
//				std::cout << "thisnode is " << thisnode->toString() << std::endl;
//				std::cout << "col is " << curCol->toString() << "@" << curCol << std::endl;
//				std::cout << "col's last son is" << curCol->getLastSon()->toString() << "@" << curCol->getLastSon()<< std::endl;
//				std::cout << "===end" << std::endl;
				curRowLast = thisnode;
				curCol->getLastSon()->insertSon(thisnode);
				curCol->num++;
			}
			curCol = curCol->getNext();
		}
	}
}
template <class T>
std::string CrossList<T>::toString()const
{
	std::string s="<node head> -> ";
	std::queue<CrossNode<T>*> colleft;
	CrossNodeHead<T> *phead=this->head->getNext();
	while(phead)
	{
		s += phead->toString()+ ",\t";

		if(phead->hasSon())colleft.push(phead->getSon());
		phead=phead->getNext();
	}
	s+=std::string("\n");
	CrossNode<T>*	pnode=NULL;
	int sum=0;
	while(!colleft.empty())
	{
		pnode=colleft.front();
		colleft.pop();
		sum++;
		s+=pnode->toDetailedString();
		s+="\n";

		if(pnode->hasSon())
			colleft.push(pnode->getSon());


	}
	return s;
}

//================function macros
//=======class CrossNode
template <class T>
CrossNode<T> *CrossNode<T>::getNext()
{
	return (CrossNode<T>*)this->next;
}
template <class T>
CrossNode<T> *CrossNode<T>::getPrevious()
{
	return (CrossNode<T>*)this->previous;
}
template <class T>
CrossNode<T> *CrossNode<T>::getSon()
{
	return (CrossNode<T>*)this->son;
}
template <class T>
CrossNode<T> *CrossNode<T>::getFather()
{
	return (CrossNode<T>*)this->father;
}

template <class T>
CrossNodeHead<T> *CrossNodeHead<T>::getNext()
{
	return (CrossNodeHead<T>*)this->next;
}
template <class T>
CrossNodeHead<T> *CrossNodeHead<T>::getPrevious()
{
	return (CrossNodeHead<T>*)this->previous;
}
template <class T>
CrossNode<T> *CrossNodeHead<T>::getSon()
{
	return (CrossNode<T>*)this->son;
}
template <class T>
CrossNode<T> *CrossNodeHead<T>::getFather()
{
	return (CrossNode<T>*)this->father;
}
template <class T>
CrossNodeHead<T>* CrossNodeHead<T>::removeCol()
{
	return (CrossNodeHead<T>*)this->CrossNode<T>::removeCol();
}
template <class T>
void CrossNodeHead<T>::restoreCol()
{
	this->CrossNode<T>::restoreCol();
}
} /* namespace x2 */

#endif /* SOLUTIONS_ALGORITHM_X_CROSSNODE_H_ */
