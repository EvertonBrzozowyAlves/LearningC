# C

'Hello World' em C:
```C
#include <stdio.h>

int main()
{
    printf("Welcome to the guessing game");
}
```

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