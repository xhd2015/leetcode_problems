/*
 * List.h
 *
 *  Created on: 2017年4月6日
 *      Author: 13774
 */

#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <def.h>

namespace x2
{

template<class T>
class ListNode{
public:
	typedef ListNode<T> This;
public:
	ListNode();
    ListNode(const T& data,ListNode<T>* next=NULL,ListNode<T>* previous=NULL);
    ~ListNode();

    AS_MACRO const T& getData()const;
    AS_MACRO T& getData();
    AS_MACRO void setData(const T& data);
    AS_MACRO ListNode<T>* getNext()const;
    AS_MACRO ListNode<T>* getPrevious()const;
    AS_MACRO void setNext(ListNode<T>* next);
    AS_MACRO void  setPrevious(ListNode<T>* previous);
    ListNode<T>* removeNext();
    ListNode<T>* removePrevious();
    void    insertNext(ListNode<T>* next);
    void    insertPrevious(ListNode<T>* previous);
    AS_MACRO int  hasNext()const;
    AS_MACRO int  hasPrevious()const;//done
    /**
     * @new method since 2017-03-18 21:23:10
     */
    void		adjustOffset(ptrdiff_t diff);


    ListNode<T>*    getLast()const;//done
    ListNode<T>*    getFirst()const;//done
    DEPRECATED AS_MACRO static void adjustOffset(char **p,ptrdiff_t off);
    //指向构造函数的地址
    //用 new (void*p) 构造函数,俗称placement new
protected:
    T   data;//for storage
    ListNode<T> *next,*previous;
};

//===============TreeNode and Tree
//	uses "Tree.cpp"
template <class T>
class TreeNode:public ListNode<T>{
public:
	typedef ListNode<T> Father;
public:
	TreeNode();
    TreeNode(const T& data,TreeNode<T>* father=NULL,TreeNode<T>* son=NULL,TreeNode<T>* next=NULL,TreeNode<T>* previous=NULL);
    ~TreeNode();

    AS_MACRO void setSon(TreeNode<T>* son);//done
    AS_MACRO void setFather(TreeNode<T>* father);//done
    AS_MACRO TreeNode<T>* getSon()const; //done
    AS_MACRO TreeNode<T>* getDirectFather()const;//direct father,done
    		void		addSon(TreeNode<T>* son);
    AS_MACRO bool		hasSon()const;
    AS_MACRO bool 		hasFather()const;

    void		insertSon(TreeNode<T>* son);
    void		insertFather(TreeNode<T>* father);
    TreeNode<T>*	removeSon();
	TreeNode<T>*	removeFather();
	void 			adjustOffset(ptrdiff_t diff);


    TreeNode<T>* getParent()const;//往previous一直遍历，直到是根，然后返回根的father,done

protected:

