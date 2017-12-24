//Basic structure of our new int type 
typedef struct int_t{
	size_t register_size;
	bool* register_content;
} int_t;
//declaration et initialisation
int_t* init(long int value,size_t size){
	assert((int(size)%32)!=0) ; 
	assert(( pow(2,int(size)) - 1 )<value) ;
	int_t* myStruct=(int_t*)malloc(sizeof(int_t));
	myStruct->register_size=size;
	myStruct->register_content=(bool*)malloc(size);
	do{
		myStruct->register_content[size--]= value%2;
		value>>1; //division par 2
	}while(size>=0);
	return myRegstruct;
}
//Initialisation (with a value)
int_t* init(long int value){
}
//addition
int_t* addition(int_t* a,int_t* b){
	assert(a->regsiter_size!=b->register_size);
	int_t* result=(int_t*)malloc(sizeof(int_t));
	result->register_size=a->register_size;
	int counter;
	for(counter=0;counter<result->register_size;counter++){
		result->register_content[i] = (a->register_content[i]==b->register_content[i]) ? 0 : 1 ; 
	}
	return result;
}
