//============ACCEPTED BY : Leetcode=============
//============TIME : 28ms=========
//============MEMORY : UNKNOWN K======
//============TIME COMPLEXITY : O(n^2)==
//============SPACE COMPLEXITY : O(n^3)=
//============DETAILS : 60/60 Tests Passed=====
//============DATE : 2017-04-10 10:48:18========
/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: 13774
 */
#include <vector>
#include <iostream>
#include <ctime>
#include <map>

using namespace std;

struct Node{
	Node *next,*previous;
	int val;
	int num;
	Node(Node* next=NULL,Node* previous=NULL):next(next),previous(previous){}
	Node(int val,int num,Node* next=NULL,Node* previous=NULL):next(next),previous(previous),val(val),num(num){}

	void insertNext(int val,int num)
	{
		Node *newnode=new Node(val,num,this->next,this);
		if(newnode->next)
			newnode->next->previous = newnode;
		this->next = newnode;
	}
	//remove all node after thisnode such that the count of number can not exceed biggestnum
	static void eliminate(Node *thisnode,int biggestnum)
	{
		Node *p=thisnode->next;
		while(p && biggestnum >= p->num) p = p->next;
		/**
		 * We should free those nodes here,but I did not.
		 * make a note to mark this problem
		 */
		thisnode->next = p;
		if(p)p->previous = thisnode;
	}
	/**
	 * true means DONE on this node
	 */
	static void update(Node* thisnode,int newval,int newnum)
	{
		while(true)
		{
			if(newval > thisnode->val)
			{
				if(newnum >= thisnode->num)
				{
					thisnode->val = newval;
					thisnode->num = newnum;
					eliminate(thisnode,newnum);
				}else{//insert this to next
					Node *newnode = new Node(newval,newnum,thisnode,thisnode->previous);
					thisnode->previous = newnode;
					if(newnode->previous)
						newnode->previous->next = newnode;
				}
				return;//ended
			}else if(newval == thisnode->val)
			{
				if(newnum > thisnode->num) {thisnode->num = newnum;eliminate(thisnode,newnum);}
				return;
			}else{
				if(newnum <= thisnode->num)return;
				else if(thisnode->next == NULL)
				{
					Node *newnode = new Node(newval,newnum,NULL,thisnode);
					thisnode->next = newnode;
					return;
				}else{
					thisnode = thisnode->next;//continue to next
				}
			}
		}
	}
};

