//Structure de base ; le type int redefinie
typedef struct int_t{
	short int sign;
	size_t size;
	int* val;
}int_t;
//Fonction d'initialisation
void initInt(int_t *myInt, size_t s) ; 
//Redefinition des opérateurs de base
//Opérateur d'addition
