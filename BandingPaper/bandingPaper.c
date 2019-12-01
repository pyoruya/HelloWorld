#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int* solution(int n) 
{
    if(n < 1) {
        printf("Incorrect banding count is input!\n");
        return NULL;
    }

    int* answer;
    int length = (pow(2,n)-1);
    answer = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i += 2)
    {
        answer[i] = (i/2 & 0x01);
    }
    if(n == 1) { return answer; }

    int* rcv = solution(n-1);
    for(int j = 1; j < length; j += 2)
    {
        answer[j] = rcv[j/2];
    }
    free(rcv);

    return answer;
}

int* solution_2(int n)
{
    if(n < 1) {
        printf("Incorrect banding count is input. \n");
        return NULL;
    }

    int* past_tmp; 
    int* answer;
    past_tmp = malloc(sizeof(int));
    answer = malloc(sizeof(int));

    for(int i = 1; i <= n; ++i)
    {
        int length = (pow(2,i) - 1);
        free(answer);
        answer = (int*)malloc(sizeof(int)*length);
        for (int j = 0; j < length/2; ++j)
        {
            answer[j] = past_tmp[j];
            answer[length - j -1] = ((past_tmp[j]+1) & 0x01);
        }
        answer[length/2] = 0;
        free(past_tmp);
        past_tmp = (int*)malloc(sizeof(int)*length);
        memcpy(past_tmp, answer, sizeof(int)*length);
    }
    free(past_tmp);

    return answer;
}

int main(void)
{
    int cnt = 0;
    int* result;

    printf("Banding number: ");
    scanf("%d",&cnt);
    printf("Input number is %d.\n", cnt);

    result = solution(cnt);
    printf("solution: ");
    for (int i = 0; i < pow(2, cnt)-1; ++i)
    {
        printf("%d, ", result[i]);
    }
    printf("\n");

    result = solution_2(cnt);
    printf("solution_2: ");
    for (int i = 0; i < pow(2, cnt)-1; ++i)
    {
        printf("%d, ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}


