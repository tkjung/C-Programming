#include <stdio.h>
 
typedef struct complex
{
  double re; // 실수부(real)
  double im; // 허수부(imaginary)
} complex;


complex c_add(complex c1, complex c2)
{
    complex sum;

    sum.re = c1.re + c2.re;
    sum.im = c1.im + c2.im;

    return sum;
 }


 void printf_c(complex c)
 {
    printf("%.1lf + %.1lfi\n", c.re, c.im );
 }

 int main(int ac, char *av[])
{
   complex c1, c2;

   scanf("%lf %lf", &c1.re, &c1.im);
   scanf("%lf %lf", &c2.re, &c2.im);

   printf_c (  c_add(c1, c2)  );
}
