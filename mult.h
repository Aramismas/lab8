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
	 virtual Iterator* create_iterator(){Iterator* n = new BinaryIterator(this); return n  ;}
        virtual Base* get_left() { return exp1;}
        virtual Base* get_right()  { return exp2;}
        virtual void accept(CountVisitor* v) { v->visit_mult(); }

};

#endif
