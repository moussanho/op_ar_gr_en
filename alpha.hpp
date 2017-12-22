//Structure de base ; le type int redefinie
typedef struct int_t{
	bool sign;
	size_t size;//utilisation d'un type plus adaptée pour quantifier une dimension
	int* val;
}int_t;
//Fonction d'initialisation
void initInt(int_t & myInt, size_t size,bool sign) ; //Passage par reference de la structure;critère de performance
//Redefinition des opérateurs de base par le mecanisme de surcharge
//Opérateur d'addition

