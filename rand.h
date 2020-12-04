#ifndef RAND_H
#define RAND_H

#include "base.hpp"

class Rand : public Base { 
     private: 
	double val;
     public: 
        Rand() : val(rand() % 100), Base() {}
        virtual double evaluate() { return val; } 
        virtual std::string stringify() { return std::to_string(val); }
	virtual Iterator* create_iterator(){Iterator* n = new NullIterator(); return n  ;}
        virtual Base* get_left() { return nullptr;}
        virtual Base* get_right()  { return nullptr;}
        virtual void accept(CountVisitor* v) { v->visit_op(); }

};

#endif //RAND_H 
