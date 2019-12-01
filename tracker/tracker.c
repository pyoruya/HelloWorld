#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int solution(char* dirs)
{
	int answer = 0;
	int track[20][20] = {0,};
    float x = 10., y= 9.;
    int pastDir = 'U';
    
    for (int i = 0; i < strlen(dirs); ++i)
    {
        char curDir = dirs[i];
        float incX = 0, incY= 0;
        switch (pastDir)
        {
            case 'U':
                incX -= 0.5;
                incY += 0.5;
                break;
            case 'D':
                incX += 0.5;
                incY -= 0.5;
                break;
            case 'R':
                incX += 0.5;
                incY += 0.5;
                break;
            case 'L':
                incX -= 0.5;
                incY -= 0.5;
                break;
            default:
                printf("Wrong input. \n");
                break;
        }
        switch (curDir)
        {
            case 'U':
                incX -= 0.5;
                incY += 0.5;
                break;
            case 'D':
                incX += 0.5;
                incY -= 0.5;
                break;
            case 'R':
                incX += 0.5;
                incY += 0.5;
                break;
            case 'L':
                incX -= 0.5;
                incY -= 0.5;
                break;
            default:
                printf("Wrong input. \n");
                break;
        }

        if ((fabs(x+incX-9.5) + fabs(y+incY-9.5)) > 10)
        {
            continue;
        }
        
        pastDir = curDir;
        x += incX;
        y += incY;
        if (track[(int)x][(int)y] == 0)
        {
            answer++;
            track[(int)x][(int)y] = 1;
        }
    }

    for (int i = 19; i>=0; --i)
    {
        for (int j = 0; j<20; ++j)
        {
            printf ("%d  ",track[j][i]);
        }
        printf("\n");
    }
    
    return answer;
}


int main()
{
    printf("Tracker by Hoon\n");

    printf("Disatance of tracking: %d\n", solution("ULURRDLLU"));

    printf("Disatance of tracking: %d\n", solution("LULLLLLLU"));
    printf("Disatance of tracking: %d\n", solution("LLLLLLLLLLLLLLLLLLL"));
    return 0;
}

