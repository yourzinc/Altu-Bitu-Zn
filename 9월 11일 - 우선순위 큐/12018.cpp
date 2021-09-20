#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;


int main()
{
    //입력
    int n, m; // n= 과목 수, m= 주어진 마일리지
    cin>>n>>m;

    int total=0; // total = 성준이가 사용하는 마일리지 합산
    priority_queue<int, vector<int>> pq;
    // pq = 과목별 성준이가 사용하는 마일리지 max_heap

    for(int i=0; i<n; i++)
    {
        int p, l; // p = 과목을 신청한 사람 수, l = 수강인원
        cin>>p>>l;

        int pm; // pm = 과목 당 성준이 마일리지

        vector<int> v;

        for(int j=0; j<p; j++){
            cin>>pm;
            v.push_back(pm);
        }

        sort(v.begin(), v.end(), greater<int>());
        pm = v[l-1];

        if(p<l) pm = 1; // 신청한 사람 수 < 수강인원
        
        total+=pm;
        pq.push(pm);
    }

    // 최대로 들을 수 있는 과목 개수 계산
    while(total>m && n>0)
    {
        total -= pq.top();
        pq.pop();
        n--;
    }

    // 출력
    cout<<n;

    return 0;
}