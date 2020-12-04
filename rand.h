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
};

#endif //RAND_H 
