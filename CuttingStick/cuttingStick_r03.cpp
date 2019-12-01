#include <string>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    char stack[100000]={0,};
    int pos=0;

    for(int i=0; i<arrangement.length(); i++)
    {
        if(arrangement[i] =='(')
        {
            stack[pos++] = '(';
        }
        else
        {
            stack[--pos] = 0;
            if(arrangement[i-1] == '(')
            {
                int index = 0;
                for(index = 0; stack[index] != 0; ++index);
                answer += index;
            }
            else
            {
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    cout<<"Cutting the stick / Hoon"<<endl;

    cout << "The number of sticks: " << solution("()(((()())(())()))(())") << endl;   

    return 0;
}
