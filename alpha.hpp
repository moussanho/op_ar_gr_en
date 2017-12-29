//Basic structure of our new int type 
typedef struct int_t{
	int register_size;
	bool* register_content;
} int_t;
//declaration and initialisation (with a value)
int_t* init(long int value,int size){
	//assert((int(size)%32)!=0) ; 
	//assert(( pow(2,int(size)) - 1 )<value) ;
	int_t* myStruct=malloc(sizeof(int_t));
	myStruct->register_size=size;
	myStruct->register_content=(bool*)malloc(size);
	//shift  operators using for binary division: >>><<<< 
	int i=0;
	while((i<size)){
		myStruct->register_content[size-i-1]=value%2 ; value>>=1 ; i++;
		}
    if(i<=size-1) {
	   while(i<=size-1){  myStruct->register_content[i]=0; i++;}
	}
	return myStruct;
} 
//converter before printing
int converter(int_t* a){
	int result=0;
	for(int i=a->register_size-1,j=0 ;i>=0;i--,j++){
	    if(a->register_content[i]==1) result+=pow(2,j); 
	}
	return result ;
}
//addition
int_t* addition(int_t* a,int_t* b){
	//assert(a->register_size!=b->register_size);
	int_t* result=init(0,a->register_size);
	int counter;
	bool overflown=false;
	for(counter=0;counter<result->register_size;counter++){
		 if(!(overflown||0)){
			   result->register_content[counter]=(!(a->register_content[counter]& b->register_content[counter] ))? false :
			   !(a->register_content[counter]& b->register_content[counter] ) ; //end of ternary
			   overflown=(a->register_content[counter]&(~b->register_content[counter])) ? 0: true;
			   }
		   if(overflown){
			 if(a->register_content[counter]&(!b->register_content[counter]))
			 {result->register_content[counter]=a->register_content[counter]^overflown; overflown=0;}  
			 if((!a->register_content[counter])&b->register_content[counter] || 
			 a->register_content[counter]&b->register_content[counter] || !
			 (a->register_content[counter]&b->register_content[counter])){ result->register_content[counter]=0;} 
	}
}return result;
}
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
int_t* multiplication(int_t* a, int_t* b){
	int_t* result=init(0,a->register_size);
	for(int i=0;i<a->register_size-1;i++){
		if(*(b->register_content+i)==0) continue;
		for(int j=0;j+i<=a->register_size-1;j++){
			result->register_content[i+j]=a->register_content[j] ;
		}
		for(int j=0;j<i;j++){
			result->register_content[j]=0;
		}
	}
	return result ;
}
//Division
int_t* division(int_t* a, int_t* b){
	int_t* result=init(0,a->register_size);
	for(int i=0;i<a->register_size;i++){
		if(*(b->register_content+i)==0) continue;
		for(int j=0;j+i<=a->register_size;j++){
			result->register_content[result->register_size-i-j-1]=a->register_content[a->register_size-j-1] ;
		}
		for(int j=result->register_size-1;j>i;j--){
			result->register_content[j]=0; 
		}
	}
	return result ;
}
