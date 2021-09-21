#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct cmp{
    bool operator()(int a, int b)
    {
        if(abs(a)==abs(b)) return a>b;
        else return abs(a)>abs(b);
    }
};

int main()
{
    int n;
    cin>>n; // n= 연산의 개수

    priority_queue<int, vector<int>, cmp> h;
    while(n--)
    {
        int x;
        cin>>x;
        if(x)
        {
            h.push(x);
        } 
        else // 절댓값이 가장 작은 값을 출력
        {
            if(!h.size()){ cout<<0<<"\n"; continue;}
            cout<<h.top()<<"\n";
            h.pop();
        }
        
    }
    return 0;
}