# C

'Hello World' em C:
```C
#include <stdio.h>

int main()
{
    printf("Welcome to the guessing game");
}
```

Esses arquivos que importamos com extesão .h são chamados de header files.

Compilando:
```shell
gcc Program.c -o Program<.exe>
```
>No Windows, podemos usar a extensão .exe. No Linux, podemos usar uma extesão diferente do arquivo original, apenas para facilitar a vida.  

Executando:
```shell
./guessing.out
```
Comentários são adicionados com **//**.  

Em C, booleanos são do tipo int: 0 para false e 1 para true.  
Usamos o mesmo conceito de variáveis ficarem acessíveis ao bloco em que foram declaradas.  

Sintaxe do for:
```C
    for (int i = 1; i <= 5; i++)
    {
        //code here
    }
```

Declaramos constantes em C da seguinte forma:

```C
#include <stdio.h>

#define NUMBER_OF_TRIES 3 //constante

int main(){
    //...
}
```

Em C, o compilador não gera erro ao utilizar uma variável que não foi utilizada.  
Sempre utilize variáveis inicializadas com valor.  
Quando se utiliza uma variável que não foi inicializada, não sabemos qual valor conterá nela.  
Isso depende um pouco do compilador utilizado.  
Em alguns casos, pode acontecer de ser impresso um valor que é resultado da 'sujeira' de um programa anterior.  

Podemos utilizar interpolação de strings com uma marcação que indica o tipo da variável e sua respectiva varíavel como parâmetro:

```C
printf("You took %d tries to beat the game!\n", tries); //cada variável possui um tipo
printf("Final points: %f!\n", points);
```

Podemos fazer casting informando o tipo desejado na frente davariável.
```C
double value = (double)2; 
```
>Em C, não há restrição e podemos transformar um tipo que cabe mais informação em um tipo que cabe menos informação, como de double para int.

Em C não temos strings. Utilizamos array de chars.

```c
char secretWord[20];
sprintf(secretWord, "WATERMELON");
printf("%s\n", secretWord);
```
>para o printf saber quando parar, podemos atribuir um char '\0' depois de inserir o texto desejado no array.

Podemos utilizar a estrutura do {...} while():

```c
do
{
    //code
} while (!guessed && !hanged);
```

Quando utilizar a função scanf para ler char do teclado, deixe um espaço, para indicar que não quer que a tecla enter seja considerada.  
```c
scanf(" %c", &letter);
```

## Bits, Bytes, Hexadecimal

No computador, tudo é representado de maneira binária (0 ou 1 - sem energia, com energia - ligado, desligado).  
Desse modo, os números não são representados de forma decimal mas sim de forma binária:  
Em decimal, faríamos: 1, 2, 3 .. 9, 10.  
Quando chegamos no 9, não temos mais um novo número para representar o dez. Dessa forma, utilizamos 1 e 0, números que já temos disponíveis, para fazer essa representação.  
Em binários, só temos 0 e 1. Então, as representações ficam assim:  0, 1, 10, 11, 100.  
Com hexadecimal, podemos utilizar os números de 0 a 9 e depois as letras de A a F, nos dando 16 possibilidades por posição.  
Isso nos possibilita representar o número 255, por exemplo, como FF. A base hexadecimal é muito usado por exemplo em escala de cor RGB.  
Ambos representam 1 byte, pois para representar uma letra, temos que ter uma definição de combinação de números para letras, por exemplo:  
Letra A vai ser o número 65. O número 65 é representado em binário assim 01000001.  
A tabela que guarda essas informações é a tabela ASCII (American Standard Code for Information Interchange).  

| Decimal | Binário | Hexadecimal |
| :-:     | :-:     | :-:         |
| 0       | 0       | 0           |  
| 1       | 1       | 1           |
| 2       | 10      | 2           |
| 3       | 11      | 3           |
| 4       | 100     | 4           |
| 9       | 1001    | 9           |
| 10      | 1010    | A           |
| 11      | 1011    | B           |
| 255     | 11111111| FF          |

Cada número binário representa um **bit**.  
Um **byte** é um conjunto de 8 bits. Ou seja:  
10000000 = 1 byte.  

Foi optado por usar 8 bits para formar um byte pois, antigamente, os processadores apenas conseguiam guardar 8 bits em um espaço de memória.  
Isso limitava as possbilidades a 256: 11111111 = 255 = 2^8.  As opções vão de 0 a 255.  

Podemos usar a mesma lógica usada para representar letras com binários para representar cores, música, etc.  


## ASCII

### Sinais de controle (não-imprimíveis)

