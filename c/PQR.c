/*
 PQR.c
 CSE305
 Assignment 6 Problem 1
 Thomas Waring III
*/
#include <stdio.h>

int main() {
	int a = 50; 
	int b = 100;
	void P(int *c, void R(int)) {
	  printf("Entered P, c = %d.\n", *c);

		void Q(int p) {
		printf("%d\n", p);
		R(p+100);
		}
	
	if (a == b) R(b);
	else {*c = *c + 25;
		P(c, Q); 
	}
	printf("I BET THIS EXITS THREE TIMES!\n");
	}
	void Q(int p) {
	  printf("%d\n", p);
	}
	P(&a, Q);
	printf("a=%d\n",a);
}
