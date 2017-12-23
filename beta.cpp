#include <cstdio>

int main(int argc, char** argv){
	printf("Projet M1 CHPS");
}

void initInt(int_t *myInt, size_t s){
     myInt->val=(int*)malloc(int(s)*sizeof(int));
     myInt->size = s;
}