class Solution
{
public:
	int removeBoxes(vector<int>& boxes)
	{
		row = (int) boxes.size();
		col = row;
		C = new std::map<int,Node>[row * col]; //C[i][j][k]
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				int base = i*col + j;
				if(i > j)continue;
				else if( i == j)
				{
					C[base].insert({0,Node()});
					C[base][0].insertNext(1, 1);
				}else{
					C[base].insert({j-i,Node()});
					C[base][j-i].insertNext(-1, -1);
				}
			}
		}
		this->boxes = &boxes;
		solveRangeg(0,row-1);
		int val = C[row-1][row - 1].next->val;
		return val;//C[0][row-1][row-1][VAL]
	}
	/**
	 * i<j &&  0<=k<=j-i-2  但不必做检查 A[i+k]==A[j], A[j]!=A[j-1]
	 */
	void solveRangef(int i,int j,int k)
	{
		int base=i*col + j;
		if(C[base].find(k)!=C[base].end())return; //already has i,j,k solved
		if(i<0 || i>=row || j<0 || j>=col || i>=j)return;

		C[base].insert({k,Node()});
		C[base][k].insertNext(-1, -1);

		solveRangeg(i,i+k);
		solveRangeg(i+k+1,j-1);

		int diff = j -i -k-2;
		int base2=(i+k+1)*col + (j-1);
		int isolateVal=diff>=0?C[base2][diff].next->val:0;
//		std::cout << "isolate value is " << isolateVal << std::endl;

		int base1=i*col + (i+k);
		Node *n=C[base1][k].next;
		Node *basenode=C[base][k].next;
		while(n)
		{
			Node::update(basenode,n->val + 2*n->num + 1 + isolateVal,n->num + 1);
			n=n->next;
		}

//		std::cout << "(in f) "<< "at "<<i << " to "<< j<<", last is  "<< boxes->operator[](j)<<"  F:" << ","<<C[base + FVAL] << "," << C[base+FLASTNUM]<<"          ";
//		std::cout << "G:"<<C[base + GVAL] << "," << C[base+GLASTNUM]<< std::endl;
	}
	/**
	 * i<j
	 *
	 * GVAL总是保持最大值
	 */
	void solveRangeg(int i,int j)
	{
//		std::cout <<"C["<<i<<","<<j<<","<<(j-i)<<"]="<<C[base + GVAL]<<std::endl;
		int base=i*col+j;
  		if(i<0 || i>=row || j<0 || j>=col || i>=j || C[base][j-i].next->val!=-1)return;


		solveRangeg(i,j-1);

		std::vector<int> &A = *boxes;
		Node *basenode=C[base][j-i].next;
		int base1 = i*col + (j-1);
		Node *base1node=C[base1][j-i-1].next;
		if(A[j]==A[j-1])
		{
			Node *n=base1node;
			while(n)
			{
				Node::update(basenode, n->val + 2*n->num + 1, n->num + 1);
				n=n->next;
			}
//			if(i==0)
//			{
//				std::cout << "(in g) "<< "at "<<i << " to "<< j<<", last is  "<< boxes->operator[](j)<<"  F:" << ","<<C[i][j][j-i][0].first << "," << C[i][j][j-i][0].second<<"          " <<
//						std::endl;
//			}
			return;
		}

		Node::update(basenode,base1node->val + 1,1);
		for(int r=j-i-2;r>=0;r--)
		{
			if(A[r+i]!=A[j])continue;
			solveRangef(i,j,r);
			Node *n=C[base][r].next;
			while(n)
			{
				Node::update(basenode,n->val,n->num);
				n = n->next;
			}
		}
//		if(i==0){
//			std::cout << "(in g) "<< "at "<<i << " to "<< j<<", last is  "<< boxes->operator[](j)<<"  F:" << ","<<C[i][j][j-i][0].first << "," << C[i][j][j-i][0].second<<"          " << std::endl;
//		}
	}


	std::map<int,Node> *C;
	//看来这个算法不是无后效的，在每一步选择了一个合并方式时，会因为后面的数字而被修改。
	std::vector<int> *boxes;
	int row;
	int col;
};

