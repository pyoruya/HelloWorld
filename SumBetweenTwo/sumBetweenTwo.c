#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int A, int B) {
    long long a = (long long)A;
    long long b = (long long)B;
    if (a<b)
    {
        return (a+b) * (b-a+1) /2;
    }
    else
    {
        return (a+b) * (a-b +1) /2;
    }
}

int main(void)
{
    int A, B;
    printf("Input Two integers: ");
    scanf("%d",&A);
    scanf("%d",&B);

    printf("Sum between the two numbers: %lld \n", solution(A, B));
    
    return 0;
}

