/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月13日
 *      Author: 13774
 */




#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
	int getMaxIncLength(std::vector<int> &arr)
	{
		std::cout << "here"<<std::endl;
		int n=(int)arr.size();
		if(n==0)return 0;
		std::vector<int> subarr;
		subarr.push_back(arr[0]);
		for(int i=1;i<n;i++)
		{
			for(int i=0;i<subarr.size();i++)
				std::cout<<subarr[i]<<", ";
			std::cout << std::endl;
			int e=arr[i];
			int left=0,right=(int)subarr.size();
			/**
			 * f(i,j)  i<=j  i==j时返回i
			 *   mid=(i+j)/2
			 *   if   A[mid]==e return mid
			 *   else if A[mid]<e left=mid+1
			 *   else if A[mid]>e right=e
			 *
			 *  return result
			 *    if found,it will find at random position of that element, that directs i<j
			 *    if not found,it will locate left the same with right,kept that A[left-1]<e
			 */
			while(left < right)//f(i,j) i==j-1 return i
			{
				int mid=(left+right)/2;
				if(e < subarr[mid])right=mid;
				else if( e > subarr[mid]) left=mid+1;
				else { right=mid;break;}
			}
			if(right==(int)subarr.size())
				subarr.push_back(e);
			else if(subarr[right]==e)
			{
				while(right<(int)subarr.size() && subarr[right]==e)right++;
				if(right==(int)subarr.size())subarr.push_back(e);
				else	subarr[right]=e;
			}else{
				subarr[right]=e;
			}
		}
		for(int i=0;i<subarr.size();i++)
				std::cout<<subarr[i]<<", ";
		return (int)subarr.size();
	}
};


void testLongestIncreasingSubarray()
{
	std::vector<int> A={0,1,2,1,2,3,3,3,2,2,2,2,4,1};//如果是添加，一定是在最末尾，如果是替换，则对后面的无影响

//	std::vector<int> B={1,3,5,7};
//	int left=0,right=(int)B.size();
//	int e=4;
//	while(left < right)//right is at insert position
//	{
//		int mid=(left+right)/2;
//		if(e < B[mid])right=mid;
//		else if( e > B[mid]) left=mid+1;
//		else break;//equal
//	}

	Solution s;
	int sum=s.getMaxIncLength(A);
	std::cout << "LIS is "<<sum<<std::endl;
}
