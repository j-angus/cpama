/* ch16ex04.c */

#include <stdio.h>

typedef struct {
	double real, imaginary;
} Complex;

Complex make_complex(double r, double i);
Complex add_complex(Complex c1, Complex c2);

int main (void)
{
	Complex c1, c2, c3;

	c1 = make_complex(10, 20);
	c2 = make_complex(15, 25);
	printf("c1.real: %0.2f, c1.imaginary: %0.2f\n", c1.real, c1.imaginary);
	printf("c2.real: %0.2f, c2.imaginary: %0.2f\n", c2.real, c2.imaginary);

	c3 = add_complex(c1, c2);
	printf("c3.real: %0.2f, c3.imaginary: %0.2f\n", c3.real, c3.imaginary);

	return 0;
}

Complex make_complex(double r, double i)
{
	Complex cmplx = {r, i};

	return cmplx;
}

Complex add_complex(Complex c1, Complex c2)
{
	Complex result = {	c1.real + c2.real,
				c1.imaginary + c2.imaginary};

	return result;
}
