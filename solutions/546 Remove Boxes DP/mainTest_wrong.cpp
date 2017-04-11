/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: 13774
 */
#include <vector>
#include <iostream>

using namespace std;
struct SolutionType
{
	SolutionType(int val = -1,  int lastnum = -1) :
			val(val), lastnum(lastnum)
	{
	}
	int val;
	int lastnum;
};

class Solution
{
public:
	enum{MAX_NUM = 100};
public:
	int removeBoxes(vector<int>& boxes)
	{
		row = (int) boxes.size();
		col = row;
		int sz=row*col*col;
		C = new SolutionType[sz];
		for(int i=0;i<sz;i++)
		{
			C[i].val = -1;
		}
		this->boxes = &boxes;
		int maxk=solveRangeMax(0,row - 1);

		return C[(row-1)*col + maxk].val;
	}
	int solveRangeMax(int i,int j)
	{
		int base = i * col * col + j * col;
		int maxk=0;
		for(int k=0;k<=j-i;k++)
		{
			solveRange(i,j,k);
			if(C[base].val > C[base + maxk].val)maxk=k;
		}
		return maxk;
	}
	/**
	 * for every call instance, k>=0,i+k<=j
	 */
	void solveRange(int i, int j,int k)
	{
		if (i < 0 || i >= row || j < 0 || j >= col || i > j || k<0)
			return;
		std::vector<int> &A = *boxes;
//		if(i+k > j)std::cout << "k exceeds " << std::endl;
		std::cout << "<i,j,k>=" << i << "," << j << "," << (i+k)<< std::endl;
		int index = i * col *col + j*col + k;
		if (C[index].val == -1)
		{
			int indexlow=i*col*col + (j-1)*col + k;
			if (j == i)
			{
				C[index].val = 1;
				C[index].lastnum = 1;
			}
			else if(i+k < j)
			{
				solveRange(i,j-1,k);
				C[index].val = C[indexlow].val + 1;
				C[index].lastnum = C[indexlow].lastnum;

				std::cout << "<LESS> at " << i << ", " << j<<","<<(i+k) <<" ";
				std::cout << "calls for " << i << "," << j-1<<","<<(i+k) <<std::endl;
				std::cout << "get value is <" << C[indexlow].val <<","<<C[indexlow].lastnum << ">"<< std::endl;
			}else{// i+k = j
				//no merge
				int lowi=solveRangeMax(i,j-1);

				int lowindex = i*col*col + (j-1)*col + lowi;
				int maxval = C[lowindex].val + 1;

				std::cout << "<END> at " << i << ", " << j<<","<<(i+k) <<" ";
				std::cout << "calls for max" << i << "," << j-1<<","<< "*"<<std::endl;
				std::cout << "get value is <" << C[lowindex].val <<","<<C[lowindex].lastnum << ">"<< std::endl;
				int divi=-1;
				for(int r=j-1;r>=i;r--)
				{
					if(A[r]!=A[j])continue;
					int v1=0,v2=0;
					int indexv1=i*col*col + (r-1)*col + r-1-i;
					if(i <= r -1)
					{
						solveRange(i,r - 1,r - 1 -i);

						std::cout << "<MERGE 1> at " << i << ", " << j<<","<<(i+k) <<" ";
						std::cout << "calls for " << i << "," << r-1<<","<<(r-1) <<std::endl;
						std::cout << "get value is <" << C[indexv1].val <<","<<C[indexv1].lastnum << ">"<< std::endl;
						v1 = C[indexv1].val + 2*C[indexv1].lastnum + 1;
					}
					if(r <= j -1 )
					{
						int maxsubi=r*col*col + (j-1)*col + solveRangeMax(r,j-1);
						v2 = C[maxsubi].val;
						std::cout << "<MERGE 2> at " << i << ", " << j<<","<<(i+k) <<" ";
						std::cout << "calls for max " << i << "," << j-1<<","<< "*" <<std::endl;
						std::cout << "get value is <" << C[maxsubi].val <<","<<C[maxsubi].lastnum << ">"<< std::endl;
					}
					int tempv=v1+v2;
					if(maxval < tempv)
					{
						maxval = tempv;
						divi = r;
					}else if(maxval == tempv){//select one whose number is bigger
						if(divi!=-1)
						{
							int indexdivi = i*col*col + (divi-1)*col + divi - 1 -i;
							if(C[indexv1].lastnum < C[indexdivi].lastnum)
								divi = r;
						}else{
							divi = r;
						}
					}
				}
				C[index].val = maxval;
				std::cout << "val=" << maxval << " ";
				if(divi==-1) // normal adding
				{
					std::cout << i << "," << j << "," << (i+k) << " normal update" << std::endl;
					C[index].lastnum = 1;
				}else{
					std::cout << i << "," << j << "," << (i+k) << " merge at "<< divi << std::endl;
					int indexdivi = i*col*col + (divi-1)*col + divi - 1 -i;
					C[index].lastnum = C[indexdivi].lastnum;
				}


			}
		}
	}

	SolutionType *C;
//	int		*D;
	std::vector<int> *boxes;
	int row;
	int col;
};

void testRemoveBoxes()
{
//	std::vector<int> boxes ={ 1, 3, 2, 2, 2, 3, 4, 3, 1 };
	//result = 23

	//i,j中以k结尾时，i~k-1 k+1~j是相互独立的，并且肯定是 k+1~j先消除，然后 i~k-1再消除，然后再消除k是最大值
	//但是存在一个问题，i~k-1能否与k相互合并从而得到一个更大的值？取决于i~k-1的最后一个数是否与k的数相同
	std::vector<int> boxes ={8, 6, 2, 6, 6, 3, 2, 3, 2, 2};//可以先预处理，将重复元素合并
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
	 *
	 */
	Solution s;
	int v = s.removeBoxes(boxes);
	std::cout << "max is " << v << std::endl;
}

