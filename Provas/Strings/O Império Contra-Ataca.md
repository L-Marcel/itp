Seduzido pelo lado sombrio, você se uniu ao Império Galáctico na perseguição aos rebeldes. Analisando os dados de um droid capturado, você descobriu o algoritmo de criptografia usado pela Resistência. Porém, durante a batalha para captura do droid, um tiro de pistola blaster acertou uma de suas unidades de memória, destruindo todas as chaves criptográficas que ali estavam armazenadas.

Lord Vader ordena que você implemente o algoritmo para decifrar as mensagens enviadas pela Aliança Rebelde. Você sabe, porém, que sem as chaves criptográficas não terá sucesso e sofrerá as consequências... No entanto, é sabido que a destruição da Estrela da Morte renovou a fé dos rebeldes e em todas as transmissões da Aliança a expressão "QUE A FORCA ESTEJA COM VOCE" é usada em algum ponto da mensagem.

Venha para o Lado Negro da Força!

****

Implemente um algoritmo que descobre a chave e decifra as mensagens da Aliança Rebelde. ​Seu programa deverá conter:

Uma função para descobrir a chave, que recebe como parâmetros uma mensagem cifrada C, um fragmento da mensagem original KP (know-plaintext), e um vetor para armazenar a chave K descoberta.
Uma função para decifrar mensagens, que recebe como parâmetros uma mensagem cifrada C e a chave K. A função deverá transformar a mensagem cifrada na mensagem original a partir da aplicação da chave.
​O programa deverá receber como entrada uma mensagem cifrada C de até 200 caracteres. Como saída, o programa deverá imprimir a chave K de 4 dígitos decimais (0000 a 9999) utilizada na cifragem e a mensagem original P. Caso o fragmento (KP) não exista na mensagem original (e, consequentemente, a chave K não possa ser calculada), o programa deverá exibir: "Mensagem nao e da Resistencia!

Os caracteres permitidos para as mensagens, tanto cifrada como original, são definidos no vetor a seguir, que deverá ser incorporado ao seu código:

```c
const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
```

O algoritmo de cifragem é baseado no deslocamento de cada caractere de entrada pelo número de vezes especificado pela chave naquela posição. Logo, a decifragem é realizada pelo processo inverso, deslocando cada caractere no sentido contrário pelo número de vezes indicado pela chave naquela posição. Além disso, subtraindo a mensagem original P da mensagem cifrada C, é possível encontrar a quantidade de deslocamentos realizada e, assim, a chave utilizada.

Exemplos:

```
Mensagem cifrada (C):   UJHHBTNWJFHSGVKIGQUGF
Fragmento da mensagem original (KP): DARKSIDE

Cálculo da Chave: 
1)   U  J  H  H  B  T  N  W  JFHSGVKIGQUGF
  -  D  A  R  K  S  I  D  E
    -----------------------
    17  9 30 37 23 11 10 18
    \---------/ \---------/ --> !=


2)   U  J  H  H  B  T  N  W  J  FHSGVKIGQUGF
     -  D  A  R  K  S  I  D  E
       -----------------------
        6  7 30 31  1  5 19  5
       \---------/ \---------/ --> !=


3)   U  J  H  H  B  T  N  W  J  F  HSGVKIGQUGF
        -  D  A  R  K  S  I  D  E
          -----------------------
           4  7 24  9 35 14  6  1
          \---------/ \---------/ --> !=


4)   U  J  H  H  B  T  N  W  J  F  H  SGVKIGQUGF
           -  D  A  R  K  S  I  D  E
             -----------------------
              4  1  2  3  4  1  2  3
             \---------/ \---------/ --> ==
    K0 K1 K2 K3 K0 K1 K2 K3 K0 K1 K2 ... 

    K[]={1,2,3,4}
```


Decifragem da Mensagem:            
```
  UJHHBTNWJFHSGVKIGQUGF (mensagem cifrada)
- 123412341234123412341 (chave: 1234)
  ---------------------
  THEDARKSIDEOFTHEFORCE (mensagem original)
```
Obs.1: Este algoritmo de cifragem, conhecido como Cifra de Vigenère, foi considerado indecifrável por mais de 300 anos. No entanto, Charles Babbage, inventor do primeiro computador, conseguiu superá-lo utilizando técnicas de cripto-análise. 

Obs.2: A técnica de utilizar parte conhecida da mensagem original para decifrar um código é chamada de Ataque de Texto Plano Conhecido (do inglês known-plaintext attack - KPA). Esta mesma estratégia foi utilizada por Alan Turing para decodificar as mensagens nazistas geradas a partir da máquina Enigma, conforme pode ser observado (com algumas adaptações) no filme "O Jogo da Imitação".