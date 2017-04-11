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
		int n = (int) height.size();
		int inci=0,decj=n-1;
		int maxinc=0,maxdec=0;
		while(inci < decj)
		{
//
			//select one direction
			if(maxinc > maxdec) //use decj
			{
				while(decj > inci && height[decj] <= maxdec) {
					sum+=maxdec - height[decj--];
				}
				if(decj == inci)break;
				maxdec = height[decj];
			}else{
				while(inci < decj && height[inci] <= maxinc){
					sum+=maxinc - height[inci++];
				}
				if(decj == inci)break;
				maxinc = height[inci];
			}
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

//	std::vector<int> height={7,6,3,2,1,4,4,5,1};
	 //result is 11

	std::vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
	//result is 6

	 Solution s;
	 int sum=s.trap(height);
	std::cout << "sum is " << sum << std::endl;

}

