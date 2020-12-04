#ifndef MULT_H
#define MULT_H 
#include <string>
#include "base.hpp"
class Mult : public Base{

private:
        Base* exp1;
        Base* exp2;
public:
        Mult(Base* num1 , Base* num2) : exp1(num1), exp2(num2), Base() { }
        virtual double evaluate(){ return exp1->evaluate()* exp2->evaluate();}
        virtual std::string stringify(){return exp1->stringify() + " * " + exp2->stringify();}
};

#endif
