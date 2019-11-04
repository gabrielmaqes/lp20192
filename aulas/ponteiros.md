# Ponteiros e vetores

- O que são vetores?
- O que são ponteiros?
- Declaração de ponteiros
- Operador de endereço
- Operador de acesso indireto
- Relação entre os operadores de acesso indireto e de endereço
- Declaração de vetores
- Vetores de tamanho variável
----------
## Slides

* [Acessem aqui os slides](Ponteiros.pptx)

----------
## Vetores e Ponteiros
- **Vetores**(arranjos, matrizes, arrays, variáveis indexadas) é uma coleção de variáveis do **mesmo tipo** que é referenciado por um nome comum.
- **Ponteiros** são variáveis que armazenam endereço para outras variáveis.

Considere um exemplo de um programa usado para calcular a média de dado 3 notas:

```c
    int main () {
      float n1, n2, n3;
      scanf ("%f %f %f", &n1,&n2, &n3);
      printf ("%f",(n1+n2+n3)/3);
    }
```
Agora, considere calcular a média de dado 50 notas. Nesse caso, uso de variáveis simples pode ser impraticável ou proibitiva.

```c
    int main () {
      // formato geral eh:
      // tipo indentificador[tamanho];
      float notas[50];
      // lendo 50 notas
      for (int i = 0; i < 50; i++) {
        scanf ("%f", &notas[i]);
      }
      // imprimindo 50 notas;
      for (int i = 0; i < 50; i++) {
        printf ("%f\n", notas[i]);
      }
    }
```
É comum encontrar códigos que usam a macro “define” para controlar o tamanho e os algoritmos que processam vetores:

```c
    #include "stdio.h"
    
    #define TAM 5
    
    int main () {
      // formato geral eh:
      // tipo indentificador[tamanho];
      float notas[TAM];
      // lendo TAM notas
      for (int i = 0; i < TAM; i++) {
        scanf ("%f", &notas[i]);
      }
      // imprimindo TAM notas;
      for (int i = 0; i < TAM; i++) {
        printf ("%f\n", notas[i]);
      }
      return 0;
    }
```
O compilador da linguagem C não verifica índices de vetores, tenha cuidado para não ocorrer invasão de memória. Pois isso pode levar a modificar outras variáveis do teu programa:

```c
    int main () {
      int v[3];
      int a = 20;
      v[3] = 50;
      printf ("%d\n",v[3]); // invadiu memória
      /*
      em alguns compiladores, pode ter alterado essa varáivel
      */
      printf ("%d\n", a); 
      return 0;
    }

```
## Relação entre vetores e ponteiros

```c
    int main () {
      int v[3];
      int *p;
      p = v; // atribuindo um vetor a um ponteiro
      // posso usar o ponteiro com indices
      p[0] = 20;  // v[0] = 20
      p[1] = 30;  // v[1] = 30
      p[2] = 40;  // v[2] = 40
      printf ("%d %d %d\n",v[0], v[1], v[2]);
      int v2[5] = {1,6,8,9,3};
      p = v2;
      printf ("%d %d %d %d %d\n",p[0],p[1],p[2],p[3],p[4]);
      //v = v2; 
      /* vetores sao variaveis imutaveis, nao posso alterar o local da memoria apontada por um vetor */
    
      return 0;
    }
   ``` 
## Operadores de endereço e de acesso indireto

Esses operadores são complementares:


- O operador de endereço & é usado para retornar o endereço de uma dada variável
- O operador de acesso indireto * é usado para retornar a variável em um dado endereço

```c
    int main () {
      int a = 10;
      int b = 20;
      int *p;
      p = &a;
      printf ("%d %d %d\n", a,b,p);
      printf ("%d\n", *p);
      *p = 50;   // a = 50
      printf ("%d\n", a);
      p = &b;
      printf ("%d\n", *p);
      return 0;
    }
```

## Simulando passagem por referência

Um exemplo de aplicação de ponteiros, é para simular passagem por referencia entre funções. Deste modo, uma função consegue alterar o valor de uma variável de outra função. Um exemplo é na utilização da função scanf. A seguir será apresentado um outro caso.

Considere esse código para fazer a troca de valor de duas variáveis:

```c
    int main () {
      int a = 10;
      int b = 20;
      // codigo para trocar valor
      int t = a;
      a = b;
      b = t;
      // imprimir
      printf ("%d %d\n",a,b);
      return 0;
    }
```
Agora criaremos uma função para executar o algoritmo de troca, dado que ele é utilizado por diversos algoritmos:

