#pragma once
#include "strategy.h"
#include <functional>

class Decision
{
private:
	Strategy&& strategy;
	//typedef double(*function)(double x);
	//using function = typename double(function)(double x)
	using function = typename std::function<double(double)>;

public:
	//Decision() = default;
	//Decision& operator=(const Decision& decision) { this->strategy = decision.strategy; };
	Decision(Strategy& _strategy) : strategy(std::move(_strategy)) {};
	void set_strategy(Strategy& _strategy) { strategy = std::move(_strategy); }
	double get_answer(double _start, double _end, double _eps, function _f, function _df) { return strategy.get_result(_start, _end, _eps, _f, _df); }
	~Decision() = default;

};

//По четвертому блоку :
//1.   function df;
//Зачем хранить в полях класса производную.В get_result добавь параметром по умолчанию ее.
//2. И вот скажи мне зачем через const передавать все параметры ?
//3. typedef double(*function)(double x); -лучше using.
//4. И давай принимать не указатель на функцию, а std::function например.
//5. Strategy & strategy; Ссылки не храним, храним умный указатель на стратегию.Получаем указатель через метод set_strategy.
//6. Лучше разбить каждую стратегию на свой h файл.
//7. По методам хорд : если a > b ? Если решение уже есть в точках a или b ? Если мы не смогли найти решение за какое - то кол - во итераций и метод зациклился ?
//Это все ко всем методам замечания.
//8.
//
//копировать
//while ((b - a) / 2 > _eps)
//{
//	c = (a + b) / 2;
//	if ((_f(a) * _f(c)) > 0) { a = c; }
//	else { b = c; }
//}
//
//
//Если у тебя решение уже найдено в точке c.То надо остановиться, сделать break.
//9. Метод Ньютона может запросто зациклиться.Нужно определенное число итераций.


//1. вроде исправил!
//2. убрал!
//3. и 4. исправлено вместе!
//5. последний пункт под вопросом!????
//6. исправил!
//7. добавил ограничение по итерациям!
//8. добавил ограничение по итерациям!
//9. добавил ограничение по итерациям!