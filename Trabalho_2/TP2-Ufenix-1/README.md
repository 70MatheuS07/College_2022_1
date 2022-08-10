# Trabalho Prático  II - TEP - **Ufenix**
Prof. Vinícius Mota 
DI/UFES

**Data de entrega: 03/08/2022**

Local de entrega:
   - AVA.

## 1. Objetivos

Este  segundo trabalho visa reforçar o desenvolvimento das habilidades de  uso de ponteiros, arrays e memória dinâmica, além de exercitar o uso de genéricos com `void *`, ponteiros de função e manipulação de memória genérica. 

O foco maior estará  no uso de ponteiros de função em C
usando interfaces genéricas `void*` como um cliente. Para isto, iremos implementar um sistema com os comandos básicos de interface com arquivos. 

  ## 2. Visão geral do sistema

Neste trabalho iremos implementar o  **Ufenix**.  Seu primeiro sistema operacional!!!  

Como este é seu primeiro sistema operacional, o **Ufenix** contará  com apenas comandos básicos dos sistemas *Nix.  Para isto, você deverá implementar versões simplificadas dos seguintes comandos: `tail`, `uniq`, `ls` e o `sort`. As funções são incrementais e em seguida serão apresentados roteiros para facilitar o desenvolvimento de cada uma. 

O projeto inicial contém os seguintes arquivos:
 - `ufenixcat.c`,`ufenixtail.c`, `utils.c`, `ufenixls.c`, `ufenixsort.c`, `Ufenix.c`: Arquivos que deverão ser modificados para o trabalho.
 - `Makefile`: Compilador do trabalho.
 - `exemplos`: Diretório contendo exemplos.     
 

Você deverá implementar arquivos contendo uma main para cada comando, separadamente. 
A filosofia do Unix é se afastar da construção de programas monolíticos que fazem de tudo. Isto é, visa  a construção de programas para  comandos menores, cada um focado e simplificado para executar bem uma tarefa, no nosso caso, cada comando de filtro. Essas pequenas ferramentas são combinadas para realizar tarefas maiores, no nosso caso, o **Ufenix**. 

Você escreverá quatro dessas ferramentas nesta tarefa: `uniq`, `tail`,  `ls` e o `sort`. Além de algumas funções auxiliares. 
Cada ferramenta deve funcionar e ser testada de forma independente. 
 Em seguida, as unificará em um programa que simula um terminal e que permita o uso dos comandos de filtro implementados neste sistema. 

Deste modo, para cada comando deve haver uma regra no `Makefile` que permita compilar o teste separadamente.   Já o `Ufenix.c` contém a main do SO.  Este SO apresentará apenas um prompt de comando que ficará aguardando comandos válidos (como um terminal). 



**IMPORTANTE**:

  
 - É responsabilidade do desenvolvedor garantir que o programa faz uso eficiente da memória por meio do valgrind. 
 - É seu dever  como desenvolvedor filtrar erros de entrada dos usuários. Mesmo que não estejam listados aqui. Sempre comente essas verificações.
 - A compilação do executável deve ser por meio de um `Makefile`.
 - Código deve estar bem comentado.
 - É opcional "limpar o terminal" entre as passagens do menu de opções.
  
 ### Visão geral dos comandos Unix

Os comandos `uniq` e `tail` fazem parte de uma categoria especial de comandos chamados "filtros". Um filtro é um programa que lê a entrada (normalmente linha por linha) do usuário ou de um arquivo, transforma a entrada de alguma forma e produz alguma saída.

Alguns outros exemplos de filtros unix são `cat`, `sort` e `grep`. `cat` é o mais simples de todos os filtros; a saída apenas repete a entrada. Ao executar `cat nomearquivo`  imprimirá o conteúdo do arquivo. Se nenhum argumento de nome de arquivo for fornecido, o comando irá ler da entrada padrão (teclado). Isso significa que o programa lerá as linhas digitadas no terminal pelo usuário.

Abra um terminal e execute os filtros em um arquivo de exemplo para entendê-los:
 - `cat cores.txt`
 - `cat -b cores.txt`
 - `cat -b` sem um argumento de nome de arquivo. O programa irá esperar que você digite input. Digite uma linha de texto e pressione enter. Ele ecoa a linha com seu número de linha.  Quando você terminar de digitar sua entrada, pressione control-d. Isso sinaliza o fim da entrada (EOF para "fim do arquivo").
 - `uniq cores.txt` 

