#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "rand.h"
#include "iterator.hpp"
#include "visitor.hpp"
#include <iostream>

int main()
{


	Base* num1 = new Op(3);
	Base* num2 = new Op(4);
	Mult* temp = new Mult(num1, num2);
	Base* dummy = new Add(temp, num2);
	Iterator *it = dummy->create_iterator();
	CountVisitor *visit = new CountVisitor();
	it->first();
	while(!it->is_done()) {
		Base* phase = it->current();
		phase->accept(visit);
		it->next();
	}
	std::cout << "Mult Count: " << visit->mult_count() << " OP Count: " << visit->op_count() << std::endl;
return 0; 
}
