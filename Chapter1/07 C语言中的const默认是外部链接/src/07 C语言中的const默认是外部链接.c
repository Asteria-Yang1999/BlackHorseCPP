/*
 ============================================================================
 Name        : 07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	extern const int a; //告诉编译器a在外部
	printf("a = %d \n", a);

	return EXIT_SUCCESS;
}
