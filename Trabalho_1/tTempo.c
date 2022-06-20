#include "tTempo.h"

// Pega os segundos dado pela maquina, para sortear uma palavra.
unsigned int PegaTempo()
{
    long int mytime = 0;
    unsigned int tempo=0;

    mytime = time(NULL);

    mytime = mytime / 86400;

    tempo = mytime;

    return tempo;
}
