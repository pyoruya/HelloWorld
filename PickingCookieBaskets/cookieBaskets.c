// 각각의 바구니는 1번부터 N번 까지의 번호가 붙어있었기 때문에 철수 씨는 
// 첫째 아들에게 사줄 쿠키들의 바구니 번호가 l번부터 m번 까지라면 
// 둘째 아들에게 사줄 쿠키들의 바구니 번호는 m+1번부터 r번까지가 되도록 쿠키를 사려 합니다
// (1 <= l <= m, m+1 <= r <= N). 
// 물론 두 아들에게 주는 쿠키 개수의 합이 같아야 합니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// cookie_len은 배열 cookie의 길이입니다.
int solution(int cookie[], int cookie_len) {
    int answer = -1;
    
    int sum = 0;
    for(int i = 0; i <= cookie_len; ++i)
    {
        sum += cookie[i];
    }

    for (int startPos = 0; startPos < cookie_len-1; ++startPos)
    {
        int sum_endPos = sum;
        for (int endPos = cookie_len - 1; endPos > startPos; --endPos)
        {
            if (sum_endPos & 0x01) //odd value 
            {
                continue;
            }
            else
            {
                bool isFind = false;
                int accum = 0, target = sum_endPos>>1;
                for(int n = startPos; n <= endPos; ++n)
                {
                    accum += cookie[n];
                    if (accum < target)
                    {
                        continue;
                    }
                    else if (accum == target)
                    {
                        isFind = true;
                        if(answer < accum)
                        {
                            answer = accum;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                if (isFind == true)
                {
                    break;
                }
            }
            sum_endPos -= cookie[endPos];
        }
        sum -= cookie[startPos];
    } 
    return (answer != -1)? answer : 0;
}

int cookie_arr1[4] = {1,1,2,3};
int cookie_arr2[4] = {1,2,4,5};

int main()
{
    printf("Buying the cookie baskets for two sons.\n");
    printf("by Hoon.\n");

    printf("answer = %d\n",solution(cookie_arr1, sizeof(cookie_arr1)/sizeof(int)));
    printf("answer = %d\n",solution(cookie_arr2, sizeof(cookie_arr2)/sizeof(int)));

    return 0;
}