Uma dica: Todos os filtros  e funções padrões do C são bem documentados no Linux. Por exemplo, para encontrar a documentação  do cat use `man cat`, para a função `printf()` use `man printf`.

## 3. Tarefas

### 3.1: Revisão dos Códigos para as tarefas 3.2, 3.3 e 3.4
______
### *ufenixcat,  ufenixtail, e ufenixuniq*

 Todos os programas dependem da leitura de arquivos. A leitura de arquivos funciona de maneira semelhante. Sua primeira tarefa é estudar o código do programa fornecido, juntamente com sua referência C favorita para obter uma visão geral de como a leitura de arquivos funciona em C. 
 
 O programa `ufenixcat.c` está totalamente implementado. 
 
 Os arquivos `ufenixuniq.c` e `ufenixtail.c` contêm código para lidar com os argumentos da linha de comando e a configuração do arquivo, e você implementará o restante. 

 Você deve ler e entender o código fornecido, descobrir como alterá-lo/ampliá-lo para atender às suas necessidades e, finalmente, adicionar comentários para documentar sua estratégia.


____
###  3.2: Implementar a função `ler_linha`

A função de biblioteca padrão `fgets` é usada para ler o texto de um arquivo.

```
char *fgets(char *buf, int bufsize, FILE *stream);
```

Como a maioria das funções, `fgets` não faz nenhuma alocação; em vez disso, depende do cliente fornecer o buffer para gravação. O cliente deve pré-alocar memória com base em uma expectativa de qual tamanho será "grande o suficiente" para armazenar a linha. Se a escolha de tamanho do cliente for muito pequena, uma função de leitura de linha pode estourar o buffer (se você usar `gets`) ou truncar a linha de leitura (se você usar `fgets`).

Um *design* mais amigável para o cliente seria que a função de leitura tratasse a alocação internamente e criasse uma linha do tamanho apropriado. Você vai implementar uma função `ler_linha`:

`char *ler_linha(FILE *fp);`


A função `ler_linha` lê a próxima linha de um arquivo. O valor de retorno é uma string alocada dinamicamente e terminada em nulo (ou `NULL` se estiver em EOF, "fim do arquivo"). Esta função funciona como uma versão mais elegante do `fgets` (na verdade, internamente você deve implementá-la usando `fgets`!) na medida em que lê a próxima linha, mas essa versão também aloca o armazenamento.

Para alocar memória para a string retornada, a função deve fazer uma alocação inicial e ampliá-la sucessivamente, se necessário. Para ser mais específico, ele deve primeiro alocar um buffer de tamanho mínimo (32) e ler a primeira parte da linha no buffer, usando uma única chamada para `fgets`. Se houver mais para ler, ele deve realocar o buffer para dobrar seu tamanho atual (64) e fazer outra chamada para `fgets` para ler o restante da linha. Deve continuar assim, dobrando a alocação e lendo mais, até finalmente atingir a nova linha ou EOF que sinaliza o fim desta linha.
Se não conseguir alocar memória suficiente, `ler_linha` deve gerar uma mensagem de erro e sair do programa. 

Detalhes específicos do funcionamento da função:

- A função deve ler a próxima linha do arquivo.  Considera-se que uma linha termina após o primeiro caractere de nova linha ou EOF, o que ocorrer primeiro.
- A string retornada deve incluir os caracteres lidos até o caractere de nova linha, mas não deve incluir o próprio caractere de nova linha. Se a próxima linha consistir em apenas um caractere de nova linha, retorne uma string vazia.
- Se `ler_linha` atingir  EOF, significando que não há caracteres para serem lidos, a função deve retornar NULL. Observe que a condição EOF não pode ser verificada até que você tenha chamado `fgets`, porque é o processo de tentar ler além do final que aciona a condição EOF.
-  Este caso deve limpar qualquer alocação inicial que acabou não sendo necessária e retornar NULL.
- Se ocorrer um erro em `fgets`, a função deve retornar o que foi lido até aquele ponto, ou NULL se não tiver lido nada (dica: sua função pode acabar fazendo isso sem que você considere explicitamente este caso). 
- `ler_linha` deve retornar o endereço de memória alocado dinamicamente armazenando a próxima linha. O cliente é responsável por desalocar essa memória com free quando não for mais necessária.
Você deve usar apenas a função de E/S do arquivo `fgets`.

Escreva sua implementação de *ler_linha* no arquivo *util.c*. Você pode testá-lo usando nosso programa `ufenixcat.c` fornecido. Mais tarde, a função `ler_linha` para escrever os programas `ufenixtail` e `ufenixuniq`.