void testRemoveBoxes()
{
//	std::vector<int> boxes ={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
//	std::vector<int> boxes ={1,1,1,1,1,1,1,1,1,1,2,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//	std::cout << "size is " << boxes.size() << std::endl;
	//result is 9606
//
//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10,
//			10, 6, 6, 2, 9, 2, 2, 4, 6, 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5, 5, 9, 1, 8, 6, 2, 9};
	//result is 114

	std::vector<int> boxes ={3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5,
			8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3,
	9, 8, 8, 6, 5, 3/*35*/, 7, 4, 9, 6, 3/*40*/,9, 4, 3, 5, 10, 7, 6, 10, 7/*49*/};
	//0-35 = 3,    <98,2>
	//0-29 = 3     <76,5>
	//result is 136, mine is 124

//	[3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5,8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3,9, 8, 8, 6, 5, 3, 7, 4, 9, 6]
	//result is 102, is fine
	//but by adding one more,it is wrong
	//adding 3, I get 107,but which should be 111

//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10, 10, 6, 6, 2, 9, 2, 2, 4, 6,
//		 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5};
	//result is 97
//
//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10, 10, 6, 6, 2, 9, 2, 2, 4, 6,
//	 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5,5};
	//result is 106, mine is 102

//	std::vector<int> boxes ={8, 2, 2, 9, 6, 4, 3, 10, 2, 10, 10, 1, 10, 2, 9, 5, 2, 9, 7, 4, 10, 2, 3, 8, 3, 6, 10, 9, 7, 10, 9, 7, 5, 3, 4, 1, 3, 10, 2, 6, 1, 1, 1, 2, 5, 5, 10, 8, 9, 9};
	//result is 146, mine is 142
//	std::vector<int> boxes ={ 1,1,1};
	//result = 9


//	std::vector<int> boxes ={ 1, 3, 2, 2, 2, 3, 4, 3, 3 };
	//result = 27
//	std::vector<int> boxes ={8, 6, 2, 6, 6, 3, 2, 3, 2, 2};
//	result = 24

//	std::vector<int> boxes ={ 1, 3, 2, 2, 2, 3, 4, 3, 1 ,2,2};
	//result = 33

	//i,j中以k结尾时，i~k-1 k+1~j是相互独立的，并且肯定是 k+1~j先消除，然后 i~k-1再消除，然后再消除k是最大值
	//但是存在一个问题，i~k-1能否与k相互合并从而得到一个更大的值？取决于i~k-1的最后一个数是否与k的数相同
//	std::vector<int> boxes ={8, 6, 2, 6, 6, 3, 2, 3, 2, 2};//可以先预处理，将重复元素合并
	// result = 24
	/**
	 * process
	 *   8 6 2 6 6， 以 k=3为例
	 *	合并顺序 : 6， 8 6 2, 6  选择一个能与6构成更大数的方式 6, 8 2 6,6
	 *	k=4时，能与6构成的更大的，max of 6
	 *
	 *
	 *	f(i,j)时
	 *	f(i,j+1)与 A[j+1],f(i,j)的关系
	 *
	 *	f(i,j)后，A[j+1]如果没有出现在A[i,j]中，则无论A[j+1]何时合并都是无关紧要的，因此此时尚未确定A[j+1]的合并次序
	 *					出现在A[i,j]中，最大值可能由不合并产生；这种情况下，A[j+1]的次序未定
	 *					如果出现在A[i,j]中，则可能产生合并，就需要选择一个合并，合并时，需要首先选择一个合并位置r,则j+1的合并次序必须在r+1~j-1之后，因为这些
	 *					元素不合并，j+1不可能产生合并。
	 *					合并时，r合并之后j+1必然合并
	 *					max D[r+1~j-1] < D[r] =  D[j+1] - 1;  D[m~n] = min{D[i]},max{D[i]}  最早合并次序，最晚合并次序
	 *					在保证这个关系的前提下，求最大值
	 *					可能产生的顺序是：
	 *						... {A[r+1~j-1]} ... A[r] A[j+1] ...
	 *
	 *						A[r+1~j-1]是独立计算的，所以可以先计算出来最大值v1
	 *						设 A[r] 在 A[i~r]中的合并次序是m，则取一个m使前面的合并达到最大值即可，如果这个m的最大值已经确定，则整个序列确定
	 *
	 *						设g(i,j,k) 为i~j中k的合并次序为k序列最大值，k=0~j-i分别对应第一个和最后一个合并
	 *
	 *						A[j]的合并次序是k，意味着恰有有k个数在A[j]之前被先合并， 这些数下标都比j小；另外的 j-i-k个数在A[j]之后合并
	 *
	 *
	 *
	 *			如果D[i] < D[j] 且 i > j,则j不可能与i之后的任何元素合并（即它们是独立的）
	 *
	 *
	 *			子集划分： {8, 6, 2, 6, 6, 3, 2, 3, 2, 2};找到两个点，将数组划分为1,2,3，使1 ,3的和2的交集为空
	 *			最大子集即1,3最大的那个子集
	 *			适中子集，即
	 *			最小子集
	 *			 8 .. {}
	 *			 86 , 2,
	 *
	 *
	 *
	 */

	//60 tests , task 26ms
	Solution s;
	int v = s.removeBoxes(boxes);
	std::cout << "max is " << v << std::endl;
}

