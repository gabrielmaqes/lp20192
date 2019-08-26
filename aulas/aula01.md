
## Apresentação da disciplina e construindo o primeiro programa

### Roteiro

* Ementa
* Alguns pontos importantes
* Primeiro programa
  * Compiladores versus interpretadores
  * Declarações Variáveis
  * Espaço em branco e indentação
  * Impressão no console ( a função printf )
  * Funções
* Características da linguagem C
* Ambientes de desenvolvimento
* Avaliação
* Outras referências

### Ementa 

* Estudo detalhado de uma linguagem de programação. 
* Estrutura da linguagem. 
* Comandos e declarações. 
* Tipos e Representações de dados. 
* Mecanismos de entrada e saída de dados. 
* Aplicações

([acesse aqui o conteúdo programático completo](https://profsergiocosta.github.io/teaching/laboratorio_programacao))

***


### Alguns pontos importantes

* Essa não é uma disciplina de introdução a programação. O foco agora será na
linguagem
* Essa é uma disciplina prática, então pressupõe que todos irão realizar as
atividades solicitadas e um pouco mais :)
* Essa disciplina tem como objetivo prepará-los para as engenharias. Na computação, podemos citar: estrutura de dados, sistemas operacionais, sistemas embarcados, computação gráfica e compiladores. 
* Iremos usar a linguagem C, evitando misturar códigos de C com C++.

***
### Primeiro programa

Como não temos muito tempo para perder, vamos começar com o primeiro programa em C, para ver algumas diferenças desta linguagem comparada com o Python.

Para isso, usaremos aqui como base o livro [C for Python programmers de Carl Burch](http://www.toves.org/books/cpy/). A sua tradução do capítulo 1 esta diponível [nesse link](https://github.com/profsergiocosta/cpy-ptbr/blob/master/cap01.md).



***

#### Compiladores versus interpretadores

* Uma grande diferença entre C e Python é simplesmente como você executa programas escritos nas duas linguagens. 
  * Com programas em C, você geralmente usa um _compilador_ antes de executar. 
  * Por outro lado, com o Python, você normalmente usa um _interpretador_.

* Passo (1) um programa é escrito na linguagem C:

```C
#include <stdio.h>

int main () {
    printf ("Ola mundo!\n");
    return 0;
}
```
* Passo (2) é compilado, e passo (3) é então executado:

```
sh:~$ gcc meuprograma.c -o meuprograma
sh:~$ ./meuprograma
Ola mundo!
```
Editando, compilando e executando pelo Visual Code:

![](../img/olamundovisualcode.png)



 >Observação: Algumas IDEs (Ambientes integrados de desenvolvimento), ou mesmo o ambiente online [repl.it](https://repl.it/languages/c), torna esses passos transparentes.

 >Observação: Veremos no decorrer do curso, que existem outros passos importantes, a saber, a **pré-compilação** e a **linkedição**.  Compreender esses passos será muito importante para poder usar bem bibliotecas externas.

***
#### Declarações Variáveis

* Diferentemente de Python, a linguagem C é estaticamente tipada, ou seja, todas as variáveis e parâmetros são associados a um dado tipo em tempo de compilação.
* Em C, a declaração da variável define o tipo **da variável**, especificando se é um inteiro (`int`), um número de ponto flutuante (`double`), caracter (`char`), ou algum outro tipo que estudaremos depois. 
* Uma vez que você declara que uma variável é de um tipo particular, você não pode mudar seu tipo: 
  * Se a variável `x` é declarada do tipo`double`, e você atribui `x = 3;` , então ` x` irá, na verdade, manter o valor de ponto flutuante 3.0 em vez do inteiro 3. 

> Ser estaticamente tipada tem como principal vantagem ser mais segura, dado que os erros associados a tipos podem ser executado em tempo de compilação. Atualmente existe uma nova onda de linguagens que estão usando essa característica: Swift, Kotlin, Rust, Go, Scala, TypeScript ...



***
#### Declarações Variáveis - como declarar

* Declarar uma variável é bastante simples: você insere o tipo da variável, alguns espaços em branco, o nome da variável e um ponto e vírgula:

```c
double x;
```

* Caso tenha mais de uma variável do mesmo tipo, elas pode ser declaradas na mesma linha, separando as como uma `,`:

```c
double x,y,z;
```

> Versões mais antigas da linguagem C exigiam que as variáveis fossem declaradas no inicio do bloco. Versões mais recentes da linguagem permitem elas serem declaradas em qualquer ponto do programa.

* Declaração e atribuição, com a possibilidade de declarar em qualquer ponto do programa, uma boa prática declarar no ponto mais próximo aonde será usada. Usualmente, já atribuindo valor:

```c
printf ("Calculando a somatoria de notas");
double notas[] = { 10, 8, 5, 7, 3, 10};
double soma = 0.0;
for (int i = 0; i < 6;i++) {
    soma = soma + notas[i];
}
printf ("soma é %f\n",soma);
```

***
#### Declarações Variáveis: possíveis erros

> A linguagem C é **estaticamente tipada**, porém mesmo assim é considerada uma linguagem **fracamente tipada**. Em geral os valores são convertidos, e erros de tipos não são detectados. Linguagens como C++, Java, Swift, GO e Kotlin são mais **fortemente tipadas**. Por exemplo, na seguinte linha ``` int i = 10.5;``` o valor 10.5 será convertido para 10 e armazenado na variável. 

* Se você esquecer de declarar uma variável, o compilador se recusará a compilar um programa no qual uma variável é usada, mas não é declarada.


```c
int main () {
    a = 10;
    b = 20;
    c = a + b;
}
```

Uma tentativa de compilação, levaria aos seguintes erros:

```
$ gcc programaerrovariavelnaodeclarada.c
programaerrovariavelnaodeclarada.c:5:5: error: ‘a’ undeclared (first use in this function)
     a = 10;
     ^
programaerrovariavelnaodeclarada.c:5:5: note: each undeclared identifier is reported only once for each function it appears in
programaerrovariavelnaodeclarada.c:6:5: error: ‘b’ undeclared (first use in this function)
     b = 20;
     ^
programaerrovariavelnaodeclarada.c:7:5: error: ‘c’ undeclared (first use in this function)
     c = a + b;
     ^
```


***
#### Espaço em branco e indentação

* Em Python, os espaços em branco, tabs e quebra de linhas são importantes: você separa suas instruções colocando-as em linhas separadas e indica a extensão de um bloco (como o corpo de uma instrução `while` ou `if`) usando recuo.

* Como a maioria das linguagens de programação, C não usa espaço em branco, exceto para separar palavras. 
    * A maioria das declarações é terminada com um ponto e vírgula `;`, 
    e blocos de instruções são indicados usando um conjunto de chaves, `{` e `}`. 

* Por exemplo:

```C
disc = b * b - 4 * a * c;
if (disc < 0) {
    num_sol = 0;
} else {
    t0 = -b / a;
    if (disc == 0) {
        num_sol = 1;
        sol0 = t0 / 2;
    } else {
        num_sol = 2;
        t1 = sqrt(disc) / a;
        sol0 = (t0 + t1) / 2;
        sol1 = (t0 - t1) / 2;
    }
} 
```

 * O espaço em branco é insignificante, então o computador ficaria tão feliz se eu tivesse escrito da seguinte maneira.

```C
disc=b*b-4*a*c;if(disc<0){
num_sol=0;}else{t0=-b/a;if(
disc==0){num_sol=1;sol0=t0/2
;}else{num_sol=2;t1=sqrt(disc/a;
sol0=(t0+t1)/2;sol1=(t0-t1)/2;}} 
```

* Enquanto o computador pode estar feliz com isso, nenhum humano sensato preferiria essa última versao. Assim, qualquer programador competente tende a ser muito cuidadoso com os espaços em branco para indicar a estrutura do programa.

> Existem algumas exceções à regra de ignorar o espaço em branco: É ocasionalmente significativo separar palavras e símbolos. O fragmento `intmain` é diferente do fragmento ` int main` ; da mesma forma, o fragmento `a++ + 1` é diferente do fragmento `a+ + +1`.

***
#### Impressão no console ( a função `printf` )

* Em C, você usa `printf ()` para exibir resultados para o usuário ver, o que você realizaria usando `print` em Python.

* A maneira como os parâmetros para `printf ()` funcionam é um pouco complicada, mas também bastante conveniente: 
    * O primeiro parâmetro é uma string especificando o formato do que imprimir, 
    * e os seguintes parâmetros indicam os valores a serem impressos. 

* A maneira mais fácil de entender isso é olhar para um exemplo.

```c
printf("# solns: %d\n", num_sol);
```

* Esta linha diz para imprimir usando “# solns: %d\n” como a string de formatação. A função `printf ()` passa por esta string de formatação, imprimindo os caracteres “# solns:” antes de chegar ao caractere de porcentagem '%'. 
* O caractere de porcentagem é especial para `printf ()`: Diz para imprimir um valor especificado em um parâmetro subseqüente. Nesse caso, um _d_ minúsculo segue o caractere de porcentagem, indicando para exibir o parâmetro como um `int` no formato decimal. 
(O _d_ significa decimal.) 

* Então, quando `printf ()` alcança “%d”, ele olha o valor do parâmetro a seguir (vamos imaginar `num_sol` é 2 neste exemplo) e exibe esse valor. Em seguida, continua através da string de formatação, neste caso, exibindo um caractere de quebra de linha. No geral, o usuário vê a seguinte linha de saída:

> \# solns: 2


Vamos ver outro exemplo.

```c
printf("# solns: %d", num_sol);  
printf("solns: %f, %f", sol0, sol1);`
```

* Vamos supor que `num_sol` contém 2, `sol0` com 4 e `sol1` com 1. Quando o computador alcança essas duas chamadas de função `printf ()`, ele primeiro executa a primeira linha, que exibe “\ # solns: 2 ”, E depois o segundo, que mostra “ solns: 4000000, 1.000000 ”, conforme ilustrado abaixo.

* A segunda chamada para `printf ()` neste exemplo ilustra como a função pode imprimir múltiplos valores de parâmetro. Na verdade, não há realmente nenhuma razão para não termos combinado as duas chamadas para `printf ()` em uma neste caso.

```c
printf("# solns: %dsolns: %f, %f",  
     num_sol, sol0, sol1);
```

***
### Impressão no console ( a função `printf` ) - caracteres especiais de formatação

Há uma variedade de caracteres que podem seguir o caractere de porcentagem na string de formatação.

* `%d`, como já vimos, diz para imprimir um valor `int` na forma decimal.
* `%x` diz para imprimir um valor `int` em formato hexadecimal.
* `%f` diz para imprimir um valor `double` em forma de ponto decimal.
* `%e` diz para imprimir um valor `double` em notação científica (por exemplo, 3.000000e8).
* `%c` diz para imprimir um valor `char`.
* `%s` diz para imprimir uma string. 

> Não há nenhum tipo de variável para representar uma string, mas C suporta alguns recursos de string usando matrizes de caracteres. Adiaremos a discussão desses recursos para mais tarde, depois de discutirmos os indicadores, já que as sequências envolvem alguns conceitos mais complexos que ainda não vimos.

> Você também pode incluir um número entre o caractere de porcentagem e o descritor de formato como em “%10d”, que diz `printf ()` para justificar à direita um número inteiro decimal em dez colunas.

***
#### Funções


* Ao contrário do Python, todo o código C deve estar aninhado dentro das funções e as funções usualmente não são aninhadas umas nas outras. 
    * O Python é uma linguagem de script, deste modo ela    permite escrever codigos fora de funções.
* Assim, a estrutura geral de um programa em C é tipicamente muito direta: 
    * É uma lista de definições de funções, uma após a outra, cada uma contendo uma lista de instruções a serem executadas quando a função é chamada.

Aqui está um exemplo simples de uma definição de função:


```c
double expon(double b, int e) {
    if (e == 0) {
        return 1.0;
    } else {
        return b * expon(b, e - 1);
    }
}
```

* Uma função C é definida: 
    * nomeando o tipo de retorno (`double` aqui, já que a função produz um resultado de ponto flutuante), 
    * seguido pelo nome da função (`expon`), 
    * seguido por um conjunto de parênteses listando os parâmetros. 
        * Cada parâmetro é descrito incluindo o tipo do parâmetro e o nome do parâmetro. 
    * A seguir,  um conjunto de chaves, no qual você aninha o corpo da função. 

> Se você tem uma função que não possui nenhum valor de retorno útil, você usaria `void` como tipo de retorno. 

> Programas possuem uma função especial chamada `main`, cujo tipo de retorno é um inteiro. Esta função é o “ponto de partida” para o programa: O computador essencialmente chama a função `main` do programa quando quer executar o programa. O valor de retorno inteiro é aparentemente sem sentido; sempre retornaremos 0 em vez de nos preocuparmos sobre como o valor de retorno pode ser usado. 

> Observação: este resultado é útil ao sistema operacional, pois se um programa retorna 0, o sistema operacional sabe que ele executou sem erros. 
***
#### Funções e o programa completo

Estamos agora em posição de apresentar um programa C completo, juntamente com seu equivalente em Python.

```c
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  printf("GCD: %d\n",
    gcd(24, 40));
  return 0;
} 
```

```python
def gcd(a, b):
  if b == 0:
    return a
  else:
    return gcd(b, a % b)

print("GCD: " + str(gcd(24, 40)))
```

> Como você pode ver, o programa C consiste em duas definições de função. Em contraste com o programa Python, onde a linha `print` existe fora de qualquer definição de função, o programa C requer que `printf()` esteja na função `main` do programa, já que é aqui que colocamos todo o código de nível superior é concluir quando o programa é executado.)


***

### Características da linguagem C

* Uso geral (porém com foco principal no desenvolvimento de sistemas)
  * Atualmente as linguagens Go e Rust tem propósito similar.
* Linguagem estaticamente tipada
* Linguagem de Nível Médio (possui diversas abstrações de alto nível, porém permite acesso a abstrações de mais baixo nível, como memória)
* Linguagem Compilada
* Amplamente utilizada, ainda é a linguagem mais utilizada no desenvolvimento de sistemas operacionais, compiladores, servidores, banco de dados ...
  * Novamente, as linguagens Go e Rust estão surgindo como alternativa.
* Influenciou diversas linguagens (c++, c#, Java, JavaScript, PHP, Objective C, Swift ...
* Eficiente (Desempenho), se bem utilizada consome pouco recursos, sem overheads como os causados por "garbage collectos"
* No Brasil e provavelmente no mundo, é a linguagem mais utilizada para a introdução a programação.
* Utilizada inclusive no póscomp, e outras seletivos para o mestrado.

***

#### Ambientes de desenvolvimento

Iremos usar nas aulas o ambiente online [repl.it](), porém em casa seria interessante experimentar um ambiente de desenvolvimento como: 

* codeblocks: o mais didático
* visual code: para casar, já que pode usar para todas linguagens.
* vim: o mesmo que visual code, mas sem mouse :)
* emacs: o mesmo que poderia dizer para vim
* eclipse: pesado demais para C, mas com bastante recursos.
* netbeans: ainda mais pesado, mas se tens uma máquina de verdade :)
...


***
#### Avaliação

| Unidade | Atividade        | Pontos |
|---------|------------------|--------|
| 1       | Prova Escrita    | 8      |
| 1       | Exercícios SIGAA | 2      |
| 2       | Prova Escrita    | 6      |
| 3       | Exercícios SIGAA | 4      |
| 3       | Projeto final    | 7      |

***
### Outras referencias 

Destaco os seguintes livros:

* **GoalKicker  - C Notes For Professionals**
* **Head First C**
* Helbert Shildt - C Completo e total
* [**Jens Gustedt - Modern C**](http://icube-icps.unistra.fr/img_auth.php/d/db/ModernC.pdf)
* Marcos Laureano - Programando em C para Linux e Windows
* **Peter Prinz - C In A Nutshell**
* **Ritchie & Kernighan - The C Programming Language**
* [C for Python Programmers](http://www.toves.org/books/cpy/)

Sites e cursos

* [Introdução a Ciência da Computação em C](https://www.ime.usp.br/~hitoshi/introducao/)
* [Introdução aos Algoritmos e Estruturas de Dados (1º Semestre 2013/14)](http://web.ist.utl.pt/aplf/aed//IAED1314F)
* [Practical programming in C](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-087-practical-programming-in-c-january-iap-2010/)
* [ Coursera - The Arduino Platform and C Programming](https://www.coursera.org/learn/arduino-platform/home/welcome)
* [ EdX - C Programming: Using Linux Tools and Libraries](https://courses.edx.org/courses/course-v1:Dartmouth_IMTx+DART.IMT.C.07+2T2018/course/)
* [ EdX - C Programming: Advanced Data Types](https://courses.edx.org/courses/course-v1:Dartmouth_IMTx+DART.IMT.C.05+2T2018/course/)
* [ EdX - C Programming: Language Foundations](https://www.edx.org/course/c-programming-language-foundations)
* [ EdX - C Programming with Linux](https://www.edx.org/professional-certificate/dartmouth-imtx-c-programming-with-linux)
* [ Udemy - Test Your C Programming Skills & Become Expert in C](https://www.udemy.com/test-your-c-programming-skills-become-expert-in-c/learn/v4/overview)
* [ Udemy - C for beginners the fastest and simple way NOW](https://www.udemy.com/c-for-beginners-themmz/learn/v4/overview)
* [ Udemy - C Programming - Practical Tutorial For Beginners](https://www.udemy.com/c-programming-create-terminal-apps/learn/v4/overview)

***


