/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月7日
 *      Author: 13774
 */


#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int sum = 0;
		int i = 0;
		int n = (int) height.size();
		std::stack<int> st;

		while (i < n)
		{
			int subsum = 0;
			st.push(i);
			i++;
			while (i < n && height[i] <= height[i - 1])
			{
				st.push(i);
				i++;
			}
			//=========try to empty this stack,get the subsum
			for (; i < n && !st.empty(); i++)
			{
				if (height[i] < height[st.top()])
					continue;

				//===========get the first bigger number in stack comparing with current number
				int lastNum;
				int popn = 0;
				while (!st.empty() && height[st.top()] <= height[i]) //bigger index first
				{
					lastNum = st.top();
					st.pop();
					popn++;
				}

				//=========now the stack is poped,calculate [lastNum,i] to thissum
				int thissum = 0;
				if (i - lastNum >= 2)
				{
					for (int j = lastNum + 1; j < i; j++)
						thissum += height[j];
					thissum = (i - lastNum - 1) * height[lastNum] - thissum;
				}

				//=========if pop at top, means it will make pair continouesly,use accumulate on subsum
				//=========else it is at lower position to upper position,then, reset subsum
				if (popn == 1)
					subsum += thissum;
				else
					subsum = thissum;
				if (st.empty())
				{
					break;
				}
				else
				{
					st.push(i);
				}
			}

			//========add the subsum to the whole sum
			sum += subsum;

			//=========i stops at the first number that terminates the stack process
			if (i == n)
				break;
		}
		return sum;
	}
};


void testTrappingRainWater()
{
//	 std::vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
	 //result is 6

//	 std::vector<int> height={4,2,3};
	 //result is 1

	std::vector<int> height={7,6,3,2,1,4,4,5,1};
	 //result is 11

	 Solution s;
	 int sum=s.trap(height);
	std::cout << "sum is " << sum << std::endl;

}

int f(std::vector<int> &height,int i,int j,std::vector<std::vector<int>> &dp)
{
	if(dp[i][j]!=-1)return dp[i][j];
	if(j - i <= 1)dp[i][j]=0;
	else{
		int max=-1;
		for(int m=i+2;m<j;m++)
		{
			for(int k=i+1;k<m;k++)
			{
				int tempsum=f(height,i,k,dp) + f(height,k,m,dp) + f(height,m,j,dp);
				if(max < tempsum)
					max=tempsum;
			}
		}
		dp[i][j]=max;
	}
	return dp[i][j];
}

void testTrappingRainWaterSimpleDp()
{
//	 std::vector<int> height={4,2,3};
	 	 std::vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
	 std::vector<std::vector<int>> dp(height.size());
	 for(auto &vec:dp)
	 {
		 vec.resize(height.size());
		 for(auto &i:vec)
		 {
			 i=-1;
		 }
	 }
	 int max=f(height,0,height.size(),dp);
	 std::cout << "trapping is " << max << std::endl;

}