|  Binário  | Oct	    | Decimal | Hexa | Abrev	|Not. Circunflexo | Cód. Escape | Nome                                                                   |
|  :-:      | :-:       | :-:     | :-:  | :-:      | :-:             | :-:         | :-:                                                                    |                                           
| 0000 0000 | 000	    | 00	  | 00	 | NULL	    | ^@              | \0	        | Nulo (inglês Null)                                                     |
| 0000 0001 | 001	    | 01	  | 01	 | SOH	    | ^A              |	            | Início de cabeçalho (inglês Start of Header)                           |
| 0000 0010 | 002	    | 02	  | 02	 | STX	    | ^B              |	            | Início de texto (inglês Start of Text)                                 |
| 0000 0011 | 003	    | 03	  | 03	 | ETX	    | ^C              |	            | Fim de texto (inglês End of Text)                                      |
| 0000 0100 | 004	    | 04	  | 04	 | EOT	    | ^D              |	            | Fim de transmissão (inglês End of Transmission)                        |
| 0000 0101 | 005	    | 05	  | 05	 | ENQ	    | ^E              |	            | Consulta; inquirição (inglês Enquiry)                                  |
| 0000 0110 | 006	    | 06	  | 06	 | ACK	    | ^F              |	            | Confirmação (inglês Acknowledge)                                       |
| 0000 0111 | 007	    | 07	  | 07	 | BEL	    | ^G              | \a	        | Campainha; sinal sonoro (inglês Bell)                                  |
| 0000 1000 | 010	    | 08	  | 08	 | BS	    | ^H              | \b	        | Espaço atrás; retorno de 1 caractere (inglês Back-space)               |
| 0000 1001 | 011	    | 09	  | 09	 | HT	    | ^I              | \t	        | Tabulação horizontal (inglês Horizontal Tabulation)                    |
| 0000 1010 | 012	    | 10	  | 0A	 | LF	    | ^J              | \n	        | Alimentação de linha; mudança de linha; nova linha (inglês Line Feed)  |
| 0000 1011 | 013	    | 11	  | 0B	 | VT	    | ^K              | \v	        | Tabulação vertical (inglês Vertical Tabulation)                        |
| 0000 1100 | 014	    | 12	  | 0C	 | FF	    | ^L              | \f	        | Alimentação de formulário (inglês Form Feed)                           |
| 0000 1101 | 015	    | 13	  | 0D	 | CR	    | ^M              | \r	        | Retorno do carro; retorno ao início da linha (inglês Carriage Return)  |
| 0000 1110 | 016	    | 14	  | 0E	 | SO	    | ^N              |	            | Mover para fora; deslocamento para fora (inglês Shift Out)             |
| 0000 1111 | 017	    | 15	  | 0F	 | SI	    | ^O              |	            | Mover para dentro; deslocamento para dentro (inglês Shift In)          |
| 0001 0000 | 020	    | 16	  | 10	 | DLE	    | ^P              |	            | escape do linque de dados; escape de conexão (inglês Data-Link Escape) |
| 0001 0001 | 021	    | 17	  | 11	 | DC1	    | ^Q              |	            | Controle de dispositivo 1 (inglês Device Control 1)                    |
| 0001 0010 | 022	    | 18	  | 12	 | DC2	    | ^R              |	            | Controle de dispositivo 2 (inglês Device Control 2)                    |
| 0001 0011 | 023	    | 19	  | 13	 | DC3	    | ^S              |	            | Controle de dispositivo 3 (inglês Device Control 3)                    |
| 0001 0100 | 024	    | 20	  | 14	 | DC4	    | ^T              |	            | Controle de dispositivo 4 (inglês Device Control 4)                    |
| 0001 0101 | 025	    | 21	  | 15	 | NAK	    | ^U              |	            | Confirmação negativa (inglês Negative-Acknowledge)                     |
| 0001 0110 | 026	    | 22	  | 16	 | SYN	    | ^V              |	            | Estado ocioso síncrono; espera síncrona (inglês Synchronous Idle)      |
| 0001 0111 | 027	    | 23	  | 17	 | ETB	    | ^W              |	            | Bloco de fim de transmissão (inglês End of Transmission Block)         |
| 0001 1000 | 030	    | 24	  | 18	 | CAN	    | ^X              |	            | Cancelar (inglês Cancel)                                               |
| 0001 1001 | 031	    | 25	  | 19	 | EM	    | ^Y              |	            | Fim de mídia; fim do meio (inglês End of Medium)                       |
| 0001 1010 | 032	    | 26	  | 1A	 | SUB	    | ^Z              |	            | Substituir (inglês Substitute)                                         |
| 0001 1011 | 033	    | 27	  | 1B	 | ESC	    | ^[              |	            | Escapar (inglês Escape)                                                |
| 0001 1100 | 034	    | 28	  | 1C	 | FS	    | ^\              |	            | Separador de arquivos (inglês File Separator)                          |
| 0001 1101 | 035	    | 29	  | 1D	 | GS	    | ^]              | \e	        | Separador de grupos (inglês Group Separator)                           |
| 0001 1110 | 036	    | 30	  | 1E	 | RS	    | ^^              |	            | Separador de registros (inglês Record Separator)                       |
| 0001 1111 | 037	    | 31	  | 1F	 | US	    | ^_              |	            | Separador de unidades (inglês Unit Separator)                          |
| 0111 1111 | 177	    | 127     | 7F   | DEL	    | ^?              |	            | Deletar (inglês Delete)                                                |

