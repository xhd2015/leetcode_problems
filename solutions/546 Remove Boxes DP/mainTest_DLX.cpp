/*
 * mainTest_DLX.cpp
 *
 *  Created on: 2017年4月10日
 *      Author: 13774
 */

#include <vector>
#include <iostream>
#include <cstddef>
using namespace  std;

struct Node{
	Node *next,*previous;
	int digit;
	int num;
	Node(int digit,int num=1,Node* next=NULL,Node* previous=NULL):next(next),previous(previous),digit(digit),num(num){}
	void remove()
	{
		Node *N=this->next,*P=this->previous;
		if(P)P->next = N;
		if(N)N->previous = P;
	}
	void restore()
	{
		Node *N=this->next,*P=this->previous;
		if(P)P->next = this;
		if(N)N->previous = this;
	}
};

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
    	root=new Node(-1);
    	Node *p=root;
    	for(int i=0,isz=(int)boxes.size();i<isz;)
    	{
    		int digit=boxes[i];
    		int num=0;
//    		std::cout << "digit is " << digit << std::endl;
    		while(i<isz && boxes[i]==digit)i++;
    		Node *thisnode=new Node(digit,num);

    		p->next = thisnode;
    		thisnode->previous = p;
    		p = thisnode;
    	}

    	max = 0;
    	curDigit = -1;
    	curNum = 0;
    	curVal = 0;
    	solve();

    	return max;

    }

    void solve()
    {
    	if(root->next == NULL) //get a solution
    	{
    		if(curVal > max)max=curVal;
//    		std::cout << "get a curval " << curVal << std::endl;
    	}else{
    		Node *p=root->next;
//    		std::cout << "current is " << p->num << std::endl;
    		while(p)
    		{
    			int prevVal = curVal,prevNum=curNum,prevDigit=curDigit;

    			std::vector<Node*> reserved;
    			reserved.push_back(p);

    			Node *pnext=p->next;
    			curDigit = p->digit;
    			curNum = p->num;
    			while(pnext && pnext->digit==curDigit)
    			{
    				curNum += pnext->num;
    				reserved.push_back(pnext);
    				pnext = pnext->next;
    			}
    			curVal += 2*curNum + 1;

    			for(auto pt : reserved)
    			{
    				pt->remove();
    			}
    			solve();
    			for(auto rit=reserved.rbegin(),ritend=reserved.rend();rit!=ritend;rit++)
    			{
    				(*rit)->restore();
    			}
    			curVal = prevVal;
    			curNum = prevNum;
    			curDigit = prevDigit;

    			p=pnext;
    		}

    	}
    }

    Node *root;
    int max;
    int curDigit,curNum,curVal; //<digit,num> val
};
void testRemoveBoxes_DLX()
{
		std::vector<int> boxes ={8, 6, 2, 6, 6, 3, 2, };//3, 2, 2};
	//	result = 24
		Solution s;
		int v = s.removeBoxes(boxes);
		std::cout << "max is " << v << std::endl;
}