```c
    void troca (int* p, int* q) {
      int t = *p; // t = a
      *p = *q;  //a = b; 
      *q = t;
    }
    int main () {
      int a = 10;
      int b = 20;
      // chamando a funcao troca
      troca (a,b); 
      // imprimir
      printf ("%d %d\n",a,b);
      return 0;
    }
```
Um exemplo de aplicação da função troca é no algoritmo de ordenação clássico, conhecido como bubble sort.

```c
    void troca (int* p, int* q) { // bubble sort 
      int t = *p; // t = a
      *p = *q;  //a = b; 
      *q = t;
    }
    
    void imprime(int vet[], int n) {
      for (int i =0 ; i < n; i++) {
          printf ("%d\n",vet[i]);
      }
    }
    #define TAM 5
    int main () {
      int v[TAM] = {5,4,3,2,1};
      
      for (int i =0; i < TAM; i++) {
        for (int j = 0; j < TAM-i; j++) {
          if (v[j] > v[j+1]) {
            troca (&v[j], &v[j+1]);
          }
        }
        imprime (v,TAM);
        printf ("-----------\n");
      }
      
      return 0;
    }
```

----------
## Exercícios
1. Considere o código abaixo:

```c
    #include "stdio.h"
    
    
    int main(void) {
      
      int qtAlunos;
      printf ("entre com a quantidade de alunos:");
      scanf ("%d",&qtAlunos);
      float notas[qtAlunos];
      // lendo notas
      for (int i=0; i < qtAlunos; i++) {
        printf ("Nota (%d)",i);
        scanf ("%f",&notas[i]);
      }
      
      // calcula a média
      float soma = 0;
      for (int i=0; i < qtAlunos; i++) {
        soma = soma + notas[i];
      }
      float media = soma / qtAlunos;
      
      //calcula maior nota
      float maior = notas[0];
      for (int i=1; i < qtAlunos; i++) {
        if (notas[i] > maior)
          maior = notas[i];
      }
      
      //calcula menor nota
      float menor = notas[0];
      for (int i=1; i < qtAlunos; i++) {
        if (notas[i] < menor)
          menor = notas[i];
      }
      
      // conta quantidade de notas acima do limiar dado
      float limiar;
      printf ("Entre com uma nota limiar:");
      scanf ("%f",&limiar);
      int conta = 0;
      for (int i=0; i < qtAlunos; i++) {
        if (notas[i] > limiar)
          conta++;
      }
      // imprime estatistica
      printf ("Média: %f\n", media);
      printf ("Maior nota: %f\n", maior);
      printf ("Menor nota: %f\n", menor);
      printf ("Foram %d maiores que %f \n", conta,limiar);
      
      return 0;
    }
```
Reescrevam o código abaixo criando as seguintes funções:


- Lê n notas dada
- Dado um vetor de notas, retorne a média
- Dado um vetor de notas, retorne o maior valor
- Dado um vetor de notas, retorne o menor valor
- Dado um vetor de notas e um limiar, retorne o quantidade de valores acima do limiar

RESPOSTA:

```c
    #include "stdio.h"
    
    void leValores (float v[], int n) {
      // lendo notas
      for (int i=0; i < n; i++) {
        scanf ("%f",&v[i]);
      }
    }
    
    float calculaMedia (float v[], int n) {
      // calcula a média
      float soma = 0;
      for (int i=0; i < n; i++) {
        soma = soma + v[i];
      }
      return soma / n;
    }
    
    float maior (float v[], int n) {
      //calcula maior nota
      float maior = v[0];
      for (int i=1; i < n; i++) {
        if (v[i] > maior)
          maior = v[i];
      }
      return maior;
    }
    
    float menor (float v[], int n) {
       //calcula menor nota
      float menor = v[0];
      for (int i=1; i < n; i++) {
        if (v[i] < menor)
          menor = v[i];
      }
     return menor; 
    }
    
    int quantValoresMenorQue (float v[], int n, float limiar) {
      int conta = 0;
      for (int i=0; i < n; i++) {
        if (v[i] > limiar)
          conta++;
      }
      return conta;
    }
    
    int main(void) {
      
      int qtAlunos;
      
      printf ("entre com a quantidade de alunos:");
      scanf ("%d",&qtAlunos);
      float notas[qtAlunos];
      leValores (notas, qtAlunos);
      float limiar;
      printf ("Entre com uma nota limiar:");
      scanf ("%f",&limiar);
     
       // imprime estatistica
      printf ("Média: %f\n", calculaMedia (notas, qtAlunos));
      printf ("Maior nota: %f\n", maior (notas, qtAlunos));
      printf ("Menor nota: %f\n", menor (notas, qtAlunos));
      printf ("Foram %d maiores que %f \n"
                , quantValoresMenorQue(notas, qtAlunos, limiar)
                  ,limiar);
      
      return 0;
    }
```

