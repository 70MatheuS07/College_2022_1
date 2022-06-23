#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tJogador tJogador;

typedef struct tLeitura tLeitura;

tJogador *CriaJogador();

void LehJogador_1(tJogador *jogador_1);

int EscolhaDeModo(tJogador *jogador);

void LiberaJogador(tJogador *jogador);

void ImprimeNomeJogadorCabecalho(tJogador *jogador);

void ImprimeAmbosJogadores(tJogador *jogador_1, tJogador *jogador_2);

void ImprimeEspacosJogador1(tJogador *jogador_1);

void ImprimeEspacosJogador2(tJogador *jogador_2);

void LehJogador_2(tJogador *jogador_1, tJogador *jogador_2);

int NomesIguais(tJogador *jogador_1, char nomeVerifica[10000]);

void ImprimeNomeJogador(tJogador *jogador);

void RegistraQtdJogos(tJogador *jogador);

void RegistraGanhouUmaTentativa(tJogador *jogador);

void RegistraGanhouDuasTentativas(tJogador *jogador);

void RegistraGanhouTresTentativas(tJogador *jogador);

void RegistraGanhouQuatroTentativas(tJogador *jogador);

void RegistraGanhouCincoTentativas(tJogador *jogador);

void RegistraGanhouSeisTentativas(tJogador *jogador);

void RegistraQtdDerrotas(tJogador *jogador);

void EscreveLehEstatistica(tJogador *jogador);

int ConfereNomeJogadorEstatistica(tJogador *jogador, tJogador *jogadores);

void EscreveJogadorEstatistica(tJogador *jogador, tJogador *leitura);

void ModificaJogadorEstatistica(tJogador *jogador, tJogador *lido);

void ImprimeEstatisticaJogador(tJogador *jogador);

void SalvaNome(tJogador *jogador, char nomeSalvo[21], int jogou);

void InicializaJogador(tJogador *jogador);

void ImprimeTodasEstatisticas();

void ClonaJogador(tJogador *lido, tJogador *jogadorLidoCopia);

void CriaArquivo();

int SlotJogadorVazio(tJogador *jogador);

void ClassificacaoParcial(tJogador *jogador);

void EscreveJogadorEstatisticaTXT(tJogador *jogador);

#endif