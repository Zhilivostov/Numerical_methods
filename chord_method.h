#pragma once
#include "strategy.h"
#include <cmath>

class Chord_method final : public Strategy
{
public:
	Chord_method() = default;
	double get_result(double _start, double _end, double _eps, function _f, function _df = 0) const override
	{
		double a = std::min(_start, _end);
		double b = std::max(_end, _start);
		int i = 0;
		while ((fabs(b - a) > _eps) && (i < max_iter))
		{
			a = a - (b - a) * _f(a) / (_f(b) - _f(a));
			b = b - (a - b) * _f(b) / (_f(a) - _f(b));
			++i;
		}
		if ((fabs(b - a) > _eps) && (i == max_iter))
			throw std::invalid_argument("Wrong data");
		return b;
	}
	~Chord_method() = default;
};