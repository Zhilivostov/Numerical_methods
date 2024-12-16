#pragma once
#include "strategy.h"

class Decision
{
private:
	Strategy& strategy;
	typedef double(*function)(double x);

public:
	
	Decision(Strategy& _strategy) : strategy(_strategy) {};
	double get_answer(const double _start, const double _end, const double _eps, function _f) { return strategy.get_result(_start, _end, _eps, _f); }
	~Decision() = default;

};

