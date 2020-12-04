#ifndef DIV_H
#define DIV_H

#include "base.hpp"
#include <string>

class Div : public Base{

private:
	Base* exp1; 
	Base* exp2;
public:
	Div(Base* num1 ,Base* num2) : exp1(num1), exp2(num2), Base() { }
	virtual double evaluate(){ return exp1->evaluate() / exp2->evaluate();}
	virtual std::string stringify(){return exp1->stringify() + " / " + exp2->stringify();}
}; 

#endif 
