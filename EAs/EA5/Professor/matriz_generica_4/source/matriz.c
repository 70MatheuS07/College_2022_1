#ifdef TIPADO_
#ifdef DESTE_TIPO_
#ifdef DESTE_FORMATO_
/* ESTE ARQUIVO SOMENTE DEVE SER 
 * PRÉ-PROCESSADO E, DEPOIS, COMPILADO SE 
 * O TIPO, O PREFIXO DOS NOMES DOS MÉTODOS E O FORMATO
 * ESTIVEREM DEFINIDOS */

 typedef struct TIPADO_(Matriz_st) {
		unsigned int lin;
		unsigned int col;
		DESTE_TIPO_ ** v;
}  TIPADO_(Matriz_t);

TIPADO_(Matriz_pt) 
       TIPADO_(criaMatriz) (unsigned int m, unsigned int n) 
{
	TIPADO_(Matriz_pt) mat = (TIPADO_(Matriz_pt)) malloc(sizeof( TIPADO_(Matriz_t)));
		
	mat->lin = m;
	mat->col = n;
	mat->v = (DESTE_TIPO_**) malloc(m*sizeof(DESTE_TIPO_*));
	for (unsigned i=0; i<m; i++)
	{	mat->v[i] = (DESTE_TIPO_*) malloc(n*sizeof(DESTE_TIPO_));
		if (mat->v[i] == NULL) {
			printf("Memória insuficiente!\n");
			exit(1);
		}
	}
	return mat;
}



void TIPADO_(liberaMatriz) (TIPADO_(Matriz_pt) mat){
	
	for (unsigned i=0; i<mat->lin; i++)
	{	free(mat->v[i]);
	}
	free(mat->v);
	free(mat);
}


DESTE_TIPO_ TIPADO_(acessaMatriz) (TIPADO_(Matriz_pt) mat, unsigned int i, unsigned int j) {
	
	if ( i>= TIPADO_(linhasMatriz)(mat) || j>= TIPADO_(colunasMatriz)(mat)) {
		printf("Acesso inválido!\n");
		exit(1);
	}
	return mat->v[i][j];
}




void TIPADO_(atribuiElemMatriz) (TIPADO_(Matriz_pt) mat, 
						unsigned int i, 
                        unsigned int j, 
                        DESTE_TIPO_ valor) 
{
	if ( i>= TIPADO_(linhasMatriz)(mat) ||  j>= TIPADO_(colunasMatriz)(mat)) {
		printf("Atribuição inválida!\n");
		exit(1);
	}
	mat->v[i][j] = valor;
}


unsigned int TIPADO_(linhasMatriz) (TIPADO_(Matriz_pt) mat) {
	return mat->lin;
}


unsigned int TIPADO_(colunasMatriz) (TIPADO_(Matriz_pt) mat) {
 return mat->col;
}


void TIPADO_(exibeMatriz) (TIPADO_(Matriz_pt) mat)
{
	char formato[10] = " ";
	strcat (formato, DESTE_FORMATO_);
	strcat (formato, " ");
	
	for (unsigned int i=0; i < TIPADO_(linhasMatriz) (mat); i++)
	{
		for (unsigned j = 0; j < TIPADO_(colunasMatriz) (mat); j++)
		{
			printf (formato , TIPADO_(acessaMatriz) (mat,i,j));
		}
		printf ("\n");
	}
	printf ("\n\n");
}

void TIPADO_(preencheSequencialMatriz) (TIPADO_(Matriz_pt) mat)
{
	DESTE_TIPO_ valor = 1;
    for (unsigned int i=0; i < TIPADO_(linhasMatriz) (mat); i++)
    {
		for (unsigned int j=0; j< TIPADO_(colunasMatriz)(mat); j++)
		{
			TIPADO_(atribuiElemMatriz) (mat, i,j, valor);
			valor++;
		}
	}
}



TIPADO_(Matriz_pt)  TIPADO_(multiplicaMatrizes) (TIPADO_(Matriz_pt) mat1, 
                                                   TIPADO_(Matriz_pt) mat2)
{
	DESTE_TIPO_ valor;
	
	if (TIPADO_(colunasMatriz) (mat1) != TIPADO_(linhasMatriz) (mat2))
	{
		printf("Dimensões não permitem multiplicação das matrizes!\n");
		exit(1);
	}
	
	TIPADO_(Matriz_pt) resultado = TIPADO_(criaMatriz) ( 	TIPADO_(linhasMatriz)  (mat1),
										TIPADO_(colunasMatriz) (mat2) );
	
	for (unsigned int i = 0; i < TIPADO_(linhasMatriz) (resultado); i++)
	{
		for (unsigned int j = 0; j < TIPADO_(colunasMatriz) (resultado); j++)
		{	
			valor = (DESTE_TIPO_) 0;
			for (unsigned int k = 0; k < TIPADO_(colunasMatriz) (mat1) ; k++)
			{
				valor += TIPADO_(acessaMatriz) (mat1,i,k) * 
						 TIPADO_(acessaMatriz) (mat2,k,j);
			}
			TIPADO_(atribuiElemMatriz) (resultado,i,j,valor);
		}
	}
	return (resultado);
}



#endif /* TIPADO_        */
#endif /* DESTE_TIPO_    */
#endif /* DESTE_FORMATO_ */


