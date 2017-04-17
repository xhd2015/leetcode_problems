//============ACCEPTED BY : Leetcode===============
//============TIME COMPLEXITY : O()=========
//============SPACE COMPLEXITY : O()========
//============DETAILS : / TESTS PASSED=======
//============BEATS ： % CPP SUBMISSIONS============
//============TIME : ms ===========================
//============DATE : ============
//============ALGORITHM : =====


/**
 * it is however in its essence a brute force method.
 */

#include <vector>
#include <string>
#include <StringUtils.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
//2^10  == 1024个子串,最多50个，即至多51200个子串需要比较
//将所有的子串形成，然后按长度排序；从最长到最短，直到发现第一个串计数为1的串
//优化方案，因为比较的时候都需要按照长度来比较，所以每一步实际上可以依照长度来进行
// getAllSubs(const std::string& s,int len) 获取s的所有长度为len的子串(0,...)
// 对获取的子串进行排序
//  findFirstLongestUnique
    int findLUSlength(vector<string>& strs) {
        int n=(int)strs.size();
        std::vector<std::vector<std::vector<string>>> subs(n);
        for(int i=0;i<n;i++)
        {
        	int m=(int)strs[i].size();
        	subs[i].resize(m+1);
        	subs[i][m].push_back(strs[i]);
//        	std::cout << "m is "<<x2::toString(subs[i][m]) << std::endl;

        }
        for(int j=10;j>0;j--)
        {
        	for(int i=0;i<n;i++)
        	{
        		if(j + 1< (int)subs[i].size())
        		{
            		for(auto &str:subs[i][j+1])
    				{
    	//        			std::cout << "cur string is "<<str<<std::endl;
    					for(int k=0;k<(int)str.size();k++)
    					{
    						subs[i][j].push_back(str.substr(0, k)+str.substr(k+1,str.size()));
    					}
    				}
        		}

        	}
        	if(hasUnique(subs,j))return j;
        	for(int i=0;i<n;i++)
        	 {
        	      if(j + 1< (int)subs[i].size())subs[i][j+1].clear();
        	 }
        }
        return -1;
    }
	bool hasUnique(const  std::vector<std::vector<std::vector<string>>>& subs,int len)
	{
		std::map<std::string,int> count;
		for(int i=0;i<(int)subs.size();i++)
		{
			if(len < (int)subs[i].size())
			{
				for(auto &str:subs[i][len])
				{
					if(count.find(str)==count.end())count[str]=1;
					else count[str]++;
				}
			}
		}
		for(auto &p:count)
		{
			if(p.second==1)return true;
		}
		return false;
	}

  //subs[i][j] = strs[i]'s substr whose length is j
};

void testLongestUncommonSubsequenceII()
{

	Solution s;
	std::vector<std::string> strs={"abc","abc","adc","adc","ae","ab","a"};
	int res=s.findLUSlength(strs);
	std::cout << "result is "<<res << std::endl;

}

