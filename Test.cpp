#include "gtest/gtest.h"
#include "decision.h"
#include "strategy.h"

double f(double x) { return (x - 1) * (x - 3); }
double df(double x) { return 2*x - 4; }

TEST(Chord_method, Test)
{
	auto meth = Chord_method();
	auto res = Decision(meth);
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}

TEST(Bisector_method, Test)
{
	auto meth = Bisector_method();
	auto res = Decision(meth);
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}

TEST(Newton_method, Test)
{
	auto meth = Newton_method(df);
	auto res = Decision(meth);
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}