/*
 * ExactCover.cpp
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */

#include "ExactCover.h"
#include <UniversalTest.h>
#include <vector>
#include <set>
#include <def.h>
#include "CrossNode.h"
#include <utility>

namespace x2
{

ExactCover::ExactCover(SaveFunType saver):
		saver(saver)
{
	// TODO Auto-generated constructor stub

}

ExactCover::~ExactCover()
{
	// TODO Auto-generated destructor stub
}

void ExactCover::solve(CrossList<int>& list)
{

	//judge if A is empty,if it is empty print solution
	if(list.head->getNext()==NULL)
	{
		//list is empty

		//the only solution is 1 3 5
//		std::cout << "List is empty" << std::endl; //save one solution
//		while(getchar()!='\n');
		if(saver)
			this->saver(solutionone);
		else{
//			std::cout << "Find one solution but no saver function defined." << std::endl;
		}

	}else{

		//find such column j that has smallest amount of 1
		CrossNodeHead<int> *pcol=list.head->getNext();
		CrossNodeHead<int> *pmincol=pcol->getMinNum();

//		std::cout << "min num of col is " << pmincol->num << std::endl;

		if(pmincol->num==0)return; //impossible to have a solution

		//for each row i intersect with j'1,select one as candidate solution
		CrossNode<int> *curRow=pmincol->getSon();
		while(curRow)
		{
			this->solutionone.push_back(curRow);
//			std::cout << "curRow is " << curRow->toDetailedString() << std::endl;
			//try to delete any other i' has same 1 in any column with i
			CrossNode<int> *rowHead=(CrossNode<int>*)curRow->getFirst();
//			std::cout << "curRow first head is " << rowHead->toDetailedString() << std::endl;
			//use a vector to record each column's rows's first available node(as if that column is removed)(=getFirst or getNext)
			//a problem: repeating removing a row(remove a removed row) can be possible?  == can be possible
			//			and repeating restoring is possible?  == can be possible

			std::vector<std::vector<CrossNode<int>*> > rowsheads;
			std::vector<CrossNodeHead<int>*> colheads;
			for(CrossNode<int>* it=rowHead;it!=NULL;it=it->getNext())
			{
				std::vector<CrossNode<int>*> arowheads;
				CrossNodeHead<int> *itcolhead=(CrossNodeHead<int>*)it->getFirstFather();
//				std::cout << "colhead is " << itcolhead->toString() << "@" << itcolhead << std::endl;

				//remove each row of that column
				for(CrossNode<int>* itcol=itcolhead->getSon();itcol!=NULL;itcol=itcol->getSon())
				{
//					std::cout << "row head is " << itcol->toDetailedString() << std::endl;
					arowheads.push_back(itcol);
//					std::cout << "before remove size is " <<itcolhead->num << std::endl;
					itcol->removeRow();
//					std::cout << "after remove size is " <<itcolhead->num << std::endl;
				}
				//remove that column
				colheads.push_back(itcolhead);
				rowsheads.push_back(std::move(arowheads));
				itcolhead->removeCol();

				//go to next node of that column and repeat
			}

			std::cout << "current reduced is " << std::endl << list.toString() << std::endl;

			//call this process on reduced A
			solve(list);

			//restore all removed nodes
			std::vector<std::vector<CrossNode<int>*> >::reverse_iterator itrows=rowsheads.rbegin(),itrowsend=rowsheads.rend();
			std::vector<CrossNodeHead<int>*>::reverse_iterator itcol=colheads.rbegin(),itcolend=colheads.rend();
			while(itcol!=itcolend)
			{
				for(std::vector<CrossNode<int>*>::reverse_iterator itrow=itrows->rbegin(),itrowend=itrows->rend();itrow!=itrowend;itrow++)
				{
//					std::cout << "restoring row " << (*itrow)->toDetailedString << std::endl;
					(*itrow)->restoreRow();

				}
//				std::cout << "restoring col " << (*itcol)->toDetailedString << std::endl;
				(*itcol)->restoreCol();
				itcol++;
				itrows++;
			}
			std::cout << "current un-reduced is " << std::endl << list.toString() << std::endl;

			//loop to next row
			this->solutionone.pop_back();
			curRow = curRow->getSon();

		}

	}

}

} /* namespace x2 */
