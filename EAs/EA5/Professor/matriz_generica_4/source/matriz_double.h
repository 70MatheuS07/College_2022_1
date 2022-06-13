#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef MATRIZ_H_INCLUDED /*tenho que fazer isso porque 
                          * os matriz.h terão que ser 
                          * incluídos várias vezes no
                          * main.c
                          * faremos isso uma vez para 
                          * cada tipo de dados básico
                          * usado  */

#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%f"
#define TIPADO_(THING) D_ ## THING
#include "matriz.h"
