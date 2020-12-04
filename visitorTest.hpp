#ifndef __VISITORTEST_HPP__
#define __VISITORTEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "add.h"
#include "sub.h"
#include "mult.h"
#include "div.h"
#include "pow.h"
#include "rand.h"
#include "iterator.hpp"
#include "visitor.hpp"

TEST(VisitorTest, PowBinaryTest) {
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
	EXPECT_EQ(visit->op_count(), 2);
	EXPECT_EQ(visit->pow_count(), 1);
	EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, MultBinaryTest) {
        Base* num1 = new Op(3);
        Base* num2 = new Op(4);
        Mult* temp = new Mult(num1, num2);
        Base* dummy = new Sub(temp, num2);
        Iterator *it = dummy->create_iterator();
        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()) {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->op_count(), 2);
        EXPECT_EQ(visit->mult_count(), 1);
        EXPECT_EQ(visit->sub_count(), 0);
}

TEST(VisitorTest, DivBinaryTest) {
        Base* num1 = new Op(3);
        Base* num2 = new Op(4);
        Div* temp = new Div(num1, num2);
        Base* dummy = new Add(temp, num2);
        Iterator *it = dummy->create_iterator();
        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()) {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->op_count(), 2);
        EXPECT_EQ(visit->div_count(), 1);
        EXPECT_EQ(visit->add_count(), 0);
}

TEST(VisitorTest, AddBinaryTest) {
        Base* num1 = new Op(3);
        Base* num2 = new Op(4);
        Add* temp = new Add(num1, num2);
        Base* dummy = new Mult(temp, num2);
        Iterator *it = dummy->create_iterator();
        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()) {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->op_count(), 2);
        EXPECT_EQ(visit->add_count(), 1);
        EXPECT_EQ(visit->mult_count(), 0);
}

TEST(VisitorTest, SubBinaryTest) {
        Base* num1 = new Op(3);
        Base* num2 = new Op(4);
        Sub* temp = new Sub(num1, num2);
        Base* dummy = new Mult(temp, num2);
        Iterator *it = dummy->create_iterator();
        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()) {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->op_count(), 2);
        EXPECT_EQ(visit->sub_count(), 1);
        EXPECT_EQ(visit->mult_count(), 0);
}

TEST(VisitorTest, AddRandBinaryTest) {
        Base* num1 = new Rand();
        Base* num2 = new Rand();
        Add* temp = new Add(num1, num2);
        Base* dummy = new Mult(temp, num2);
        Iterator *it = dummy->create_iterator();
        CountVisitor *visit = new CountVisitor();
        it->first();
        while(!it->is_done()) {
                Base* phase = it->current();
                phase->accept(visit);
                it->next();
        }
        EXPECT_EQ(visit->rand_count(), 2);
        EXPECT_EQ(visit->add_count(), 1);
        EXPECT_EQ(visit->mult_count(), 0);
}

TEST(VisitorTest, VisitorTest1) {
	CountVisitor *visitor = new CountVisitor();
	Base *num1 = new Op(8);
	Base *num2 = new Op(4);
	num1->accept(visitor);
	EXPECT_EQ(visitor->op_count(), 1);
	num2->accept(visitor);
	EXPECT_EQ(visitor->op_count(), 2);
	Base* temp1 = new Sub(num1, num2);
	Base* temp2 = new Div(num1, num2);
	temp1->accept(visitor);
	temp2->accept(visitor); 
	EXPECT_EQ(visitor->op_count(), 2);
	EXPECT_EQ(visitor->sub_count(), 1);
	EXPECT_EQ(visitor->div_count(), 1);	
}

TEST(VisitorTest, VisitorTest2) {
        CountVisitor *visitor = new CountVisitor();
        Base *num1 = new Op(8);
        Base *num2 = new Op(4);
        num1->accept(visitor);
        EXPECT_EQ(visitor->op_count(), 1);
        num2->accept(visitor);
        EXPECT_EQ(visitor->op_count(), 2);
        Base* temp1 = new Add(num1, num2);
        Base* temp2 = new Mult(num1, num2); 
	Base* temp3 = new Pow(num1, num2);
        temp1->accept(visitor);
        temp2->accept(visitor);
	temp3->accept(visitor);
        EXPECT_EQ(visitor->op_count(), 2);
        EXPECT_EQ(visitor->add_count(), 1);
        EXPECT_EQ(visitor->mult_count(), 1);
	EXPECT_EQ(visitor->pow_count(), 1);	
}

#endif // visitorTest.hpp