### 3.3 Implementar a função e o programa `ufenixtail`

O programa `ufenixtail` deverá ser semelhante em operação ao tail padrão com as seguintes diferenças:

- `ufenixtail` suporta apenas uma opção de linha de comando, -N, onde N é o número de linhas para saída
- `ufenixtail` lê apenas um arquivo passado como argumento.
- Para alcançar as N linhas que o usuário deseja ver,  você deve usar um array de N entradas. Essa matriz contém as N linhas mais recentes lidas. A matriz é uma "janela deslizante" de N linhas que está se movendo pela entrada. Quando `ufenixtail` chegar ao final da entrada, a janela conterá as N linhas finais. 
- Quando `ufenixtail` começar a processar a entrada, ele lerá as primeiras N linhas no array usando sua função `ler_linha`. Ao ler a N+1ª linha, ele não deve ampliar o array, mas sim descartar a 1ª linha (que é a mais antiga) da entrada e usar esse slot do array para o N+1º. O N+2 substitui a segunda linha e assim por diante. Desta forma, o array é usado como uma espécie de fila circular que a qualquer momento armazena no máximo as N linhas mais recentes lidas.

Os desafios na implementação deste programa são a lógica da fila circular, bem como o cuidado com as strings que estão sendo alocadas e desalocadas.

Exemplo de uso:
``` 
ufenix$  cat cores.txt
vermelho
verde
verde
amarelo
azul
azul
azul
azul
ufenix$  tail -3 cores.txt
azul
azul
azul
```

### 3.4 Implementar a função e o programa `ufenixuniq`

O programa `ufenixuniq` será semelhante em operação ao `uniq` padrão com algumas diferenças:

- `ufenixuniq` filtra todas as linhas duplicadas, não importa onde elas apareçam na entrada;
- Apenas uma cópia de cada linha exclusiva é impressa.
-  As linhas exclusivas são impressas na mesma ordem em que apareceram na entrada.
- `ufenixuniq` sempre prefixa cada linha de saída com sua contagem de ocorrências na entrada (este é o comportamento do uniq padrão quando invocado com o flag -c)
- ufenixuniq não suporta flags de linha de comando.
  
Para detectar linhas repetidas em qualquer lugar na entrada, o `ufenixuniq` deve acompanhar todas as linhas que viu enquanto se move pela entrada. Ele também precisará contar a frequência para cada linha. 
Você pode usar uma matriz  para armazenar essas informações. Contudo, quantas entradas precisamos para este array? Ao contrário do `ufenixtail`, que sabia de antemão o número exato de entradas a serem alocadas, o `ufenixuniq` está no escuro. Pode precisar de uma matriz de 10 entradas ou 10.000. Qualquer escolha fixa arbitrária será muito grande para algumas entradas e muito pequena para outras. 

A estratégia para o  `ufenixuniq` é alocar o array para 100 entradas como estimativa inicial e, se/quando isso for preenchido, redimensionar o array para adicionar mais 100 entradas. Em seguida, repita isso conforme necessário, adicionando 100 entradas adicionais a cada vez.

Para corresponder ao formato de saída da solução de amostra, ao imprimir o número de contagem de linhas, você deve usar o formato printf %7d em vez de apenas %d. Isso imprimirá o número com largura 7, o que significa que a saída será algo como:

```
      1 vermelho
   5000 azul
  12413 verde
1253473 amarelo
``` 

### 3.5 Implementação do `ufenixls`

A implementação do `ls` imprimirá o conteúdo dos diretórios de várias maneiras. Contudo, serão implementados menos opcionais do que o `ls`.

Para implementar o ls, é necessário entender a função `scandir`. Use `man scandir` para ver exemplos de uso.

#### 3.5.1 Estudar Código scandir 

Eara implementar o `ls`, você precisará ser um cliente da função `scandir`, que é usada para criar uma listagem de diretórios (um array de strings do conteúdo de um diretório) para um determinado caminho. Ele também usa dois ponteiros de função: uma função de filtro que controla quais entradas incluir na lista e uma função de comparação que controla a ordem das entradas na lista.

A compreensão do scandir é fundamental para a implementação do ufenixls, então antes de usá-lo, vamos ver como a função é implementada.

