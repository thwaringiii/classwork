//fibonacci.c
//Thomas Waring III
//Assignment 3

/*
Property: For f(n), when n is < or = to 100, the function will result
in a value of 91 every single time.

The f() function creates an incredible amount of growth because the else
statement contains nested recursion calls. The f(f()) calls won't exit
until the value of n reaches 111. At that point, the inner f() call will
return 111-10, or 101, to the outside f() call. That function will
decrement 10 more, resulting in 91 and freedom from the nested functions.

The peak of the nested f(f()) stack calls can be adjusted "higher" or
"lower" by adjusting how much is added to n. The lower the number
added to n, the more calls that must be made before the peak of the
stack is reached. Subtracting more from n when it is greater than 100
will result in more recursive calls before n exceeds the number
required to return n-10 TWICE in a row, therefore breaking a recursion
call.

The number being added to n must remain greater than the number being
subtracted from n when n is > 100 to prevent infinite calls.
*/

#include <stdio.h>

int main() {
  int i;
  for (i=0; i<10; i++)
    printf("%d\n", fibo());
}

/*
  F(n) = F(n-1) + F(n-2);
  F(1-10): 1,1,2,3,5,8,13,21,34,55
*/

int fibo() {
  static int fib = 1;	 //given
  static int fib2 = 0;
  static int fib3 = 1;
  static int counter = 0;
  
  if(counter > 0){
    fib = fib2 + fib3;
    fib2 = fib3;
    fib3 = fib;
  }
  counter++;
  return fib;    //given
}
