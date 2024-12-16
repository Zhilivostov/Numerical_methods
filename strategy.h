#pragma once

class Strategy
{
protected:
	typedef double(*function)(double x); //çàäàíèå òèïà function

public:

	Strategy() = default;
	virtual double get_result(const double _start, const double _end, const double _eps, function _f) const = 0; // eps - ïîãðåøíîñòü
	virtual ~Strategy() = default;
};

class Chord_method final: public Strategy
{
public:
	Chord_method() = default;
	double get_result(const double _start, const double _end, const double _eps, function _f) const override
	{
		double a = _start;
		double b = _end;
		while (fabs(b - a) > _eps)
		{
			a = a - (b - a) * _f(a) / (_f(b) - _f(a));
			b = b - (a - b) * _f(b) / (_f(a) - _f(b));
		}
		return b;
	}
	~Chord_method() = default;

};

class Bisector_method final: public Strategy
{
public:
	Bisector_method() = default;
	double get_result(const double _start, const double _end, const double _eps, function _f) const override
	{
		double c = 0;
		double a = _start;
		double b = _end;
		while ((b - a) / 2 > _eps)
		{
			c = (a + b) / 2;
			if ((_f(a) * _f(c)) > 0) { a = c; }
			else { b = c; }
		}
		return c;
	}
	~Bisector_method() = default;
};

class Newton_method final: public Strategy
{
private:
	function df;

public:
	Newton_method(function _df) : df(_df) {};
	//void get_fd(function& _df)
	//{
		//df = _df;
	//}
	double get_result(const double _start, const double _end, const double _eps, function _f) const override
	{
		double x0 = (_start + _end) / 2;
		double x1 = x1 = x0 - _f(x0) / df(x0);
		while (fabs(x1 - x0) > _eps)
		{
			x0 = x1;
			x1 = x0 - _f(x0) / df(x0);
		}
		return x1;
	}
	~Newton_method() = default;
};
