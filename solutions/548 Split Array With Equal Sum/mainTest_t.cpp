//============ACCEPTED BY : Leetcode===============
//============TIME COMPLEXITY : O()=========
//============SPACE COMPLEXITY : O()========
//============DETAILS : / TESTS PASSED=======
//============BEATS ： % CPP SUBMISSIONS============
//============TIME : ms ===========================
//============DATE : ============
//============ALGORITHM : =====

#include <vector>
#include <string>
#include <StringUtils.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool findTripleDivide(vector<int> &num) {
    	int n=(int)num.size();
    	if(n<7)return false;//0 0  0  0 0 0 0
    	int sum[n]={0};
    	sum[0]=num[0];
    	for(int i=1;i<n;i++)
    	{
    		sum[i]=sum[i-1]+num[i];
//    		std::cout << "sum i is "<<sum[i]<<std::endl;
    	}
    	std::map<int,std::set<std::pair<int,int>>> info;
    	for(int i=0;i<n;i++)
    	{
    		for(int j=i;j<n;j++)
    		{

    			int thisum=sum[j]-(i==0?0:sum[i-1]);
    			auto it=info.find(thisum);
    			if(it!=info.end())
    			{
    				it->second.insert({i,j});
    			}else{
    				info.insert({thisum,{
    					{i,j}}
    				});
    			}
    		}
    	}
    	for(auto &p:info)
    	{
//    		std::cout << "sum is "<<p.first<<std::endl;
    		if(p.second.size()<4)continue;
    		int num=0;
    		int i=0;//next expected start
    		for(auto &pij:p.second)
    		{

    			if(pij.first==i)
    			{

    				std::cout << i << std::endl;
    				i=pij.second+2;
    				num++;
    			}else if(pij.first > i)
    			{
    				break;//not possible
    			}

    			if(num==4)
    			{
    				if(i==n+1)return true;
    				else break;
    			}
    		}
    	}
    	return false;
    }

};


void testSplitArrayWithEqualSum()
{
	std::vector<int> vec={1,2,1,2,1,2,1};
	Solution s;
	bool hasdivide=s.findTripleDivide(vec);

	std::cout << "Find Triple? "<< hasdivide<< std::endl;

}
