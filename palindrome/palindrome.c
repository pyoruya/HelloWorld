#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(char* s) {
    int answer = 0;
    int length = strlen(s);
    printf("input s= %s  length= %d \n", s, length);

    for (int startPos = 0; startPos < length; ++startPos)
    {
        int Index = 0;
        bool isPalindrome = true;

        for (int endPos = length-1; endPos >= (startPos + answer); --endPos)
        {
           while((startPos+Index) < (endPos-Index))
           {
               if (s[startPos+Index] == s[endPos-Index])
               {
                   Index ++;
               }
               else 
               {
                   isPalindrome = false;
                   break;
               }
           }
           if (isPalindrome)
           {
               int len_palindrome = endPos - startPos + 1;
               if (answer < len_palindrome)
               {
                   answer = len_palindrome;
               }
               break;
           }
           isPalindrome = true;
           Index = 0;
        }
    }
    return answer;
}

int main()
{
    printf("Palindrome \n");
    printf("solution: %d \n", solution("abcdcba"));
    printf("solution: %d \n", solution("abacde"));
    printf("solution: %d \n", solution("b"));
    printf("solution: %d \n", solution("axyz00uy"));
    return 0;
}

