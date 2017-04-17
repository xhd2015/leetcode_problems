//============ACCEPTED BY : Leetcode===============
//============TIME COMPLEXITY : O(|s|*|p|)=========
//============SPACE COMPLEXITY : O(|s|*|p|)========
//============DETAILS : 445/445 TESTS PASSED=======
//============BEATS ： 73% CPP SUBMISSIONS============
//============TIME : 9ms ===========================
//============DATE : 2017-04-13 17:47:46============
//============ALGORITHM : DP(No NFA Involved)========

/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月13日
 *      Author: 13774
 */

#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct State{
	T data;
	int type;
};
class Solution {
public:
	enum{ CHAR_SINGLE,CHAR_ANY,NUM_SINGLE,NUM_ANY};
	enum{ STATE_START,STATE_CHAR,STATE_NUM_OR_CHAR,STATE_ERR};
public:
	/**
	 * Successful or not
	 */
	bool initStateStream(const std::string &pattern)
	{
		int n=(int)pattern.size();
		int j=0;//index of last state in stream
		int curState=STATE_CHAR,nextState;
		for(int i=0;i<n;i++)
		{
			char ch=pattern[i];
			switch(curState)
			{
				case STATE_CHAR:/* EXPECT a char*/
					if(ch!='*')
					{
						stateStream.push_back({ch,NUM_SINGLE});
						nextState=STATE_NUM_OR_CHAR;
					}else{
						i--;
						nextState=STATE_ERR;
					}
					break;
				case STATE_NUM_OR_CHAR:
					if(ch=='*')
					{
						stateStream[j].type=NUM_ANY;
						nextState=STATE_CHAR;
					}else{
						i--;
						nextState=STATE_CHAR;
					}
					j++;
					break;
				case STATE_ERR:
					//clear the stream
					return false;
					break;
			}
			curState=nextState;
		}
//		std::cout << "j is "<< j << std::endl;
//		for(int i=0;i<(int)stateStream.size();i++)
//		{
//			std::cout << "<" << stateStream[i].data << ","<<stateStream[i].type<<">"<<std::endl;
//		}
		return true;
	}
	bool f(int i,int j)
	{
//		std::cout << "i="<<i<<" , j="<<j<<std::endl;
		if(i<nstring)
		{
			if(j>=nstate)return false;
			int base=i*nstate + j;
			if(dp[base]==-1)
			{
				if((*ps)[i]==stateStream[j].data || stateStream[j].data=='.')
				{
					if(stateStream[j].type==NUM_ANY)dp[base]=(f(i+1,j) || f(i+1,j+1) || f(i,j+1));
					else						dp[base]=f(i+1,j+1);
				}else if(stateStream[j].type==NUM_ANY)dp[base]=f(i,j+1);
				else dp[base]=false;
			}
			return dp[i*nstate + j];
		}
		if(j>=nstate)return true;
		else if(stateStream[j].type==NUM_ANY)return f(i,j+1);
		else return false;

	}
    bool isMatch(string s, string p) {
    	if(!initStateStream(p))return false;
    	 nstring=(int)s.size();
    	 nstate=(int)stateStream.size();
    	 ps=&s;
    	 dp = new int[nstring * nstate];
    	 for(int i=0;i<nstring * nstate;i++)
    		 dp[i]=-1;
    	 return f(0,0);
    }


    std::vector<State<char>> stateStream;
    int nstate,nstring;
    const std::string *ps;
    int *dp;
};

void testWildcardMatching()
{
//	std::vector<std::pair<std::string,std::string>> testCases={
//			{"aa","a"},//false
//			{"aa","aa"},//true
//			{"aaa","aa"},//false
//			{"aa","a*"},//true
//			{"aa",".*"},//true
//			{"ab",".*"},//true
//			{"aab","c*a*b"},//true
//	};
//	std::pair<std::string,std::string> pair={"aaa","a*a"};
	//result is true

//	std::pair<std::string,std::string> pair={"bbbba",".*a*a"};
	//result is true

	std::pair<std::string,std::string> pair={"b","aaa."};

	Solution s;

	bool matched=s.isMatch(pair.first,pair.second);
	std::cout << "Is matched?"<<matched<< std::endl;
//	for(auto &p:testCases)
//	{
//		Solution s;
//		std::cout << "Is matched?"<<s.isMatch(p.first,p.second)<< std::endl;
//	}
}


