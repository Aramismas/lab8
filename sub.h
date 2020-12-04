#ifndef sub_h
#define sub_h

#include "base.hpp"
#include "op.hpp"

class Sub : public Base {
    private: 
        Base* exp1;
        Base* exp2;
    public:
        Sub(Base* v1, Base* v2) : exp1(v1), exp2(v2), Base() { }
        virtual double evaluate() { return exp1->evaluate() -  exp2->evaluate() ; }
        virtual std::string stringify() { return exp1->stringify() + " - " + exp2->stringify(); }
	virtual Iterator* create_iterator(){Iterator* n = new NullIterator(this); return n  ;}
        virtual Base* get_left() { return exp1;}
        virtual Base* get_right()  { return exp2;}
        virtual void accept(CountVisitor* v) { v->visit_sub(); }



};

#endif //Sub_h
