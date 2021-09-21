#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    priority_queue<int, vector<int>, greater<int> pq;

    // 입력
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        pq.push(a);
    }

    // 계산
    while(m--)
    {
        int j;
        j = pq.top();
        pq.pop();
        j += pq.top();
        pq.pop();

        pq.push(j);
    }

    // 합 계산
    int sum=0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }

    // 출력
    cout<<sum;

    return 0;
}