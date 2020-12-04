#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "rand.h"
#include "iterator.hpp"
#include "visitor.hpp"

int main()
{


	Base* num1 = new Op(3);
	Base* num2 = new Op(4);
	Pow* temp = new Pow(num1, num2);
	Base* dummy = new Add(temp, num2);
	Iterator *it = dummy->create_iterator();
	CountVisitor *visit = new CountVisitor();
	it->first();
	while(!it->is_done()) {
		Base* phase = it->current();
		phase->accept(visit);
		it->next();
	}
return 0; 
}

