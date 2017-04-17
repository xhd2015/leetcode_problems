//============BEST ACCEPTED=========
//============ACCEPTED BY : Leetcode=============
//============TIME COMPLEXITY : O(n)===========
//============SPACE COMPLEXITY : O(1)==========
//============DETAILS : 120/120 TESTS PASSED=======
//============BEATS ： 82% CPP SUBMISSIONS=======
//============TIME : 12ms ======================
//============DATE : 2017-04-12 21:27:01=========

//A Problem : submission runs may appear to be slow or fast, depending on the real time machine
//for example,the same procedure
//TIME1 2017-04-12 21:21:54      got  22ms, beats 10%
//TIME2 2017-04-12 21:25:02      got  16ms, beats 30%
//TIME3 2017-04-12 21:25:47      got  13ms, beats 60%
//TIME4 2017-04-12 21:28:45      got  12ms, beats 82%, the best submission I've ever made!!!

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;


class Solution {
public:
	/**
	 * if no integer average,return -1
	 */
	int getMean(vector<int> & machines)
	{
		int thisV=machines[0];
		int diff=0;
		for(int i=1;i<n;i++)
		{
			diff += machines[i] - thisV;
			if(diff % (i+1)==0)
			{
				thisV+=diff/(i+1);
				diff=0;
			}
		}
		if(diff!=0)return -1;
		else return thisV;
	}
    int findMinMoves(vector<int>& machines) {
    	n=(int)machines.size();
    	V = getMean(machines);
    	pA = &machines;
//    	std::cout << "V is "<< V << std::endl;
    	if(V==-1)return -1;
    	int steps=fastf();
    	return steps;
    }

    int fastf()
    {
    	int curMax=0;
    	int a=0;
    	for(int i=0;i<n;i++)
    	{
    		int Ai=(*pA)[i];
    		int diff=a + V -Ai;
    		if(curMax < a)curMax = a;
    		if(curMax < -a) curMax = -a;
    		if(curMax < Ai - V) curMax = Ai -V;
    		a=diff;
    	}
    	return curMax;
    }
    int f(int i,int a) ////    	return std::max(a,-a,f(i+1,diff),Ai - V);
    {
    	if(i==n)return 0;
    	int Ai=(*pA)[i];
    	int diff=a + V - Ai;
    	if(a==0)return f(i+1,diff); // max { a, f(i+1,diff) }
    	else if(a < 0) return std::max(-a,f(i+1,diff)); // max { -a, f(i+1,diff) }
    	else if(Ai<a) return std::max ( f(i+1,diff),a); // max{ -a,...,...}   diff 序列 max{a,f(i+1,diff),-a,Ai-V}
    	else if(diff > 0) return std::max(a,f(i+1,diff));
    	else if(diff <= 0) return std::max(Ai-V,f(i+1,diff));
    	else return 0;

    }
    std::vector<int> *pA;
    int V;
    int n;
};

void testSuperWashingMachine()
{
//	std::vector<int> A={7,9,0,2,14,4};// V =36/6=6
	//result is 8

//	std::vector<int> A={1,2,3,4,5,6,7};
	//result is 6

//	std::vector<int> A={0,0,10,0,0,0,10,0,0,0};
	//result is 8

//	std::vector<int> A={0,0,11,0,11,0,0,2};
	//result is 8

	std::vector<int> A={55,26,51,72,70,85,45,51,2,23};
	//result is 71

//	std::vector<int> A={0,2,0};
	//result is -1

//	std::vector<int> A={0,3,0};
	//result is 2

//	std::vector<int> A={1,0,5};
	//result is 3

	Solution s;
	int min=s.findMinMoves(A);
	std::cout << "minimum steps is " << min << std::endl;
}
