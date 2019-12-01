#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
void printV(vector<int> tg)
{
    for(int i= 0; i<tg.size(); ++i)
    {
        cout<<tg[i]<<" ";
    }
    cout<<endl;
    return;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
	int a = 0;
	int b = distance;

    printV(rocks);
    cout<<"distance = "<<distance<<"  n="<<n<<endl;
    cout<<"-----------------------------"<<endl;
	while(a < b) {
		int c = (a+b+1)/2;
		int p = 0;
		int hits = 0;
        cout<<"a="<<a<<"  b="<<b<<"  c="<<c<<endl;
		for(int i=0;i<rocks.size();i++) 
        {
			if(rocks[i]-p < c) 
            {
                ++hits;
                cout<<hits<<" ";
            }
    		else 
            {
                p = rocks[i];
                cout<<"p="<<p<<endl;
            }
		}
		if(hits > n) 
        {
            b = c-1;
            cout<<endl<<"hits > n    b=c-1 ="<<(c-1)<<endl;
        }
		else 
        {
            a = c;
            cout<<endl<<"hits <= n    a=c ="<<(c-1)<<endl;
        }
        cout<<"-----------------------------"<<endl;
	}
    answer = a;
    return answer;
}

int main()
{
    cout<<"Stepping Bridge by Hoon"<<endl;

//    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 1)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 2)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 3)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 4)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 5)<<endl<<endl;
//
//    cout<<"Long distance value: "<<solution(25, {14,11,21,17}, 2)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(25, {14,11,17}, 1)<<endl<<endl;
//
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;
    cout<<"------------------------------------------------"<<endl;

    cout<<"Long distance value: "<<solution(100, {3,4,8,9,14,23,25,31,36}, 5)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(100, {1,4,5,9,14,23,25,31,36}, 5)<<endl<<endl;
//    cout<<"Long distance value: "<<solution(100, {30, 60}, 1)<<endl<<endl;
    return 0;
}

