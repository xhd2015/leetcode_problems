/*
 * SudokuCrossList.h
 *
 *  Created on: 2017年4月6日
 *      Author: 13774
 */

#ifndef SOLUTIONS_ALGORITHM_X_SUDOKUCROSSLIST_H_
#define SOLUTIONS_ALGORITHM_X_SUDOKUCROSSLIST_H_
#include "CrossNode.h"
namespace x2
{

class SudokuCrossList : public CrossList<int>
{
public:
	enum{
		ROWSZ=9,
		COLSZ=9,
		NINESZ=9,
		C_1=0,
		C_ROW=1,
		C_COL=2,
		C_NINE=3,
		C_SIZE=4,
	};
	typedef CrossList<int> Father;
	typedef SudokuCrossList This;
public:
	SudokuCrossList();
	SudokuCrossList(int A[ROWSZ][COLSZ]);//=9,=9
	static int *multiple(int sza,int szb,int szc,int szd);
	~SudokuCrossList();

	void solve();

public:
	bool init_error;//if init is error
	int constrains[C_SIZE][COLSZ*ROWSZ];

};

} /* namespace x2 */

#endif /* SOLUTIONS_ALGORITHM_X_SUDOKUCROSSLIST_H_ */
