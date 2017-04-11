/*
 * StringUtils.cpp
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */


#include <StringUtils.h>
#include <numeric>
#include <iostream>
namespace x2{
	std::string toString(int x)
	{
		return std::to_string(x);
	}
	std::string toString(char ch)
	{
		std::string s;
		s.push_back(ch);
		return s;
	}
	std::string toString(bool b)
	{
		return b?"True":"False";
	}
	std::string toString(int *arr,int sz)
	{
		return std::accumulate(arr,arr+sz,std::string("["),sumVecString<int>)+"]";
	}
	std::string toString(int *arr,int rowsz,int colsz)
	{
		std::string s="{\n";
		for(int i=0;i<rowsz;i++)
		{
			s+=std::string("\t")+toString(arr + i*colsz, colsz) + "\n";
		}
		s+="}";
		return s;
	}
}

