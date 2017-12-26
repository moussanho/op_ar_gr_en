//Basic structure of our new int type 
typedef struct int_t{
	size_t register_size;
	bool* register_content;
} int_t;
//declaration and initialisation (with a value)
int_t* init(long int value,size_t size){
	//assert((int(size)%32)!=0) ; 
	//assert(( pow(2,int(size)) - 1 )<value) ;
	int_t* myStruct=(int_t*)malloc(sizeof(int_t));
	myStruct->register_size=size;
	myStruct->register_content=(bool*)malloc(sizeof(size));
	for(;int(size)>0 ; *(myStruct->register_content + int(size)-1)=size%2, size/=2);//shift  operator: >>><<<< 
	return myStruct;
}
/*Initialisation (with a value)   
//addition
int_t* addition(int_t* a,int_t* b){
	assert(a->regsiter_size!=b->register_size);
	int_t* result=init(0,a->register_size);
	int counter;
	bool overflown=false;
	for(counter=0;counter<result->register_size;counter++){
		 if(!(overflown||0)){
			   result->register_content[counter]=(!(a->register_content[counter]& b->register_content[counter] ))? false :
			   !(a->register_content[counter]& b->register_content[counter] ) ; //end of ternary
			   overflown=(a&(~b)) ? : ;
			   }
		   if(overflown){
			 if(a&(!b)){r=a^overflown; overflown--;}  
			 if((!a)&b || a&b || !(a&b)){ r=0;} 
	}
	return result;
}*/
//subtraction
int_t* substraction(int_t* a,int_t* b){
	   //assert(a->register_size!=b->register_size);
	   int_t* result=init(0,a->register_size);
	   int counter; 
	   bool overflown=0; 
	   for(counter=0;counter<result->register_size;counter++){
		   if((~overflown)){
			   result->register_content[counter]=a->register_content[counter]^b->register_content[counter] ; 
			   overflown=((~a->register_content[counter])&&b->register_content[counter]) ? ~overflown:overflown; //ternaire
			   }
		   if(overflown){
			 overflown=(a->register_content[counter]&(!b->register_content[counter]))? //see next line 
			 result->register_content[counter]=a->register_content[counter], ~overflown:overflown ;  
			 result->register_content[counter]=((!a->register_content[counter])&b->register_content[counter] || //see next line
			 a->register_content[counter]&b->register_content[counter] || !(a->register_content[counter] //see next line
			 &b->register_content[counter]))? ~result->register_content[counter]:result->register_content[counter];
	   }
}return result;
}
//multiplication
