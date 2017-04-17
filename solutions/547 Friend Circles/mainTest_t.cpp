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

using namespace std;
class FindUnionSet{
public:
	int *prev;
	int n;
	int setnum;
	std::vector<std::vector<int>> &M;

	FindUnionSet(std::vector<std::vector<int>> &M):
		n((int)M.size()),setnum(n),M(M)
	{
		prev=new int[n];
		for(int i=0;i<n;i++)
			prev[i]=i;
	}
	~FindUnionSet()
	{
		delete [] prev;
		n=0;
		prev=NULL;
		setnum=0;
	}
	int find(int i)
	{
		while(prev[i]!=i)i=prev[i];
		return i;
	}
	void unions(int i,int j)//to i
	{
		int fi=find(i),fj=find(j);
		if(fi!=fj)
		{
			prev[fj]=fi;
			setnum--;
		}
	}
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
    	FindUnionSet fset(M);
    	for(int i=0;i<fset.n;i++)
    	{
    		for(int j=i+1;j<fset.n;j++)
    		{
    			if(M[i][j]==1)
    				fset.unions(i, j);
    		}
    	}
    	std::cout << x2::toString(fset.prev,fset.n) << std::endl;
    	return fset.setnum;
    }
};



void testFriendCircles()
{

	Solution s;

//	std::vector<std::vector<int>> M={
//			{1,1,0},
//			{1,1,1},
//			 {0,1,1},
//
//	};
	//result is 3

//	std::vector<std::vector<int>> M={
//			{1,1,0},
//			{1,1,0},
//			{0,0,1},
//	};
	//result is 2

	std::vector<std::vector<int>> M={
			{1,0,0,1},
			{0,1,1,0},
			{0,1,1,1},//0 3, 1 2, 2 3
			{1,0,1,1},
	};
	//result is 1

	int res=s.findCircleNum(M);;

	std::cout << "result is "<<res << std::endl;

}
