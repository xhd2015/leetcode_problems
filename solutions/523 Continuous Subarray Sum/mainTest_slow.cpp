//============ACCEPTED BY : Leetcode=============
//============MEMORY : UNKNOWN K=================
//============TIME COMPLEXITY : O(n^2)===========
//============SPACE COMPLEXITY : O(n^2)==========
//============DETAILS : 75/75 TESTS PASSED=======
//============BEATS ： 4.88% CPP SUBMISSIONS=======
//============TIME : 115ms ======================
//============DATE : 2017-04-11 15:27:36=========

/*
 * mainTest_slow.cpp
 *
 *  Created on: 2017年4月11日
 *      Author: 13774
 */


#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //k may be less or equal to 0.  if k==0 scan for 0 0 in the list
        //if k!=0, k=|k|,make it positive
        bool hasthat=false;
        const int isz=(int)nums.size();
        if(k==0)
        {
            for(int i=0;i<isz;i++)
            {
                if(nums[i]==0 )
                    if(i+1 < isz && nums[i+1]==0)return true;
                    else i+=2;
            }
            return false;
        }
        if(k<0)k=-k;
        int *f=new int[isz * isz];
        for(int i=0;i<isz-1;i++)
        {
            f[i*isz + i+1] = (nums[i]+nums[i+1])%k;
            if(f[i*isz + i+1]==0)return true;
            for(int j=i+2;j<isz;j++)
            {
                int index=i*isz + j;
                f[index]=(f[index-1] + nums[j])%k;
                if(f[index]==0)return true;
            }
        }
        delete [] f;
        return false;
    }
};

void testContinuousSubarraySum_SLOW()
{

}