Uma implementação de scandir (da [musl](http://www.musl-libc.org/)) é mostrada abaixo. 

Esta função revela a alma interna de C (ponteiros de função, alocação dinâmica, ponteiro triplo!). Vá devagar, faça desenhos e tente rodar exemplos simples da `scandir`.

```C
1    int musl_scandir(const char *path, struct dirent ***res,
 2       int (*sel)(const struct dirent *),
 3       int (*cmp)(const struct dirent **, const struct dirent **)) {
 4        
 5        DIR *d = opendir(path);
 6        struct dirent *de;
 7        struct dirent **names = NULL;
 8        struct dirent **tmp;
 9        size_t cnt = 0;
10        size_t len = 0;
11
12        if (!d) {
13            return -1;
14        }
15
16        while ((de = readdir(d))) {
17            if (sel && !sel(de)) {
18                continue;
19            }
20            if (cnt >= len) {
21                len = 2 * len + 1;
22                if (len > SIZE_MAX / sizeof(*names)) {
23                    break;
24                }
25                tmp = realloc(names, len * sizeof(*names));
26                if (!tmp) {
27                    break;
28                }
29                names = tmp;
30            }
31            names[cnt] = malloc(de->d_reclen);
32            if (!names[cnt]) {
33                break;
34            }
35            memcpy(names[cnt++], de, de->d_reclen);
36        }
37
38        closedir(d);
39
40        if (errno) {
41            if (names) {
42                while (cnt-- > 0) {
43                    free(names[cnt]);
44                }
45            }
46            free(names);
47            return -1;
48        }
49        if (cmp) {
50            qsort(names, cnt, sizeof *names, 
51                (int (*)(const void *, const void *))cmp);
52        }
53        *res = names;
54        return cnt;
55    }
```

Não é necessário enviar respostas para essas perguntas, apenas trabalhe com elas para sua própria compreensão.

- Use `man readdir` para ver a definição do `struct dirent`. A parte `d_name` terá um tamanho personalizado para caber no nome de arquivo de uma entrada específica, incluindo um terminador nulo.
- Destaque os tipos de cada um dos argumentos da função. Desenhe uma imagem do layout de memória e variáveis da função  `scandir` incluindo todos os parâmetros e variáveis ​​locais. 
-  Use este diagrama ao rastrear o código para ver o que está acontecendo com a memória.
- Esse parâmetro de três ponteiros  é bastante assustador. Para que serve este parâmetro? Por que precisa de um ponteiro triplo? (Dica: dê uma olhada na linha 53, onde esse parâmetro é usado. O que o código está fazendo lá? Pense também no padrão que discutimos na aula de passar um ponteiro para algo se o chamador quiser permitir que ele seja modificado em uma função).
- Como um cliente indica que não deseja nenhuma filtragem aplicada à listagem de diretórios? Sem classificação?
- Um resultado diferente de zero da função de *callback* do filtro `sel` faz com que uma entrada seja mantida ou descartada da lista?
- O número de entradas de diretório não é conhecido antecipadamente, então o `scandir` aloca o array usando a estratégia de alocação clássica "*resize-as-you-go*". Este código deve parecer familiar, mas há alguns detalhes a serem examinados de perto:
    - Chama `realloc` na linha 25 sem ter feito uma chamada inicial para malloc. Por que isso é válido? (Dica: revise a página do manual `realloc` para ver como esse caso específico é tratado).
  - Usa a expressão `len * sizeof(*names)` para calcular o número total de bytes. Se names for NULL, essa expressão parece estar desreferenciando um ponteiro NULL, mas lembre-se de que `sizeof` não avalia o tipo, apenas informa o tamanho desse tipo.
 - A expressão de tamanho poderia ter sido escrita equivalentemente como `len * sizeof(struct dirent *)`. Qual é o benefício de usar `sizeof(*names)` em vez de nomear explicitamente o tipo?
 - Na linha 25, ele atribui o valor de retorno de `realloc` para tmp e duas linhas depois cópia do ponteiro de tmp para names. Por que não apenas atribui diretamente aos nomes?
- As linhas 31-35 fazem uma cópia heap de um `struct dirent`. Por causa do campo `d_name` de tamanho variável (veja o primeiro problema acima), ele aloca e copia um tamanho personalizado.
 - A linha 40 refere-se a um errno misterioso que sai do campo esquerdo. Leia man 3 errno para saber mais sobre seu propósito e função. Se ocorrer uma falha de alocação, qual será o valor de errno? (Dica: leia a seção NOTAS da página de manual do `malloc`)
- A linha 50/51 é um pouco difícil de analisar, mas está aplicando um typecast ao ponteiro de função que está sendo passado para `qsort`. Tente compilar o código com e sem o cast. Que aviso/erro você recebe sem o elenco? 
- A função de filtro `scandir` recebe seu argumento como` const struct dirent *;` a função de comparação recebe seus argumentos como `const struct dirent **`. Por que a incoerência?
- Rastreie as várias chamadas malloc/free para entender qual memória é alocada e desalocada dentro da função. Que desalocação ainda precisa ser feita após a saída da função? Quais são as etapas adequadas para o chamador liberar adequadamente essa memória?

### 3.5.2 Implementar o `ufenixls`

O programa `ufenixls` opera de forma semelhante ao `ls` padrão, mas com muitas simplificações e algumas diferenças.  A lista abaixo enumera os recursos necessários para `ufenixls`:

- `ufenixls` recebe zero ou mais caminhos de diretório como argumentos. Ele lista as entradas de diretório de cada caminho. Se invocado sem argumentos, ufenixls imprime as entradas do diretório atual (.)
- `ufenixls` suporta apenas caminhos de diretório como argumentos. Se um argumento se referir a um arquivo ou caminho inexistente, ele deve imprimir uma mensagem de erro e pular esse argument:
   
    "não é possível acessar _____", preenchendo o nome do argumento inválido, juntamente com um código de erro 0 e um código de status 0 (para que o programa ainda continua rodando).

- `ufenixls` imprime as entradas uma por linha.
- `ufenixls` ignora entradas cujos nomes começam com '.' a menos que seja invocado com o flag -a
- Adiciona uma barra final ao imprimir o nome de uma entrada que é um diretório.
- imprime as entradas em um diretório ordenado por nome. Os nomes são comparados lexicograficamente (ou seja, strcmp). Se invocado com o sinalizador -z, a ordem de classificação será por tipo (diretórios à frente de não-diretórios). As entradas do mesmo tipo são classificadas por nome.
- o `ufenixls` não suporta outros flags de linha de comando além de -a e -z.
- Deve chamar a função scandir padrão e não reimplementar sua funcionalidade. Dado que o scandir já é quase um programa ls, você só precisa escrever as funções de filtro/comparação, fazer uma única chamada para scandir e imprimir a lista resultante.
-  Como nota adicional, a página man do `scandir` contém um pequeno programa de exemplo. 



### 3.6 Implementar o `ufenixSort`

 você implementará sua própria versão do comando Unix sort, chamado `ufenixsort`, que usa sua função `binserir` como cliente.  A classificação padrão do Unix lê a entrada linha por linha e, em seguida, imprime as linhas em ordem ordenada. Ele oferece suporte a vários flags de linha de comando que controlam o comportamento de classificação. Experimente os seguintes comandos:

```
sort cores.txt
sort -u -r cores.txt
```

O programa `ufenixsort` opera de maneira semelhante à classificação padrão, mas com muitas simplificações e algumas diferenças. Seguem os requisitos do `ufenixsort`:

- `ufenixsort` lê um arquivo; o arquivo nomeado (se especificado como um argumento);
- A ordem de classificação padrão para `ufenixsort` é a ordem lexicográfica (alfabética).
- Flags:
  - -l, a ordem de classificação é o tamanho o comprimento da linha.
  - -n, a ordem de classificação é por valor numérico de string (aplica `atoi` a cada linha e compara números).
  - -r, a ordem de classificação para `ufenixsort` é invertida. (Dica: classifique a entrada como faria normalmente e apenas altere a ordem em que você imprime os resultados).
  - -u, `ufenixsort` descarta linhas duplicadas. A saída classificada contém uma instância de cada linha exclusiva da entrada.
  
- Não há desempate. Linhas duplicadas, ou seja, linhas que se comparam como iguais de acordo com a ordem de classificação, podem ser geradas em qualquer ordem.
- Os flags para `ufenixsort` podem ser usados ​​sozinhos ou em combinação. Se ambos -l e -n forem usados, o *flag* que estiver por último na linha de comando "ganha" como ordem de classificação.

`ufenixsort.c` é fornecido  com u código para lidar com os argumentos da linha de comando. Antes de iniciar o programa, primeiro leia e entenda o código fornecido, descubra como incorporá-lo e, finalmente, adicione comentários para documentar sua estratégia e o código. O código inicial para esta tarefa destina-se a ajudá-lo a continuar, mas você pode remover/alterar esse código como preferir.

    Processar argumentos de linha de comando é um trabalho árduo. A extensão GNU `getopt` ajuda a limpá-lo um pouco. Use `man 3 getopt` para saber mais sobre como ele funciona.

### 3.7 Implementando o Ufenix

Nesta última tarefa você irá implementar um programa que simula um terminal unix, permitindo apenas os comandos implementados acima. 

Na versão do Ufenix, você pode fazer as chamadas utilizando os nomes padrões:

- cat
- ls 
- tail
- uniq
- sort


## 4. Compilação e execução

O arquivo `Makefile` compila e gera o executável para cada comando e para o  `ufenix`. 

Para testar cada comando, execute o nome do comando

    ./ufenixcat  

Para rodar o Ufenix, execute o comando

    ./ufenix

O ufenix aguarda os comandos implementados a partir do diretório em que foi executado.


## 5. Regras Gerais

O trabalho pode ser feito **em dupla** e pelos próprios alunos, isto é, os alunos deverão necessariamente conhecer e dominar todos os trechos de código criados. 

Cada dupla deverá trabalhar independente das outras, não sendo permitido a cópia ou compartilhamento de código. O professor irá fazer verificação automática de plágio. Trabalhos identificados como iguais, em termos de programação, serão penalizados com a nota zero. Isso também inclui a dupla que forneceu o trabalho, sendo, portanto, de sua obrigação a proteção de seu trabalho contra cópias ilícitas. 

## 6. Entrega do Trabalho

O trabalho deverá ser submetido pelo Repl.it  e também pelo AVA até  as 23:59 do dia 03/08/2022. 

O arquivo enviado pelo AVA deve  seguir o padrão: PROG2-2022_MATRICULA1_MATRICULA2.zip, substituindo a matrícula pelos respectivos números de matrícula da dupla.  
O arquivo zip deve conter:
- Todos os arquivos necessários para compilação (cabeçalhos e códigos fontes)
- `Makefile` que compile o programa corretamente em um ambiente Linux.
- `README.md` contendo nome da dupla e com considerações de projeto que julgue necessário, incluindo as decisões de projeto tomadas. Por exemplo, explicação breve das bibliotecas,  etc.
 
O código fonte deverá estar bem comentado, isto é, todas os structs e funções devem ter descrições claras do que ela faz, o que representa cada parâmetro e o que ela retorna (se houver).  Pode-se adicionar também comentários que ajude a entender a lógica da  questão.



## 7. Avaliação

O trabalho será corrigido em dois turnos: correção do professor e entrevista. A correção do professor (CP) gerará uma nota entre 0 e 10 e as entrevistas (E) serão realizadas posteriormente à data de entrega do trabalho e será atribuída uma nota entre 0 e 1. Alunos que fizeram o trabalho em dupla farão a entrevista juntos, porém terão seus desempenhos na entrevista avaliados de forma individual. Pequenas e pontuais correções de código serão permitidas no momento da entrevista, o que poderá acarretar em uma CP maior.

A nota final (NF) do trabalho será dada pela seguinte fórmula: NF = E * CP

O trabalho será pontuado de acordo com sua funcionalidade e outros aspectos de implementação, conforme as listas abaixo.

### Aspectos funcionais

Os filtros terão os seguintes pesos nas notas:

 - (20%) `ufenixtail`
 - (20%) `ufenixuniq`
 - (20%) `ufenixsort`
 - (25%) `ufenixls`
 - (15%) ufenix completo


Cada filtro implementado será avaliado da seguinte forma:


1. (20%)  Testes exemplos: Os filtros executam os testes simples disponibilizados.
2. (20%) Testes de stress: Resultados corretos para testes que stressem o programa, como arquivos com linhas maiores.
3. (20%) Eficiência de memória: O código deve rodar limpo no valgrind. Serão admitidos apenas erros que sejam ocasionados por funções internas do C, por exemplo a fgets(). 
   1. Este trabalho exige muito de alocação dinâmica e ponteiros. Logo, um dos aspectos você deverá garantir que seu código é livre de erros de contexto e de vazamento de memória. 

    Isto é, abuse do valgrind para garantir que o programa é error-free. 

### Aspectos de desenvolvimento:

Considerando que as saídas dos programas são relativamente simples, os códigos serão inspecionados e devem conter o seguinte:

1.(10%) Uso correto de ponteiros e alocação de memória.  O uso incorreto de declaração  estática de vetores será penalizado em até 100% da nota. 
2. (5%) Código legível. Variáveis com nomes claros, usar constantes ao invés de números mágicos.
3. (5%) Qualidade da documentação. Fazer comentários que indiquem claramente, como o código funciona e como usar as funções implementadas. 
