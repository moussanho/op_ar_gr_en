#include <cstdio>
#include <iostream>
#include <cmath>
#include <cassert>
#include "alpha.hpp"

using namespace std;

int main(int argc, char** argv){
	printf("Projet M1 CHPS");
	int_t * a=init(6,32);int_t *b=init(4,32);
	int_t* c=substraction(a,b);
	cout<<"success!"<<endl ; 
	
}
/*Initialisation
lambda::int_t(size_t size,bool sign):size(size) ,sign(sign){//overloaded constructor 
	       //this->size=size ; this->sign=sign;
	       this->val=new int[int(size)];		   
}
//Basic operators overloading by member function
//addition
int_t & lambda::int_t::operator+(int_t & a){
	int_t b=new int_t(a.size,a.b) ;
	for(int i=0;i<a.size;b.val[i]=this->val[i]+a.val[i],i++) ;
	return b;
}  */ 
	  