2. Considere o código abaixo:

```c
      int iVar = 15;
      int jVar,*pPont,*qPont;
      pPont = &iVar;
      jVar = 2 * (*pPont);
      qPont = 2 + (pPont);
```

3. Supõe-se que as posições (endereços) de memória ocupadas pelas variáveis iVar, jVar, pPont e qPont sejam respectivamente 1080, 1082, 1084 e 1086. Responda:
- Na Linha 3, qual será o valor que a pPont assume?
- Na Linha 4, o que de fato ocorre, ou seja, qual será o valor que *pPont assume? 
- Na Linha 5, qual será o valor de jVar depois da atribuição. Por que?
- Na Linha 6, qual será o valor de qPont depois da atribuição. Por que?


4. Faça um programa usando vetores que:
    1. Preencha um vetor de inteiros com 10 posições.
    2. Imprima o maior elemento do vetor e apresente-o.
    3. Imprima o menor elemento do vetor e apresente-o.
    4. Imprima a soma entre os elementos do vetor.
    5. Imprima a média aritmética entre os elementos do vetor.
    
5. Um ponteiro é:
    1. o endereço de uma variável;
    2. uma variável que armazena endereços;
    3. o valor de uma variável;
    4. um indicador da próxima variável acessada.
    
1. Qual é o significado do operador asterisco em cada um dos seguintes casos?
    1. int *p;
    2. printf(“%d”, *p);
    3. *p = x*5;
    4. printf(“%d”, *(p+1));
    
1. Qual será a saída deste programa, supondo que i ocupa o endereço 4094 na memória?
```c
    #include <stdio.h>
    int main(){
       int i=5, *p;
       p = &i;
       printf(“%p - %d - %d\n”, p, *p+2, 3*(*p));
    }
```
8. Fazer um programa que altere o valor armazenado em uma variável através do ponteiro que aponta para a mesma, seguindo as seguintes premissas:
- A variável numero (tipo inteiro) irá armazenar o valor 35;
- O ponteiro se chama ptr;
- Logo no início, apresentar a mensagem (utilizando apenas a variável do tipo ponteiro): “O ponteiro ptr armazena o endereço ___ que, ‘\n’ por sua vez, armazena o valor ___. ‘\n”
- Após a troca do valor, apresentar (utilizando apenas a variável do tipo ponteiro): “Agora, o ponteiro ptr armazena o endereço ___ que, ‘\n’por sua vez, armazena o valor ___. ‘\n’”

 
8-  Seja a seguinte seqüência de instruções em um programa C:    

```c
    int *pti;
    int i = 10;
    pti = &i;
```
 Qual afirmativa é falsa?
- a.         pti armazena o endereço de i
- b.         *pti é igual a 10
- c.         ao se executar *pti = 20; i passará a ter o valor 20
- d.         ao se alterar o valor de i, *pti será modificado
- e.         pti é igual a 10
           
9- Se i e j são variáveis inteiras e pi e pj são ponteiros para inteiro, qual atribuição é ilegal?

- a.         pi = &i;
- b.         *pj = &j;
- c.         pj = &*&j;
- d.         i = *&*&j;
- e.         i = (*pi)+++*pj;
                       
10- Na seqüência de instruções abaixo:    
```c
    float f;
    float *pf;
    pf = &f;
    scanf("%f", pf);
```
 
    a -         Efetuamos a leitura de f
    b -        Não efetuamos a leitura de f
    c -        Temos um erro de sintaxe
    d -        Deveríamos estar usando &pf no scanf
    e -        Nenhuma das opções anteriores
 
11. Verifique o programa abaixo. Encontre o seu erro e corrija­-o para que escreva o numero 10 na tela.
```c
    #include <stdio.h> 
    int main()
    {
    int x, *p, **q;
    p = &x;
    q = &p;
    x = 10; 
    printf("\n%d\n", &q); 
    return(0);
    }
```

 
 
 

