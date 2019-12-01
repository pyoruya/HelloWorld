#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>suits(n,1);


    for(int i= 0 ; i< lost.size(); ++i)
    {
        suits[lost[i]-1] -= 1;
    }
    for(int j= 0 ; j< reserve.size(); ++j)
    {
        suits[reserve[j]-1] += 1;
    }
    suits.insert(suits.begin(),0);
    suits.push_back(0);
    for(int k= 1 ; k < suits.size()-1; ++k)
    {
        if(suits[k] == 0)
        {
            if (suits[k-1]==2){
                suits[k-1] -= 1;
                suits[k] = 1;
                answer++;
            }
            else if (suits[k+1] == 2){
                suits[k+1] -= 1;
                suits[k] = 1;
                answer++;
            }
        }
        else{
            answer ++;
        }
    }
    return answer;
}


int main()
{
    cout<<"Gym suit ....."<<endl;
    
    cout<<"return = "<<solution(5, {2,4}, {1,3,5})<<endl;
    cout<<"return = "<<solution(5, {2,4}, {3})<<endl;
    cout<<"return = "<<solution(3, {3}, {1})<<endl;

    return 0;
}
