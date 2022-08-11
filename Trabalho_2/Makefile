# Makefile simples para o TP2


PROGRAMS =  ufenixcat ufenixtail ufenixuniq ufenixls ufenixsort ufenix

all:: $(PROGRAMS)
DEPS=ufenixcat.h ufenixtail.h ufenixuniq.h ufenixls.h ufenixsort.h prototipos.h

CC = gcc
CFLAGS = -g -O0  -Wall $$warnflags
export warnflags = -Wfloat-equal -Wtype-limits -Wpointer-arith -Wlogical-op -Wshadow -fno-diagnostics-show-option
LDFLAGS =
LDLIBS =

$(PROGRAMS): %:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@ $(DEPS)

 ufenixcat ufenixtail ufenixuniq ufenixls ufenixsort: ler_linha.c
 ufenix: ufenixcat_imp.c ufenixtail_imp.c ufenixuniq_imp.c ufenixls_imp.c ufenixsort_imp.c ler_linha.c

clean::
	rm -f $(PROGRAMS) *.o

.PHONY: clean all
