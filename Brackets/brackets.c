#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Big Integer */
#include <math.h>
#define CIPHER_CNT  18
long long CIPHER = 1000000000000000000; 

typedef struct _tagBigInteger {
    long long high;
    long long low;
}Blong;

Blong castBlong(long long num)
{
    Blong result;
    result.low = num;
    result.high = 0;

    return result;
}

Blong addBlong(Blong a, Blong b)
{
    long long tlow = a.low%CIPHER + b.low%CIPHER;
    long long thigh = 0;
    if (tlow%CIPHER != a.low + b.low)
    {
        thigh = a.low/CIPHER + b.low/CIPHER;
    }
    thigh += a.high + b.high;

    Blong result = {thigh, tlow};
    return result; 
}

Blong multiplyBlong(Blong a, Blong b)
{
    Blong result = {0, 0};
    Blong offset = {0, -1};
    if(b.low == 0 || b.high == 0) { return result; }
    else
    {
        return addBlong(a, multiplyBlong(a, addBlong(b, offset)));
    }
}

Blong Bfactorial(int a)
{
    Blong result = castBlong(a);
    while (--a)
    {
        result = multiplyBlong(result, castBlong(a));
    }
    return result;
}


/* P(n) = P(n-1) * 3 - 1  (this solution is not correct) */
int solution(int n) {
    if(n < 2) { return 1; }
    else
    {
        return (solution(n-1) * 3 - 1);
    }
}

unsigned long long factorial(int n)
{
    if(n == 0) { return 1; }
    else { return (n * factorial(n-1)); }
}

/* Catalan solution - this solution need to control big integer */
long long catalan(int n)
{
//    return (int)(factorial(n * 2) / (factorial(n) * factorial(n+1)));
    long long answer = 1;
    for(int i = (n+2); i<= (n*2); ++i)
    {
       answer *= i;
    }
    answer /= factorial(n);
    return (int)answer;
}

typedef struct _pascalTriangle
{
    int *value;
}TypePascalTriangle;

TypePascalTriangle *makePascalTriangle(int step)
{
    TypePascalTriangle *triangle;
    triangle = (TypePascalTriangle*)malloc(sizeof(int)*(step+1));
    for (int i=0; i<(step+1); ++i)
    {
        triangle[i].value = (int*)malloc(sizeof(int)*(i+1));
        for(int j = 0; j <= i ; ++j)
        {
            if(j == 0) {
                triangle[i].value[j] = 1;
            }
            else if(j == i) {
                triangle[i].value[j] = 1;
            }
            else {
                triangle[i].value[j] = triangle[i-1].value[j-1] + triangle[i-1].value[j];
            }
        }
    }
    return triangle;
}

long long getCatalanArray(int num)
{
    if(num == 1) return 0;

    TypePascalTriangle *tri = makePascalTriangle(num * 2);
    int result = (tri[num*2].value[num] / (num+1));
    printf("%d \n", tri[num*2].value[num]);

    for(int i=0; i<num*2; ++i)
    {
        free(tri[i].value);
    }
    free(tri);

    return result;
}

    
    
int main(void)
{
    printf("Input the number of bracket pairs: ");
    int num;
    scanf("%d", &num);

    printf("The number of sets made up by them: %d\n", solution(num));
    printf("The number of sets made up by them: %lld\n", catalan(num));
    printf("The number of sets made up by them: %lld\n", getCatalanArray(num));

    printf("factorial %d! = %llu\n", num, factorial(num));
    
    printf("***PascalTriangle***\n");
    TypePascalTriangle *tri = makePascalTriangle(num);
    for(int i=0; i<=num; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            printf("%d ", tri[i].value[j]);
        }
        printf("\n");
    }
    for(int i=0; i<=num; ++i)
    {
        free(tri[i].value);
    }
    free(tri);

    return 1;
}

