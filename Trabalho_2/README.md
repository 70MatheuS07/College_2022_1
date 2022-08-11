## Trabalho Prático 2 - Ufenix

`Alunos:` Yan Oliveira Maia e Matheus de Oliveira Lima

`Objetivo:` Desenvolver alguns arquivos .c pré-montados com o intuito de executar algumas operações feitas no terminal do Linux (inicialmente de maneira individual), são eles: cat, ls, sort, tail e uniq. Com os arquivos prontos, o próximo passo era montar um mini sistema operacional chamado Ufenix, que executaria os arquivos desenvolvidos.

`Considerações:`  Inicialmente desenvolvemos o ler_linha.c que é base para a construção de vários arquivos. Segue abaixo a sequência de funções (cada uma no seu respectivo .c) que foram desenvolvidas no trabalho:

- `ufenix_cat:` foi finalizado assim que terminamos de programar o ler_linha.c.

- `ufenix_tail:` adotamos o método de "Janela deslizante" para conseguir imprimir no terminal a quantidade correta de linhas requisitadas.

- `ufenix_uniq:` adotamos o método de "Varredura" para conseguir conferir todas as linhas que podiam ser duplicadas, retirá-las e guardar a quantidade de linhas iguais para fazer a impressão no terminal.

- `ufenix_sort:` foi criada uma matriz do tipo char para armazenar as linhas correspondentes do arquivo passado via argumento. E dentro da função "ufenix_sort" também foi feito condicionais com base nas flags.

- `ufenix_ls`: foi criado uma struct dirent **. Por meio da função scandir foi feito a armazenagem das informações dos diretórios ordenadamente na struct. Alguns parâmetros da função scandir foram implentados para ordenar ou armazenar os diretórios de acordo com as flags.


Para a implementação do Ufenix.c foi necessário modificar os arquivos .c: ufenixcat.c, ufenixls.c, ufenixsort.c, ufenixtail.c e ufenixuniq.c para criar os arquivos, respectivamente: ufenixcat_imp.c, ufenixls_imp.c, ufenixsort_imp.c, ufenixtail_imp.c e ufenixuniq_imp.c. Porque era necessário trocar o nome da função "main" para torná-los funções a serem usadas na "main" do arquivo "ufenix.c".


Foram feitos vários testes manuais para saber se as respostas estavam saindo corretas e testes tentando se há vazamentos de memória.

Em um caso específico acontece um erro no getopt do "ufenixsort_imp.c" e "ufenixsort_imp.c". Ao executar qualquer um dos dois comandos mais de uma vez com flags diferentes, ocorre um erro no getopt apartir da segunda vez que executa outra linha de comando. Segue exemplo abaixo:

ls -a

ls -a

Dentro da função "mainUfenix_ls" eu fiz um debug momentâneo que imprimia no terminal os argumentos antes de entrar no "loop" que contém a função "getopt" e sai os argumentos corretamente, porém o case é dado como "default" e executa o "exit(1)".

Esse erro ocorre da mesma maneira com o ufenixsort_imp.c