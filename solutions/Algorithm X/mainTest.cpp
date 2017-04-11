/*
 * mainTest.cpp
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */

#include <UniversalTest.h>
#include <StringUtils.h>
#include "ExactCover.h"
#include "CrossNode.h"
#include "SudokuCrossList.h"

void testExactCover(){
//	int A[6][7]={  //solutions are :[1 3 5]
//			{1,0,0,1,0,0,1},
//			{1,0,0,1,0,0,0},
//			{0,0,0,1,1,0,1},
//			{0,0,1,0,1,1,0},
//			{0,1,1,0,0,1,1},
//			{0,1,0,0,0,0,1},
//	};
	int A[6][7]={
		{1, 1, 0, 1, 1, 0, 1, },
		{0, 0, 1, 0, 0, 1, 0, },
		{0, 0, 0, 1, 1, 0, 1, },
		{0, 1, 0, 0, 1, 1, 0, } ,
		{1, 1, 0, 0, 0, 0, 0, },
		{0, 1, 0, 0, 0, 0, 1, } ,
	};
	std::cout <<toString((int*)A,6,7)<<std::endl;

	CrossList<int> list((int*)A,6,7);

//===========Test the CrossList if it works as excepted.
//	std::cout << list.toString() << std::endl;
//
//	CrossNode<int> *acol=list.head->getNext();
////	acol = (CrossNode<int>*)acol->getSon();
//
//	acol->removeCol();
//	std::cout << "after removing a column" << std::endl;
//	std::cout << list.toString() << std::endl;
//
//	acol->restoreCol();
//	std::cout <<"after restoring a column" << std::endl;
//	std::cout << list.toString() << std::endl;

	std::vector<std::vector<int>> solutions;
	ExactCover ec([&solutions](const std::vector<CrossNode<int>*> &onesolu){
		std::vector<int> tempone;
		for(auto p:onesolu)
			{
				tempone.push_back(p->i);
			}
		solutions.push_back(std::move(tempone));
	});
	ec.solve(list);
	std::cout << "solutions are " << std::endl;
	std::cout << toString(solutions) << std::endl;

	std::cout << "<end>" << std::endl;
}


void testSudoku()
{
//	int A[9][9]={
//			{5, 3, 0, 0, 7, 0, 0,0,0 },
//			{6, 0, 0, 1, 9, 5, 0,0,0 },
//			{0, 9, 8, 0, 0, 0, 0,6,0 },
//			{8, 0, 0, 0, 6, 0, 0,0,3 } ,
//			{4, 0, 0, 8, 0, 3, 0,0,1 },
//			{7, 0, 0, 0, 2, 0, 0,0,6 } ,
//			{0, 6, 0, 0, 0, 0, 2,8,0 } ,
//			{0, 0, 0, 4, 1, 9, 0,0, 5} ,
//			{0, 0, 0, 0, 8, 0, 0,7,9 } ,
//	};
	int A[9][9]={
	{0,0,9,7,4,8,0,0,0},
	{7,0,0,0,0,0,0,0,0},
	{0,2,0,1,0,9,0,0,0},
	{0,0,7,0,0,0,2,4,0},
	{0,6,4,0,1,0,5,9,0},
	{0,9,8,0,0,0,3,0,0},
	{0,0,0,8,0,3,0,2,0},
	{0,0,0,0,0,0,0,0,6},
	{0,0,0,2,7,5,9,0,0},
	};//["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]

//	int A[9][9]={
//			{1,2,3,4,5,6,7,8,9,},
//			{2,3,4,5,6,7,8,9,1,},
//			{3,4,5,6,7,8,9,1,2,},
//			{4,5,6,7,8,9,1,2,3,},
//			{5,6,7,8,9,1,2,3,4,},
//			{6,7,8,9,1,2,3,4,5,},
//			{7,8,9,1,2,3,4,5,6,},
//			{8,9,1,2,3,4,5,6,7,},
//			{9,1,2,3,4,5,6,7,8,},
//	};
	SudokuCrossList slist(A);
	std::cout << slist.toString() << std::endl;
	std::cout << "RAW mode " << std::endl <<
				toString((int*)slist.constrains,SudokuCrossList::C_SIZE,SudokuCrossList::ROWSZ * SudokuCrossList::COLSZ) << std::endl;

	std::vector<std::vector<std::pair<int,int>>> solutions;
	ExactCover ec([&solutions](const std::vector<CrossNode<int>*> &solutionone)
			{
				std::vector<std::pair<int,int>> tempone;
				for(auto it=solutionone.begin(),itend=solutionone.end();it!=itend;it++)
				{
					auto &refit=*it;
					std::cout <<"saving "<<refit->j << std::endl;
					CrossNode<int> *node1=refit,*node2=refit;
					while(node1 && node1->i !=0 )node1=node1->getPrevious();
					while(node2 && node2->i < 81)node2=node2->getNext();
					tempone.push_back({node1->j,node2->j});
				}
				solutions.push_back(std::move(tempone));
			});
	ec.solve(slist);

	std::cout << "solutions are " << std::endl;
	std::cout << toString(solutions) << std::endl;
	std::map<std::pair<char,int>,int> orderedRes;
	for(auto &p:solutions[0])
	{
		int i=p.first / 9,j=p.first%9;
		std::cout << "getting " << p.first << std::endl;
//		std::cout << "<" << (char)(i + 'A') <<"," << j+1 << ">=" << p.second << std::endl;
		orderedRes[{(char)(i+'A'),j+1}]=p.second;
	}
	for(auto &p:orderedRes)
	{
		std::cout << toString(p.first) << "=" << p.second << std::endl;
	}

	std::cout << "<end>" << std::endl;

}
