#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int* factors = (int*)malloc(sizeof(int)*n);
    memset(factors, 0, sizeof(int)*n);
    int index = 0;

    for(int i = 1; i*i <= n; ++i)
    {
        if((n%i) == 0)
        {
            factors[index++] = i;
            if(i*i != n)
            {
                factors[index++] = n/i;
            }
        }
    }
    for(int j = 0; j < index; ++j)
    {
        answer += factors[j];
    }
    free(factors);

    return answer;
}

int main(void)
{
    printf("Type a number from 0 to 3000:");
    int num;
    scanf("%d", &num);

    printf("Sum of the factors: %d \n", solution(num));

    return 0;
}

