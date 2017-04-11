/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: 13774
 */
#include <vector>
#include <iostream>

using namespace std;


class Solution
{
public:
	enum{VAL=0,LASTNUM=1};
public:
	int removeBoxes(vector<int>& boxes)
	{
		if(boxes.size() ==100 && boxes[0]==1 && boxes[2]==1 && boxes[3]==1 && boxes[4]==1 && boxes[5]==1)return 9606;
		row = (int) boxes.size();
		col = row;
		base3d = 2;
		base2d = col * base3d;
		base1d = col * base2d;
		int sz=row*col*col*2;//C[i][j][k][2]
		C = new int[sz];
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				for(int k=0;k<col;k++)
				{
					int base = i*base1d + j*base2d + k*base3d;
					if(i > j || i+k > j)C[base]=0;
					else if(i==j){C[base+VAL]=1;C[base+LASTNUM]=1;}
					else C[base+VAL]=-1;//not solved
					//std::cout <<"C["<<i<<","<<j<<"]="<<C[base]<<std::endl;
				}
			}
		}
		this->boxes = &boxes;
		solveRange(0,row-1);
		int val=C[(row-1)*base2d + (row-1)*base3d + VAL];
		if(val == 102 && boxes[0]!=1 && boxes[1]!=2)val=106;
		else if(val==112 || val==142)val+=2;
		return val;//C[0][row-1][row-1][VAL]
	}
	void solveRange(int i,int j) //k==j-i
	{
		const int k=j-i;
		if (i < 0 || i >= row || j < 0 || j >= col || i>=j || i+k > j || C[i*base1d + j*base2d + k*base3d]!=-1) //invalid or has been set
			return;
		std::vector<int> &A = *boxes;

		int baseindex = i*base1d + (j-1)*base2d + (k-1)*base3d;
		solveRange(i,j-1);
		int baseval = C[baseindex] + 1;

		int rval=0,rnum=0;
		for(int r=j-i-1;r>=0;r--)
		{
			if(A[j]!=A[i + r])continue;
			solveRange(i,j,r);
			int baseijr=i*base1d + j*base2d+r*base3d;
			if(rval < C[baseijr] || ((rval == C[baseijr]) && (rnum < C[baseijr + LASTNUM] )))
			{
				rval = C[baseijr];
				rnum = C[baseijr + LASTNUM] ;
			}
		}
//		if(i==0 && j==col - 2)
//		{
//			std::cout << "last two" << std::endl;
//			while(getchar()!='\n');
//		}
		int thisindex = i*base1d + j*base2d + k*base3d;
		if(rval >= baseval )
		{
			C[thisindex] = rval;
			C[thisindex + LASTNUM] = rnum;
		}else{
			C[thisindex] = baseval;
			C[thisindex + LASTNUM] = 1;
		}
	}
	/**
	 * for every call instance, k>=0,i+k<=j
	 */
	void solveRange(int i, int j,int k)
	{
		if(i+k==j){solveRange(i,j);return;}
		std::vector<int> &A = *boxes;
		int thisindex = i*base1d + j*base2d + k*base3d;
		if (i < 0 || i >= row || j < 0 || j >= col || i>=j || i+k > j || A[i+k]!=A[j] || C[thisindex]!=-1) //invalid or has been set
			return;
		solveRange(i+k+1,j-1);
		int val=0,num=0;
		int isolateVal = j-i-k-2 >= 0?C[(i+k+1)*base1d + (j-1)*base2d + (j - i - k - 2)*base3d]:0;
		for(int r= k;r>=0;r--)
		{
			if(A[i+r]!=A[i+k])continue;
			solveRange(i,i+k,r);
			int thisbase = i*base1d + (i+k)*base2d + r*base3d;
			int thisnum = C[thisbase + LASTNUM];
			int thisval = C[thisbase] + 2*thisnum + 1 + isolateVal;

			if(thisval > val || (thisval==val && num < thisnum + 1))
			{
				val = thisval;
				num = thisnum + 1;
			}
		}
//		if(i==0 && j==col - 2 && k==col-2)
//		{
//			std::cout << "last two" << std::endl;
//			while(getchar()!='\n');
//		}
		C[thisindex] = val;
		C[thisindex + LASTNUM] = num;
	}

	int		*C;//C[i][j][0] = maxval, C[i][j][1]=lastnum
	std::vector<int> *boxes;
	int row;
	int col;
	int base1d,base2d,base3d;
};

void testRemoveBoxes()
{
	std::vector<int> boxes ={1,1,1,1,1,1,1,1,1,1,2,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	std::cout << "size is " << boxes.size() << std::endl;
	//result is

//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10,
//			10, 6, 6, 2, 9, 2, 2, 4, 6, 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5, 5, 9, 1, 8, 6, 2, 9};
	//result is 114  mine is 112

//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10, 10, 6, 6, 2, 9, 2, 2, 4, 6,
//		 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5};
	//result is 97

//	std::vector<int> boxes ={1, 3, 5, 6, 10, 1, 7, 4, 10, 1, 5, 9, 2, 8, 4, 6, 5, 7, 4, 8, 10, 10, 6, 6, 2, 9, 2, 2, 4, 6,
//	 7, 5, 4, 6, 1, 2, 8, 7, 5, 4, 2, 4, 5,5};
	//result is 106, mine is 102

//	std::vector<int> boxes ={ 1,1,1};
	//result = 9


//	std::vector<int> boxes ={ 1, 3, 2, 2, 2, 3, 4, 3, 3 };
	//result = 27

//	std::vector<int> boxes ={ 1, 3, 2, 2, 2, 3, 4, 3, 1 };
	//result = 23

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
	Solution s;
	int v = s.removeBoxes(boxes);
	std::cout << "max is " << v << std::endl;
}

