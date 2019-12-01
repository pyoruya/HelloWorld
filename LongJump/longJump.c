#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) 
{
    long long answer = 0;
    if(n == 1|| n==0) { return 1; }

    /* first jump is "1" */
    answer += solution(n-1);

    /* first jump is "2" */
    if (n>=2) 
    {
        answer += solution(n-2);
    }

    return answer;
}

long long solution_2(int n)
{
   long long answer = 0;
   long long past2 = 1;
   long long past1 = 2;
       
   if(n == 1) { return 1; }
   else if(n == 2) { return 2; }
   else
   {
       for(int i = 3; i <= n; ++i)
       {
           answer = past1 + past2;
           past2 = past1;
           past1 = answer;
       }
   }
   return answer%1234567;
}

int main(void)
{
    int dist;
    printf("Input distance: ");
    scanf("%d", &dist);

    printf("number of method: %lld \n", solution_2(dist));
    return 0;
}

