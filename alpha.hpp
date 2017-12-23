//Basic structure of our new int type 
typedef struct int_t{
	size_t register_size;
	bool* register_content;
} int_t;
int_t* init_new_register(int_t* myStruct,size_t size){
	assert((int(size)%32)!=0) ; 
	int_t* myRegStruct=(int_t*)malloc(sizeof(int_t));
	myRegStruct->register_size=size;
	myRegStruct->register_content=(bool*)malloc(size);
}
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
