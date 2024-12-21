#pragma once
#include "strategy.h"
#include <functional>
#include <memory>

class Decision
{
private:
	
	std::unique_ptr<Strategy> strategy;
	using function = typename std::function<double(double)>;

public:
	Decision() = default;
	void set_strategy(std::unique_ptr<Strategy> _strategy) { strategy = std::move(_strategy); }
	double get_answer(double _start, double _end, double _eps, function _f, function _df) { return strategy->get_result(_start, _end, _eps, _f, _df); }
	~Decision() = default;

};