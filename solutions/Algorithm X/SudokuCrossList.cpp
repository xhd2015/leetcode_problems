/*
 * SudokuCrossList.cpp
 *
 *  Created on: 2017年4月6日
 *      Author: 13774
 */

#include "SudokuCrossList.h"
#include <new>
#include <cstring>

namespace x2
{

SudokuCrossList::SudokuCrossList():
		init_error(false)
{
	// TODO Auto-generated constructor stub

}
SudokuCrossList::SudokuCrossList(int A[ROWSZ][COLSZ])
:init_error(false)
{
	for(int i=0;i<C_SIZE;i++)
		for(int j=0;j<COLSZ*ROWSZ;j++)
			constrains[i][j]=0;

	for(int i=0;i<ROWSZ;i++)
	{
		for(int j=0;j<COLSZ;j++)
		{
			if(A[i][j]!=0)
			{
				constrains[C_1][i*COLSZ + j] = 1;
				if(constrains[C_ROW][i*ROWSZ + A[i][j] - 1] == 1 || constrains[C_COL][j*COLSZ + A[i][j] - 1]==1)
				{
					init_error=true;
				}
				constrains[C_ROW][i*ROWSZ + A[i][j] - 1]=1;
				constrains[C_COL][j*COLSZ + A[i][j] - 1]=1;
				int NINE_no = i/3*3 + j/3;
				if(constrains[C_NINE][NINE_no * NINESZ + A[i][j] - 1] == 1)
				{
					init_error=true;
				}
				constrains[C_NINE][NINE_no * NINESZ + A[i][j] - 1]=1;
			}
		}
	}
	//=========init
	this->head = new CrossNodeHead<int>;
	int colsz=C_SIZE * COLSZ * ROWSZ;
	this->head->num =colsz;

	CrossNodeHead<int>*			curColLast=this->head;

	for(int j=0;j<colsz;j++) //we will remove the extra zero-length head before proceeds
	{
		CrossNodeHead<int>*   nextHead=new CrossNodeHead<int>;
		curColLast->insertNext(nextHead);
		curColLast = nextHead;
	}

	CrossNodeHead<int> *head1=this->head->getNext();
	CrossNodeHead<int> *head2=(CrossNodeHead<int> *)head1->getNthNext(ROWSZ * COLSZ);
	CrossNodeHead<int> *head3=(CrossNodeHead<int> *)head2->getNthNext(ROWSZ * COLSZ);
	CrossNodeHead<int> *head4=(CrossNodeHead<int> *)head3->getNthNext(ROWSZ * COLSZ);

	for(int i=0;i<ROWSZ * COLSZ ; i++)
	{
		if(constrains[C_1][i]==1)continue;
		int posi=i/COLSZ,posj=i%COLSZ;
		for(int tryi=1;tryi<=ROWSZ;tryi++)
		{
			if(constrains[C_ROW][posi * ROWSZ + tryi-1]==1)continue; //try to set <posi,posj> as tryi
			if(constrains[C_COL][posj * COLSZ + tryi-1]==1)continue;
			int NINE_no = posi/3*3 + posj/3;
			if(constrains[C_NINE][NINE_no * NINESZ + tryi-1]==1)continue;

//			std::cout << "try to set "<<posi<<","<<posj<<" as " << tryi << std::endl;


			CrossNodeHead<int> *head1_pos=(CrossNodeHead<int> *)head1->getNth(i);
			CrossNodeHead<int> *head2_pos=(CrossNodeHead<int> *)head2->getNth(posi * ROWSZ + tryi-1);
			CrossNodeHead<int> *head3_pos=(CrossNodeHead<int> *)head3->getNth(posj * COLSZ + tryi-1);
			CrossNodeHead<int> *head4_pos=(CrossNodeHead<int> *)head4->getNth(NINE_no *NINESZ + tryi-1);




			CrossNode<int>* temp1=new CrossNode<int>(0,i);
			CrossNode<int>* temp2=new CrossNode<int>(ROWSZ*COLSZ + posi*ROWSZ,tryi);
			CrossNode<int>* temp3=new CrossNode<int>(ROWSZ*COLSZ*2 + posj*COLSZ,tryi);
			CrossNode<int>* temp4=new CrossNode<int>(ROWSZ*COLSZ*3 + NINE_no * NINESZ,tryi);

			std::cout <<"setting head "<< temp1->CrossNode<int>::toString() << std::endl;


			head1_pos->getLastSon()->insertSon(temp1);
			head1_pos->num++;
			head2_pos->getLastSon()->insertSon(temp2);
			head2_pos->num++;
			head3_pos->getLastSon()->insertSon(temp3);
			head3_pos->num++;
			head4_pos->getLastSon()->insertSon(temp4);
			head4_pos->num++;

			temp1->insertNext(temp2);
			temp2->insertNext(temp3);
			temp3->insertNext(temp4);
		}
	}
//	std::cout << "end try set" << std::endl;


	head1=this->head->getNext();
	while(head1)
	{
		if(head1->num==0)head1->removeCol();
		head1=head1->getNext();
	}
}
/**
 * copy
 */
int *SudokuCrossList::multiple(int sza,int szb,int szc,int szd)
{
//	if(A==NULL || B == NULL || C==NULL || D==NULL)return NULL;
	int sz4=sza+szb+szc+szd;
	int allsz=sza*szb*szc*szd;
	int *all=new int[sz4 * allsz]();//all zeros
//	if(all==NULL)std::cout << "NULL" << std::endl;
	int ai=0,bi=0,ci=0,di=0;
	for(int i=0;i<allsz;i++)
	{
		all[i*sz4 + ai]=1;
		all[i*sz4 + sza + bi] = 1;
		all[i*sz4 + sza + szb + ci]=1;
		all[i*sz4 + sza + szb + szc + di]=1;
		di++;
		if(di==szd){
			di=0;ci++;
			if(ci==szc)
			{
				ci=0;bi++;
				if(bi==szb)
				{
					bi=0;ai++;
					if(ai==sza)
					{
						ai=0;
					}
				}
			}
		}
	}

//	std::cout << "returning " << std::endl;
//	std::cout << x2::toString(all,sza*szb*szc*szd,sza+szb+szc+szd) << std::endl;
	return all;
}
//int *SudokuCrossList::makeOne(int sza,int pos,int val)
//{
//	int *rt=new int[sza]();
//	if(pos<sza && pos>=0)rt[pos]=val;
//	return rt;
//}
SudokuCrossList::~SudokuCrossList()
{
	// TODO Auto-generated destructor stub
}

} /* namespace x2 */
