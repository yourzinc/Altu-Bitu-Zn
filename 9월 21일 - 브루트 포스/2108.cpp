//진행중입니다
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // floor()
#include <map>
using namespace std;

int main()
{
    //Input
    int n;
    cin>>n;
    
    vector<int> m(n);
    map<int,int> mm;
    
    int s,small,big; //s= 합계, small=최솟값, big=최댓값
    
    cin>>m[0];
    s=small=big=m[0];
    
    for(int i=1; i<n; i++){
        cin>>m[i];
        s+=m[i];
    }
        
    //Ouput
    //산술평균 - 반올림
    cout<<floor((float)s/n+0.5)<<"\n";

    sort(m.begin(),m.end());
    
    //중앙값
    cout<<m[n/2]<<"\n";

    //최빈값
    map<int, int> mode; //최빈값 map
    
    int j= m[0];
    int cnt= 1;
    for(int i=1; i<n; i++)
    {
        if(j==m[i]) cnt++;
        else
        {
            mode.insert(make_pair(cnt, j));
            j=m[i];
            cnt=1;
        }
    }
    

    //범위
    cout<<*(m.end()-1)-*(m.begin())<<"\n";
    
    return 0;
}