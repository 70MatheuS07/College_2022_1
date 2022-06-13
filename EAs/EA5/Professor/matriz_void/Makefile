
#Como simplificação final, vamos usar as macros especiais $@ e $ ^, que são os lados esquerdo e direito de :, respectivamente, para tornar a regra geral de compilação mais geral. 


#Flags interessantes
#-Wall dispara todos os warnings em seu código
#-g necessário para avaliar o código do valgrind
#-lm obrigatorio caso utilize a biblioteca math.h
CC=gcc
CFLAGS=-I. -Wall -g  -lm

SRC = matriz.c progmat.c


matriz: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o matriz
