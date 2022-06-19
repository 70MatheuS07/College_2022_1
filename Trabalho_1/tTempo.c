#include "tTempo.h"

// Tá errado, mas no momento é válido.

int PegaTempo()
{
    long int result = 0, dia = 0, mes = 0, ano = 0;
    long int mytime = 0;

    mytime = time(NULL);

    printf("%ld\n", mytime);

    mytime = mytime / 100000;

    printf("%ld\n", mytime);

    return mytime;
}
