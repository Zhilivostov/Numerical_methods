#pragma once
#include "strategy.h"

class Bisector_method final : public Strategy
{
public:
	Bisector_method() = default;
	double get_result(double _start, double _end, double _eps, function _f, function _df = 0) const override
	{
		double c = 0;
		double a = _start;
		double b = _end;
		if (_f(a) * _f(b) > 0) throw std::runtime_error("Wrong data");
		int i = 0;
		while (((b - a) / 2 > _eps) && (i < max_iter))
		{
			c = (a + b) / 2;
			if ((_f(a) * _f(c)) > 0) { a = c; }
			else { b = c; }
			++i;
		}
		if (i >= max_iter) throw std::runtime_error("Wrong data");
		return c;
	}
	~Bisector_method() = default;
};