/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月7日
 *      Author: 13774
 */




#include <vector>
#include <iostream>
#include <StringUtils.h>

using namespace std;
using namespace x2;

class Solution {
public:
	/**
	 * return the starts of second,and if the first contains element
	 */
	std::pair<int,bool> partition(std::vector<int>& A,int i,int j,int element)//divide into 2 parts,  <=element & >element,if the first parts contains element,return 1
	{
		if(i>=j) return {i,false};
		int upi=i,downj=j-1;
		int pos;
		bool found=false;
		while(true)//保证 downj >= upi恒成立
		{
			while(downj > upi && A[upi]<=element)
			{
//				std::cout << "upi " << upi << "found element?" << (A[upi]==element) << std::endl;
				if(A[upi]==element)found=true;
				upi++;
			}
			while(downj > upi && A[downj] > element)downj--;
			if(A[downj]==element)found=true;
			if(upi == downj ){
				if(A[upi]>element)pos=upi;
				else	pos=upi+1;
				break;
			}
			int swap=A[downj];
			A[downj]=A[upi];
			A[upi]=swap;
			upi++;
			if(upi<downj)downj--;
		}
		return {pos,found};
	}
    int firstMissingPositive(vector<int>& nums) {
    	int element=1;
    	auto p=partition(nums, 0, nums.size(), element);
    	while(p.second)
    	{
    		p=partition(nums, p.first, nums.size(), ++element);
    	}
    	return element;
    }

};

void testMissingPositive()
{
//	int B[]={3,4,-1,1};
//	int bsize=sizeof(B)/sizeof(B[0]);
	vector<int> A={3,4,-1,1,2,6,5,9,10,56,4};

	Solution s;
	int element=1;
	auto p=s.partition(A, 0, A.size(), element);

//	std::cout <<
	while(p.second)
	{
		std::cout << toString(A) << std::endl;
		std::cout << "last found is " << toString(p) << "(val = "<< A[p.first]<<")"<< std::endl;
		element++;
		p=s.partition(A, p.first, A.size(), element);
	}
	std::cout << "first missing " << element << std::endl;
//	auto p=s.partition(B, 0, bsize,2);
//	std::cout << toString(p) << std::endl;
//	std::cout << toString(B,bsize) << std::endl;

//	std::cout << s.firstMissingPositive(A) << std::endl;
}

