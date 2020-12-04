#ifndef __OP_HPP__
#define __OP_HPP__
 
#include "base.hpp"

class Op : public Base {
    private: 
        double val;
    public:
        Op(double value) : val(value), Base() { }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
	virtual Iterator* create_iterator(){Iterator* n = new NullIterator(this); return n  ;} 
	virtual Base* get_left() { return nullptr;}
	virtual Base* get_right()  { return nullptr;}
	virtual void accept(CountVisitor* v) { v->visit_op(); }
	
};

#endif //__OP_HPP__
