//============ACCEPTED BY : Leetcode===============
//============TIME COMPLEXITY : O(n^2)=========
//============SPACE COMPLEXITY : O(n)==============
//============DETAILS : 36/36 TESTS PASSED==========
//============BEATS ： 74.63% CPP SUBMISSIONS==========
//============TIME : 33ms ===========================
//============DATE : 2017-04-14 00:15:25============
//============ADVANCE : may use pruning to utilise========
//============TECHNIQUE : use next to record a list====

/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月13日
 *      Author: 13774
 */

#include <iostream>
#include <vector>
#include <StringUtils.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int n=(int)nums.size();
    	std::vector<int> sol;
    	if(n==0)return sol;
    	std::sort(nums.begin(), nums.end());

    	std::vector<int> dp(n,1);
    	std::vector<int> next(n,-1);

    	int maxid=0,maxdp=0;
    	for(int i=n;i>=0;i--)
    		for(int j=i+1;j<n;j++)
    		{
    			if(nums[j]%nums[i]==0 && dp[i]<dp[j]+1)
    			{
    				dp[i]=dp[j]+1;
    				next[i]=j;
    				if(maxdp < dp[i])
    				{
    					maxdp=dp[i];
    					maxid=i;
    				}
    			}
    		}

    	int i=maxid;
    	while(i!=-1)
    	{
    		sol.push_back(nums[i]);
    		i=next[i];
    	}
    	return sol;
    }
};

void testLongestDivisiableSubset()
{
	Solution s;
	std::vector<int> nums={1,2,3};
	std::vector<int> sol=s.largestDivisibleSubset(nums);
	std::cout << "maximum subset is "<<x2::toString(sol)<<std::endl;

}

