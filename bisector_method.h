#pragma once
#include "strategy.h"
//#include <utility>

class Bisector_method final : public Strategy
{
public:
	Bisector_method() = default;
	double get_result(double _start, double _end, double _eps, function _f, function _df = 0) const override
	{
		double c = 0;
		double a = std::min(_start, _end);
		double b = std::max(_end, _start);
		int i = 0;
		while (((b - a) / 2 > _eps) && (i < max_iter))
		//while ((b - a) / 2 > _eps)
		{
			c = (a + b) / 2;
			if ((_f(a) * _f(c)) > 0) { a = c; }
			else { b = c; }
			++i;
		}
		if (((b - a) / 2 > _eps) && (i == max_iter))
			throw std::invalid_argument("Wrong data");
		return c;
	}
	~Bisector_method() = default;
};