### Sinais Gráficos (imprimíveis)

| Binário   | Oct | Dec | Hex | Sinal    | Binário   | Oct | Dec | Hex | Sinal | Binário   | Oct | Dec | Hex | Sinal |
| :-:       | :-: | :-: | :-: | :-:      | :-:       | :-: | :-: | :-: | :-:   | :-:       | :-: | :-: | :-: | :-:   |
| 0010 0000 | 040 | 32  | 20  | (espaço) | 0100 0000 | 100 | 64  | 40  | @     | 0110 0000 | 140 | 96  | 60  | `     |
| 0010 0001 | 041 | 33  | 21  | !        | 0100 0001 | 101 | 65  | 41  | A     | 0110 0001 | 141 | 97  | 61  | a     |
| 0010 0010 | 042 | 34  | 22  | "        | 0100 0010 | 102 | 66  | 42  | B     | 0110 0010 | 142 | 98  | 62  | b     |
| 0010 0011 | 043 | 35  | 23  | #        | 0100 0011 | 103 | 67  | 43  | C     | 0110 0011 | 143 | 99  | 63  | c     |
| 0010 0100 | 044 | 36  | 24  | $        | 0100 0100 | 104 | 68  | 44  | D     | 0110 0100 | 144 | 100 | 64  | d     |
| 0010 0101 | 045 | 37  | 25  | %        | 0100 0101 | 105 | 69  | 45  | E     | 0110 0101 | 145 | 101 | 65  | e     |
| 0010 0110 | 046 | 38  | 26  | &        | 0100 0110 | 106 | 70  | 46  | F     | 0110 0110 | 146 | 102 | 66  | f     |
| 0010 0111 | 047 | 39  | 27  | '        | 0100 0111 | 107 | 71  | 47  | G     | 0110 0111 | 147 | 103 | 67  | g     |
| 0010 1000 | 050 | 40  | 28  | (        | 0100 1000 | 110 | 72  | 48  | H     | 0110 1000 | 150 | 104 | 68  | h     |
| 0010 1001 | 051 | 41  | 29  | )        | 0100 1001 | 111 | 73  | 49  | I     | 0110 1001 | 151 | 105 | 69  | i     |
| 0010 1010 | 052 | 42  | 2A  | *        | 0100 1010 | 112 | 74  | 4A  | J     | 0110 1010 | 152 | 106 | 6A  | j     |
| 0010 1011 | 053 | 43  | 2B  | +        | 0100 1011 | 113 | 75  | 4B  | K     | 0110 1011 | 153 | 107 | 6B  | k     |
| 0010 1100 | 054 | 44  | 2C  | ,        | 0100 1100 | 114 | 76  | 4C  | L     | 0110 1100 | 154 | 108 | 6C  | l     |
| 0010 1101 | 055 | 45  | 2D  | -        | 0100 1101 | 115 | 77  | 4D  | M     | 0110 1101 | 155 | 109 | 6D  | m     |
| 0010 1110 | 056 | 46  | 2E  | .        | 0100 1110 | 116 | 78  | 4E  | N     | 0110 1110 | 156 | 110 | 6E  | n     |
| 0010 1111 | 057 | 47  | 2F  | /        | 0100 1111 | 117 | 79  | 4F  | O     | 0110 1111 | 157 | 111 | 6F  | o     |
| 0011 0000 | 060 | 48  | 30  | 0        | 0101 0000 | 120 | 80  | 50  | P     | 0111 0000 | 160 | 112 | 70  | p     |
| 0011 0001 | 061 | 49  | 31  | 1        | 0101 0001 | 121 | 81  | 51  | Q     | 0111 0001 | 161 | 113 | 71  | q     |
| 0011 0010 | 062 | 50  | 32  | 2        | 0101 0010 | 122 | 82  | 52  | R     | 0111 0010 | 162 | 114 | 72  | r     |
| 0011 0011 | 063 | 51  | 33  | 3        | 0101 0011 | 123 | 83  | 53  | S     | 0111 0011 | 163 | 115 | 73  | s     |
| 0011 0100 | 064 | 52  | 34  | 4        | 0101 0100 | 124 | 84  | 54  | T     | 0111 0100 | 164 | 116 | 74  | t     |
| 0011 0101 | 065 | 53  | 35  | 5        | 0101 0101 | 125 | 85  | 55  | U     | 0111 0101 | 165 | 117 | 75  | u     |
| 0011 0110 | 066 | 54  | 36  | 6        | 0101 0110 | 126 | 86  | 56  | V     | 0111 0110 | 166 | 118 | 76  | v     |
| 0011 0111 | 067 | 55  | 37  | 7        | 0101 0111 | 127 | 87  | 57  | W     | 0111 0111 | 167 | 119 | 77  | w     |
| 0011 1000 | 070 | 56  | 38  | 8        | 0101 1000 | 130 | 88  | 58  | X     | 0111 1000 | 170 | 120 | 78  | x     |
| 0011 1001 | 071 | 57  | 39  | 9        | 0101 1001 | 131 | 89  | 59  | Y     | 0111 1001 | 171 | 121 | 79  | y     |
| 0011 1010 | 072 | 58  | 3A  | :        | 0101 1010 | 132 | 90  | 5A  | Z     | 0111 1010 | 172 | 122 | 7A  | z     |
| 0011 1011 | 073 | 59  | 3B  | ;        | 0101 1011 | 133 | 91  | 5B  | [     | 0111 1011 | 173 | 123 | 7B  | {     |
| 0011 1100 | 074 | 60  | 3C  | <        | 0101 1100 | 134 | 92  | 5C  | \     | 0111 1100 | 174 | 124 | 7C  | |     |
| 0011 1101 | 075 | 61  | 3D  | =        | 0101 1101 | 135 | 93  | 5D  | ]     | 0111 1101 | 175 | 125 | 7D  | }     |
| 0011 1110 | 076 | 62  | 3E  | >        | 0101 1110 | 136 | 94  | 5E  | ^     | 0111 1110 | 176 | 126 | 7E  | ~     |
| 0011 1111 | 077 | 63  | 3F  | ?        | 0101 1111 | 137 | 95  | 5F  | _     |           |     |     |     |       |  

## Tipos 

| Tipo      | Bytes    | Bits          | Valor  |
| :-:       | :-:      | :-:           | :-:    |
| Short     | 2 bytes  | 16 bits       | 2^16   |
| Int       | 4 bytes  | 32 bits       | 2^32   |
| Long      | 8 bytes  | 64 bits       | 2^64   |
| Float     | 4 bytes  | 32 bits       | 2^32   |
| Double    | 8 bytes  | 64 bits       | 2^64   |
| char      | 1 byte   | 8 bits        |        |


## Funções

**abs**: devolve o valor absoluto do número.  
**time**: devolve o número de segundos passados desde 01/01/1970 (data muito usada em programação para descobrir datas).  
**srand()**: alimenta a função rand com um número inicial.  
**rand**: gera um número 'aleatório'.  

## Ponteiros

Quando temos uma função que recebe por parâmetro um valor, e chamamos essa função passando uma variável, na verdade estamos passando o valor da variável e não a variável.  
Isso significa que estamos criando dois espaços de memória no computador, um para a variável **a** e outro para a variável **n**, que contém a cópia desse valor.  
As alterações que fizermos no valor da variável **a** no escopo da função, só existirão no escopo da função:  

```C
void calc(int n){
    n++;
    printf("%d\n", n); //1
}

int main() {
    int a = 0;
    calc(a);
    printf("%d\n", a) //0
}
```

Ao voltar para o fluxo anterior do programa, se tentarmos utilizar o valor da variável **a**, teremos o valor original, antes das alterações feitas na função **calc()**.  
Isso já era esperado, visto que trata-se de uma cópia do valor. Note que mesmo que as variáveis tivéssem o mesmo nome, ainda assim seriam variáveis diferentes.  

Caso queria que a função **calc()** altere o valor da variável **a** ao invés de criar uma cópia, deve-se passar o endereço da memória da variável **a**:

```C
void calc(int* n){ //ponteiro para endereço de memória que guarda um inteiro
    *n++; //soma no valor que estiver dentro do endereço de memória, não no endereço
    printf("%d\n", *n); //1
}

int main() {
    int a = 0;
    calc(&a);
    printf("%d\n", a); //0
}
```

Dessa forma, a varíavel **n** torna-se um **ponteiro** para um endereço de memória.  
Se tentar usar a variável **n** diretamente sem o '*', obterá o endereço de memória daquele valor.  

