#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
  int number, is_even;
  scanf("%d", &number);

  if(number % 2 == 0) {
    is_even = 1;
  };
 
  int size = 0;
  int number_to_count = number;
  while(number_to_count > 0) {
    int rest = number_to_count % 10;
    number_to_count = number_to_count - rest;
    number_to_count = number_to_count/10;
    size++;
  };
  
  int number_one = number;
  int number_two = number;
  int is_palindrome = 1;
  for(int s = size; s > size/2; s--) {
    int position = (s - 1);
    float digit = floor(number_one / pow(10, position));
    number_one -= pow(10, position) * digit;

    float last_digit = number_two % 10;
    number_two -= last_digit;
    number_two = number_two/10;
    if(digit != last_digit) {
      is_palindrome = 0;
      break;
    };
  };

  printf(
    is_even == 1? 
      is_palindrome == 1? "%d é Palíndromo e par.":"%d não é Palíndromo e par."
        :is_palindrome == 1? "%d é Palíndromo e impar.":"%d não é Palíndromo e impar.",
    number
  );

  return 0;
};