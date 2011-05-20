/* ch16ex01.c */

#include <stdio.h>

void main (void)
{
	struct complex {double real, imaginary;};
	
	struct complex c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
	printf("struct c1.real: %f, c1.imaginary: %f\n", c1.real, 
							c1.imaginary);
	printf("struct c2.real: %f, c2.imaginary: %f\n", c2.real, 
							 c2.imaginary);
	printf("struct c3.real: %f, c3.imaginary: %f\n", c3.real, 
							 c3.imaginary);
	
	c1 = c2;
	printf("struct c1.real: %f, c1.imaginary: %f\n", c1.real, 
							c1.imaginary);
	
	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;
	printf("struct c3.real: %f, c3.imaginary: %f\n", c3.real, 
							 c3.imaginary);


	return;
}
