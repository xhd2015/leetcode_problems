/*
 * Solution.cpp
 *
 *  Created on: 2017?3?26?
 *      Author: 13774
 */

#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <exception>

using namespace std;
class Solution {
public:
	/**
	 * 对字符串进行z字形排列，返回新的字符串
	 *
	 * 算法： 如果有
	 *
	 */
    string convert(string s, int numRows) {
    	if(numRows<2)return s;
    	int xrow=0,istr=0,strsz=(int)s.size(),dir=1/*1 down,-1 up*/;
    	std::vector<std::vector<char>> pos(numRows);
    	for(;istr<strsz;istr++)
    	{
    		pos[xrow].push_back(s[istr]);
    		xrow+=dir;
    		if(xrow>=0 && xrow<numRows)continue;
    		dir = -dir;
    		if(xrow==numRows)			xrow-=2;
    		else if(xrow==-1)			xrow+=2;
    	}
    	std::string news;
    	news.reserve(strsz);
    	for(auto &v:pos)
    		for(char ch:v)if(ch)news.push_back(ch);

    	return news;

    }

};

int main_deprecated()
{
	try{

	Solution s;
	std::string news= s.convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers."
			,3);//PAHNAPLSIIGYIR
	std::cout << news << std::endl;
	}catch(std::exception & e){
			std::cout << e.what() << std::endl;
	}
	return 0;
}
