/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */

#include <exception>
#include <iostream>

extern void testExactCover();
extern void testSudoku();
extern void testMissingPositive();
extern void testTrappingRainWater();
extern void testRemoveBoxes();
extern void testFastFood();
extern void testFastFood_HOJ(int argc,char *argv[]);
extern void testFastFood_HOJ_INPUT();
//extern void testRemoveBoxes_DLX();
extern void testContinuousSubarraySum_SLOW();
extern void testContinuousSubarraySum_DP();
extern void testSuperWashingMachine();
extern void testWildcardMatching();
extern void testRegularExpressionMatching();
extern void testLongestIncreasingSubarray();
extern void testRussianDollEnvelops();
extern void testLongestDivisiableSubset();
extern void testLongestDivisiableSubset_tree();
extern void testLongestUncommonSubsequenceI();
extern void testLongestUncommonSubsequenceII();
extern void testFriendCircles();
extern void testSplitArrayWithEqualSum();

int main(int argc,char *argv[])
{
	try{
		testSplitArrayWithEqualSum();
//		testFriendCircles();
//		testLongestUncommonSubsequenceII();
//		testExactCover();
//		testSudoku();
//		testMissingPositive();
//		testTrappingRainWater();
//		testTrappingRainWaterSimpleDp();
//		testRemoveBoxes();
//		testRemoveBoxes_DLX();
//		testFastFood();

//		testFastFood_HOJ(argc,argv);
//		testFastFood_HOJ_INPUT();

//		testContinuousSubarraySum_DP();

//		testSuperWashingMachine();

//		testRegularExpressionMatching();

//		testLongestIncreasingSubarray();
//		testRussianDollEnvelops();

//		testLongestDivisiableSubset();

//		testLongestDivisiableSubset_tree();
	}catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}



	return 0;
}