    TreeNode<T> *son,*father;

};

//================template syntax function
//===========class : ListNode
template <class T>
ListNode<T>::ListNode():
next(NULL),previous(NULL)
{

}
template<class T>
ListNode<T>::ListNode(const T& data,ListNode<T>* next,ListNode<T>* previous):
data(data),
next(next),
previous(previous)
{
}
template<class T>
ListNode<T>::~ListNode()
{

}

template<class T>
ListNode<T>* ListNode<T>::removeNext()
{
    ListNode<T>* rt=this->getNext();
    if(this->hasNext())
    {
        this->setNext(rt->getNext());
        if(rt->hasNext())
        {
            rt->getNext()->setPrevious(this);
        }
    }
    return rt;
}

template<class T>
ListNode<T>* ListNode<T>::removePrevious()
{
    ListNode<T>* rt=this->getPrevious();
    if(this->hasPrevious())
    {
        this->setPrevious(rt->getPrevious());
        if(rt->hasPrevious())
        {
            rt->getPrevious()->setNext(this);
        }
    }
    return rt;
}


template<class T>
void    ListNode<T>::insertNext(ListNode<T>* next)
{
    if(next)
    {
        ListNode<T>* temp1;
        temp1 = this->getNext();
        if(temp1)
        {
            temp1->setPrevious(next);
        }
        next->setPrevious(this);
        next->setNext(temp1);
        this->setNext(next);
    }
}

template<class T>
void    ListNode<T>::insertPrevious(ListNode<T>* previous)
{
    if(previous)
    {
        ListNode<T>* prev=this->getPrevious();
        if(prev)
        {
            prev->setNext(previous);
        }
        previous->setNext(this);
        previous->setPrevious(prev);
        this->setPrevious(previous);
    }
}
template<class T>
void   ListNode<T>::adjustOffset(ptrdiff_t diff)
{
	if(this->next!=NULL)
		this->next = (ListNode<T>*)((char*)this->next + diff);
	if(this->previous!=NULL)
		this->previous = (ListNode<T>*)((char*)this->previous + diff);
}
template<class T>
ListNode<T>*   ListNode<T>::getLast()const
{
//	Util::printStr("in ListNode getLast\n");
    ListNode<T>* p=(ListNode<T>*)this;
    while(p->hasNext())
    {
        p=p->getNext();
    }
//    Util::printStr("in getLast returning \n");
    return p;
}
template<class T>
ListNode<T>*    ListNode<T>::getFirst()const
{
    ListNode<T> *p=(ListNode<T>*)this;
    while(p->hasPrevious())
    {
        p=p->getPrevious();
    }
    return p;
}


//============class : TreeNode
template<class T>
TreeNode<T>::TreeNode():
son(NULL),
father(NULL)
{

}
template<class T>
TreeNode<T>::TreeNode(const T& data,TreeNode<T>* father,TreeNode<T>* son,TreeNode<T>* next,TreeNode<T>* previous):
ListNode<T>(data,next,previous),
father(father),
son(son)
{

}
template<class T>
inline TreeNode<T>::~TreeNode() {
}

template<class T>
void TreeNode<T>::addSon(TreeNode<T>* son)
{
//	Util::printStr("in TreeNode addSon \n");
	TreeNode<T>*	orison=this->getSon();
	if(orison)
	{
		orison->getLast()->insertNext(son);
	}else{
		this->setSon(son);
	}
}
template<class T>
void TreeNode<T>::insertSon(TreeNode<T>* son) {
	if(son!=NULL)
	{
#if defined(CODE64)
//	printf("insertSon 0\n");
#endif
#if defined(CODE64)
//	printf("getSon return\n");
#endif
		TreeNode<T> *orison=this->getSon();
#if defined(CODE64)
//	printf("insertSon 1\n");
#endif
		this->setSon(son);
#if defined(CODE64)
//	printf("insertSon 2\n");
#endif
		son->setFather(this);
#if defined(CODE64)
//	printf("insertSon 3\n");
#endif
		son->setSon(orison);
		if(orison)
		{
			orison->setFather(son);
		}
	}
}

template<class T>
void TreeNode<T>::insertFather(TreeNode<T>* father) {
	if(father!=NULL)
	{
		TreeNode<T> *orifather=this->getDirectFather();
		this->setFather(father);
		father->setSon(this);
		father->setFather(orifather);
		if(orifather)
		{
			orifather->setSon(father);
		}
	}
}

template<class T>
TreeNode<T>* TreeNode<T>::removeSon() {
	if(this->getSon())
	{
		TreeNode<T> *son=this->getSon()->getSon();
		this->setSon(son);
		son->setFather(this);
		this->getSon()->setFather(NULL);
		this->getSon()->setSon(NULL);
	}
}
template<class T>
void 			TreeNode<T>::adjustOffset(ptrdiff_t diff)
{
	this->Father::adjustOffset(diff);
	if(this->father!=NULL)
		this->father = (TreeNode<T>*)((char*)this->father + diff);
	if(this->son!=NULL)
		this->son = (TreeNode<T>*)((char*)this->son + diff);
}

template<class T>
TreeNode<T>* TreeNode<T>::removeFather() {
	if(this->getDirectFather())
	{
		TreeNode<T> *father=this->getDirectFather()->getDirectFather();
		this->setFather(father);
		father->setSon(this);
		this->getDirectFather()->setFather(NULL);
		this->getDirectFather()->setSon(NULL);
	}
}

template<class T>
TreeNode<T>* TreeNode<T>::getParent()const {//往previous一直遍历，直到是跟，然后返回跟的father
	TreeNode<T> *p=(TreeNode<T>*)this;
	while(p->hasPrevious())
	{
		p=(TreeNode<T>*)p->getPrevious();
	}
	return p->getDirectFather();
}



//===============function macros

//=========class : ListNode
template<class T>
ListNode<T>* ListNode<T>::getNext()const
{
    return next;
}

template<class T>
ListNode<T>* ListNode<T>::getPrevious()const
{
    return previous;
}
template<class T>
void ListNode<T>::setNext(ListNode<T>* next)
{
    this->next = next;
}

template<class T>
void  ListNode<T>::setPrevious(ListNode<T>* previous)
{
    this->previous = previous;
}
template<class T>
int  ListNode<T>::hasPrevious()const
{
    return (this->previous!=NULL);
}
//template<class T>
//void ListNode<T>::adjustOffset(char **p,ptrdiff_t diff)
//{
//	if(p!=NULL && *p!=NULL)*p+=diff;
//}
template<class T>
int  ListNode<T>::hasNext()const
{
    return (this->next!=NULL);
}

template<class T>
const T& ListNode<T>::getData()const
{
    return data;
}
template<class T>
T& ListNode<T>::getData()
{
    return data;
}
template<class T>
void ListNode<T>::setData(const T& data)
{
    this->data=data;
}
//======class TreeNode

template<class T>
 void TreeNode<T>::setSon(TreeNode<T>* son)
  {
#if defined(CODE64)
	//printf("setSon is : %x \n",son);
#endif
  	this->son=son;
  }
template<class T>
void TreeNode<T>::setFather(TreeNode<T>* father) {
    this->father=father;
}

template<class T>
TreeNode<T>* TreeNode<T>::getSon() const{
#if defined(CODE64)
//	printf("gettSon \n");
#endif
	return son;
}

template<class T>
TreeNode<T>* TreeNode<T>::getDirectFather()const {//direct father
#if defined(CODE64)
//	printf("call direct,this is %x,father is %x\n",this,this->father);
#endif
    return father;
}

template<class T>
bool		 TreeNode<T>::hasSon()const
{
	return this->son!=NULL;
}
template<class T>
bool 		 TreeNode<T>::hasFather()const
{
	return this->father!=NULL;
}



} /* namespace x2 */

#endif /* INCLUDE_LIST_H_ */
