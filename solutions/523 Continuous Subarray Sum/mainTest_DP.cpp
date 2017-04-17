//============ACCEPTED BY : Leetcode=============
//============MEMORY : UNKNOWN K=================
//============TIME COMPLEXITY : O(n)===========
//============SPACE COMPLEXITY : O(k)==========
//============DETAILS : 75/75 TESTS PASSED=======
//============BEATS ： 67% CPP SUBMISSIONS=======
//============TIME : 29ms ======================
//============DATE : 2017-04-12 08:18:34=========

/*
 * mainTest_DP.cpp
 *
 *  Created on: 2017年4月11日
 *      Author: 13774
 */



#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int isz=(int)nums.size();
        if(k==0)
        {
            for(int i=0;i<isz;i++)
                if(nums[i]==0)
                {
                    if(i+1 < isz && nums[i+1]==0)return true;
                    else i+=1;
                }
            return false;
        }else{
            if(k<0)k=-k;
            std::map<int,int> summed;
            summed[0]=-1;
            int curSum=0;
            for(int i=0;i<isz;i++)
            {
                curSum=(curSum + nums[i])%k;
                if(summed.find(curSum)!=summed.end())
                    {
                        if( i - summed[curSum] > 1)return true;
                    }
                else summed[curSum]=i;
            };
            return false;
        }
    }
};

void testContinuousSubarraySum_DP()
{
	std::vector<int> A={1,2,0,0,5,6,7,8,9};
	for(int i=10;i<10000;i++)
		A[i]=i+1;
	int k=1000000;
	Solution s;
	bool b=s.checkSubarraySum(A, k);
	std::cout << "has = " << b << std::endl;
}

