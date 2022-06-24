#include "tTempo.h"

/**
 * @brief Coleta os segundos que representa o dia.
 *
 * @return unsigned int
 */
unsigned int PegaTempo()
{
    long int mytime = 0;
    unsigned int tempo = 0;

    mytime = time(NULL);

    mytime = mytime / 86400;

    tempo = mytime;

    return tempo;
}
