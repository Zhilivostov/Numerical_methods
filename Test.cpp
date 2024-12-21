#include "gtest/gtest.h"
#include "decision.h"
#include "newton_method.h"
#include "bisector_method.h"
#include "chord_method.h"

double f(double x) { return (x - 1) * (x - 3); }
double df(double x) { return 2*x - 4; }

TEST(Chord_method, Test)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Chord_method>());
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f, 0);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}

TEST(Bisector_method, Test)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Bisector_method>());
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f, 0);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}

TEST(Newton_method, Test)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Newton_method>());
	double a = 2;
	double b = 5;
	double eps = 0.0001;
	double answer = res.get_answer(a, b, eps, f, df);
	EXPECT_TRUE(fabs(3 - answer) < eps);
}

TEST(Chord_method, Test_throw)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Chord_method>());
	double a = 12;
	double b = 15;
	double eps = 0.0001;
	EXPECT_ANY_THROW(res.get_answer(a, b, eps, f, 0));
}

TEST(Bisector_method, Test_throw)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Bisector_method>());
	double a = 12;
	double b = 15;
	double eps = 0.0001;
	EXPECT_ANY_THROW(res.get_answer(a, b, eps, f, 0));
}

TEST(Newton_method, Test_throw)
{
	auto res = Decision();
	res.set_strategy(std::make_unique<Newton_method>());
	double a = 12;
	double b = 15;
	double eps = 0.0001;
	EXPECT_ANY_THROW(res.get_answer(a, b, eps, f, df));
}