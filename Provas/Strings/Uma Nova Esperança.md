# Uma Nova Esperança

A República caiu. O perverso Império Galáctico, que tomou seu lugar, controla tudo e todos com mãos de ferro. Os poucos Jedis que sobreviveram à Ordem 66 estão dispersos pelo universo e a única esperança da galáxia é a resistência formada pela Aliança Rebelde.

Como o Império monitora todas as transmissões, a única chance da Resistência é criptografar os dados antes do envio. Cabe a você, como o último sobrevivente de uma nobre ordem de desenvolvedores, implementar o algoritmo de criptografia que será utilizado nas transmissões de dados da Aliança Rebelde. Que a Força esteja com você!

****

Implemente o algoritmo criptográfico da Aliança Rebelde. O programa deverá receber como entrada uma chave K de 4 dígitos decimais (0000 a 9999) e uma mensagem P de até 200 caracteres. Você deverá criar uma função que receberá P e K, transformando P na mensagem cifrada C a partir da aplicação da chave K. Como saída, o programa deverá imprimir a mensagem cifrada C.

Caso seja informada uma chave fora do padrão, uma mensagem "Chave invalida!" deverá ser exibida.​

Os caracteres permitidos para as mensagens, tanto cifrada como original, são definidos no vetor a seguir, que deverá ser incorporado ao seu código:

```c
const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
```

Caso seja informado algum caractere diferente dos apresentados, o programa deverá exibir a mensagem: "Caractere invalido na entrada!".

O funcionamento do algoritmo é baseado no deslocamento de cada caractere de entrada pelo número de vezes especificado pela chave naquela posição.

Exemplos:

```
Chave(K)   : 0123
Mensagem(P): AAAABBBBCC

Cifragem:
   AAAABBBBCC
 + 0123012301
   ---------
   ABCDBCDECD   

---

Chave(K)   : 6666
Mensagem(P): WXYZ1234

Cifragem:
   WXYZ1234
 + 66666666
   ---------
   ? 01789A
```

Observe que está sendo usado o vetor S para o cálculo de substituição. 
Obs.: Este algoritmo é conhecido como Cifra de Vigenère. Por mais de 300 anos foi chamado de "le chiffre indéchiffrable" (a cifra indecifrável).