#include "tTempo.h"

// Pega os segundos dado pela maquina, para sortear uma palavra.
int PegaTempo()
{
    long int mytime = 0;

    mytime = time(NULL);

    mytime = mytime / 100000;

    return mytime;
}
