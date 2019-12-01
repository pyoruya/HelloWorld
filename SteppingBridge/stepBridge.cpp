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
    printV(rocks);
    sort(rocks.begin(), rocks.end());
    printV(rocks);
    
    vector<int> gaps(rocks.size()+1, 0);
    gaps[0] = rocks[0];
    for(int k=1; k< rocks.size(); ++k)
    {
        gaps[k] = rocks[k] - rocks[k-1];
    }
    gaps[rocks.size()]=distance - rocks[rocks.size()-1];
    printV(gaps);

    /* Erasing n blocks */
    for (int cnt = 0; cnt < n; ++cnt)
    {
        int min = gaps[0];
        int minIndex = 0; 
        for(int i=0; i<gaps.size(); ++i){
            if (min > gaps[i]) {
                min = gaps[i];
                minIndex = i;
            }
        }
        if((cnt != n-1) && (minIndex != gaps.size()-1)) {     //remains more erasing turn & end of gaps.
            gaps[minIndex+1] += gaps[minIndex];
            gaps.erase(gaps.begin()+minIndex);
        }
        else
        {
            if(minIndex == gaps.size()-1){
                gaps[minIndex] += gaps[minIndex - 1];
                gaps.erase(gaps.begin() + minIndex - 1);
            }
            else if (cnt == n-1)
            {
                if ((gaps[minIndex-1] > gaps[minIndex+1]) || (minIndex==0)){
                    cout<<n<<" "<<minIndex<<" "<<gaps[minIndex]<<endl;
                    gaps[minIndex+1] += gaps[minIndex];
                    gaps.erase(gaps.begin() + minIndex);
                }
                else{
                    gaps[minIndex] += gaps[minIndex - 1];
                    gaps.erase(gaps.begin() + minIndex - 1);
                }
            }
        }
        int accum = 0;
        for(int j=0; j<gaps.size(); ++j){
            accum += gaps[j];
            cout<<accum<<" ";
        }
        cout<<endl;
    }

    answer = gaps[0];
    for(int i=1; i<gaps.size(); ++i){
        if (answer > gaps[i]) {
            answer = gaps[i];
        }
    } 

    cout<<"Final blocks location : ";
    int accum = 0;
    for(int j=0; j<gaps.size(); ++j){
        accum += gaps[j];
        cout<<accum<<" ";
    }
    cout<<endl;
    cout<<"Final blocks gap     : ";
    printV(gaps);

//    sort(rocks.begin(), rocks.end());
//	int a = 0;
//	int b = distance;
//
//	while(a < b) {
//		int c = (a+b+1)/2;
//		int p = 0;
//		int hits = 0;
//		for(int i=0;i<rocks.size();i++) {
//			if(rocks[i]-p < c) ++hits;
//    		else p = rocks[i];
//		}
//		if(hits > n) b = c-1;
//		else a = c;
//	}
//    answer = a;
    return answer;
}

int main()
{
    cout<<"Stepping Bridge by Hoon"<<endl;

    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 1)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 2)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 3)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 4)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {2,14,11,21,17}, 5)<<endl<<endl;

    cout<<"Long distance value: "<<solution(25, {14,11,21,17}, 2)<<endl<<endl;
    cout<<"Long distance value: "<<solution(25, {14,11,17}, 1)<<endl<<endl;

    cout<<"Long distance value: "<<solution(100, {3,4,8,9,14,23,25,31,36}, 5)<<endl<<endl;
    cout<<"Long distance value: "<<solution(100, {1,4,5,9,14,23,25,31,36}, 5)<<endl<<endl;
    return 0;
}

