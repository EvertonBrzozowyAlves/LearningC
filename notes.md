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

## Tipos 

| Tipo      | Bytes    | Bits          | Valor  |
| :-:       | :-:      | :-:           | :-:    |
| Short     | 2 bytes  | 16 bits       | 2^16   |
| Int       | 4 bytes  | 32 bits       | 2^32   |
| Long      | 8 bytes  | 64 bits       | 2^64   |
| Float     | 4 bytes  | 32 bits       | 2^32   |
| Double    | 8 bytes  | 64 bits       | 2^64   |
| char      | 1 byte   | 8 bits        |        |

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

## Funções

**abs**: devolve o valor absoluto do número.
**time**: devolve o número de segundos passados desde 01/01/1970 (data muito usada em programação para descobrir datas).
**srand()**: alimenta a função rand com um número inicial.
**rand**: gera um número 'aleatório'.

## Strings

Podemos utilizar barras duplas para escapar uma barra em string.