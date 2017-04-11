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

int main(int argc,char *argv[])
{
	try{
//		testExactCover();
//		testSudoku();
//		testMissingPositive();
//		testTrappingRainWater();
//		testTrappingRainWaterSimpleDp();
//		testRemoveBoxes();
//		testRemoveBoxes_DLX();
		testFastFood();

//		testFastFood_HOJ(argc,argv);
//		testFastFood_HOJ_INPUT();
	}catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}



	return 0;
}
