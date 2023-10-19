# Extração de e-mails

Crie um programa que receba uma sequência de endereços de e-mails de até 50 caracteres no formato nome@parte1.parte2 terminada pela palavra FIM e então crie uma função para obter os índices dos caracteres '@' e '.' na string através de passagem por referência. O programa deve exibir na saída padrão a parte parte1 de cada e-mail na mesma ordem da entrada de dados. Assuma que na parte nome do e-mail não pode conter o caractere '@' e a parte parte1 não pode conter o caractere '.'.

O programa não deve utilizar variáveis globais e a função não deve exibir dados na saída padrão, isto é, não deve fazer chamadas a função printf ou similar.

# Entrada / Saída

```
Entrada:
nome@parte1.parte2
FIM

Saída:
parte1
```

```
Entrada:
nome.sobrenome@parte.parte2
FIM

Saída:
parte
```