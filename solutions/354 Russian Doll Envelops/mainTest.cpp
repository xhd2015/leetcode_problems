//============ACCEPTED BY : Leetcode===============
//============TIME COMPLEXITY : O(n*log(n))=========
//============SPACE COMPLEXITY : O(n)========
//============DETAILS : 85/85 TESTS PASSED=======
//============BEATS ： 70.77% CPP SUBMISSIONS============
//============TIME : 39ms ===========================
//============DATE : 2017-04-13 22:24:20============
//============ALGORITHM : Longest Increasing Subarray & Binary Search=====

/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月13日
 *      Author: 13774
 */


#include <vector>
#include <iostream>
#include <algorithm>
#include <StringUtils.h>


using namespace std;


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	if(envelopes.size()==0)return 0;
    	std::sort(envelopes.begin(),envelopes.end(),[](const std::pair<int,int> &a,const std::pair<int,int>&b){
    		if(a.first!=b.first)return a.first < b.first;
    		return b.second < a.second;
    	});
    	std::cout << x2::toString(envelopes)<<std::endl;
    	int n=(int)envelopes.size();
    	std::vector<int> maxes;
    	maxes.push_back(0);
    	for(int i=1;i<n;i++)//next is in range of the same
    	{
    		std::pair<int,int> &cur=envelopes[i];
    		int left=0,right=(int)maxes.size();//
    		while(left<right)
    		{
    			int mid=(left+right)/2;
    			if(cur.second < envelopes[maxes[mid]].second ) right=mid;
    			else if(cur.second > envelopes[maxes[mid]].second) left=mid+1;
    			else {right = mid;break;}
    		}
    		if(right == (int)maxes.size())
    		{
    				maxes.push_back(i);
    		}else if(cur.second < envelopes[maxes[right]].second){
    			maxes[right] = i;
    		}
    	}
    	std::cout << x2::toString(maxes) << std::endl;
    	return maxes.size();
    }
};



void testRussianDollEnvelops()
{
	std::vector<std::pair<int,int>> A={{5,4},{6,4},{6,7},{2,3},{2,2},{2,1}};

	Solution s;
	int num=s.maxEnvelopes(A);

	std::cout << "maximum envelops is "<<num<<std::endl;

}
