/*
 * ExactCover.h
 *
 *  Created on: 2017年4月5日
 *      Author: 13774
 */

#ifndef SOLUTIONS_ALGORITHM_X_EXACTCOVER_H_
#define SOLUTIONS_ALGORITHM_X_EXACTCOVER_H_

#include <vector>
#include "CrossNode.h"
#include <functional>


namespace x2
{

class ExactCover
{
	typedef std::function<void(const std::vector<CrossNode<int>*> &oneSolution)> SaveFunType;
public:
	ExactCover()=default;
	ExactCover(SaveFunType saver);
	~ExactCover();

	void solve(CrossList<int>& list);
//	virtual void saveOneResult(const std::vector<CrossNode<int>*> &oneSolution);

public:
	std::vector<CrossNode<int>*> solutionone;//rows
	SaveFunType saver;
};

} /* namespace x2 */

#endif /* SOLUTIONS_ALGORITHM_X_EXACTCOVER_H_ */
