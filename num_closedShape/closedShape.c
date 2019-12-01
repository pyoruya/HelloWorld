#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/* *********************************************
 * Counting the room(area) made by drawn lines.
 *
 *  Each point has eight directions  
 *  The input lines create a room(area) as follows
 *      a. A newly drawn line ends to the past drawn point.
 *      b. A new diagonal line is drawn and there is a symmetrical line to this one.
 ***********************************************/

typedef struct {
    int x;
    int y;
} pointTypedef;

bool isSamePoint(pointTypedef a, pointTypedef b)
{
    return ((a.x==b.x)&&(a.y==b.y))? true:false;
}

typedef struct {
    pointTypedef start;
    pointTypedef end;
    pointTypedef centerX2;
} lineTypedef;

bool isSameLine(lineTypedef a, lineTypedef b)
{
    if ((a.centerX2.x == b.centerX2.x) && (a.centerX2.y == b.centerX2.y))
    {
        if (isSamePoint(a.start, b.start) || (isSamePoint(a.start, b.end)))
        {
            return true;
        }
    }
    return false;
}
         
pointTypedef movePoint(pointTypedef a, int arrow)
{
    switch (arrow)
    {
       case 0:
            a.x += 0;
            a.y += 1;
            break;

       case 1:
            a.x += 1;
            a.y += 1;
            break;

       case 2:
            a.x += 1;
            a.y += 0;
            break;

       case 3:
            a.x += 1;
            a.y += -1;
            break;

       case 4:
            a.x += 0;
            a.y += -1;
            break;

       case 5:
            a.x += -1;
            a.y += -1;
            break;

       case 6:
            a.x += -1;
            a.y += 0;
            break;

       case 7:
            a.x += -1;
            a.y += 1;
            break;
       default:
            break;
    }
    return a;
}

int solution(int arrows[], size_t arrows_m) {
    int answer = 0;

    lineTypedef* lines;
    lines = (lineTypedef*)malloc(sizeof(lineTypedef)*arrows_m);
    lines[0].start.x = 0;
    lines[0].start.y = 0;
    lines[0].end = movePoint(lines[0].start, arrows[0]);
    lines[0].centerX2.x = (lines[0].start.x+lines[0].end.x);
    lines[0].centerX2.y = (lines[0].start.y+lines[0].end.y);

    for(int i = 1; i < arrows_m; ++i)
    {
        lines[i].start = lines[i-1].end;
        lines[i].end = movePoint(lines[i].start, arrows[i]);
        lines[i].centerX2.x = (lines[i].start.x+lines[i].end.x);
        lines[i].centerX2.y = (lines[i].start.y+lines[i].end.y);
    }

    for (int i=2; i<arrows_m; ++i)
    {
        //check duplicated or connected
        bool isConnected = false;
        bool isCrossed = false;
        for (int j = 0; j<i; ++j)
        {
            if (isSamePoint(lines[i].end, lines[j].start))
            {
                isConnected = true;
            }
            if (isSamePoint(lines[i].centerX2, lines[j].centerX2))
            {
                isCrossed = true;
            }
            if (isSameLine(lines[i],lines[j]))
            {
                printf("lines[%d] and lines[%d] dupliated.\n",i, j);
                isConnected = false;
                isCrossed = false;
                break;
            }
        }
        if (isConnected)
        {
            answer++;
        }
        if (isCrossed)
        {
            answer++;
        }
    }

    free(lines);
    return answer;
}

//int arrows[] = {6,6,6,4,4,4,0,0,0,4,4,4,2,2,2,0,0,0,4,4,4,0,0,0,1,6,5,5,3,7,3,6,0};
//int arrows[] = {1,4,7};
//int arrows[] = {1,4,7,2};
int arrows[] = {4,1,4,7,2};

int main()
{
    printf("Count the number of closed shape.\n");
    printf("by Hoon.\n");

    printf("The number of closed shapes is %d \n",solution(arrows, sizeof(arrows)/sizeof(arrows[0])));
    return 0;
}

