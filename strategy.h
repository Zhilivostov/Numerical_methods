#pragma once
#include <functional>

class Strategy
{
protected:
	using function = typename std::function<double(double)>;
	static const int max_iter = 10000;

public:

	Strategy() = default;
	virtual double get_result(double _start, double _end, double _eps, function _f, function _df) const = 0; // eps - погрешность
	virtual ~Strategy() = default;
};