#include "tTempo.h"

// Tá errado, mas no momento é válido.

int PegaTempo()
{
    int result = 0;
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    return (tm.tm_mday + tm.tm_mon + 1 + tm.tm_year + 1900);
}