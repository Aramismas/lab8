#ifndef POW_H
#define POW_H
#include <math.h>
#include "base.hpp"
 
class Pow : public Base { 
     private: 
	Base * exp1; 
	Base * exp2; 
     public: 
        Pow(Base* v1, Base * v2) : exp1(v1), exp2(v2)  , Base() {}
        virtual double evaluate() { return pow(exp1->evaluate(), exp2->evaluate())  ; } 
        virtual std::string stringify() { return exp1->stringify() + " ** " + exp2->stringify(); }
};

#endif //POW_H
