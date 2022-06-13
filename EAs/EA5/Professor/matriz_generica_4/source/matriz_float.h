#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_
#undef MATRIZ_H_INCLUDED /*tenho que fazer isso porque 
                          * os matriz.h terão que ser 
                          * incluídos várias vezes no
                          * main.c */

#define DESTE_TIPO_ float
#define DESTE_FORMATO_ "%f"
#define TIPADO_(THING) F_ ## THING
#include "matriz.h"
