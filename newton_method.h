#pragma once
#include "strategy.h"
#include <cmath>

class Newton_method final : public Strategy
{
public:
	Newton_method() = default;
	double get_result(double _start, double _end, double _eps, function _f, function _df) const override 
	{
		if (_f(_start) * _f(_end) > 0) throw std::runtime_error("Wrong data");
		double x0 = (_start + _end) / 2;
		double x1 = x1 = x0 - _f(x0) / _df(x0);
		int i = 0;
		while ((fabs(x1 - x0) > _eps) && (i < max_iter))
		{
			x0 = x1;
			x1 = x0 - _f(x0) / _df(x0);
			++i;
		}
		if (i >= max_iter) throw std::runtime_error("Wrong data");
		return x1;
	}
	~Newton_method() = default;
};