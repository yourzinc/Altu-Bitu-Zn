#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //Input
    int n;
    cin>>n;
    
    vector<int> t(n), p(n);

    for(int i=0; i<n; i++)
        cin>>t[i]>>p[i];

    //Solution
    vector<int> max_value(n); //max_value[i] = (i+1)일차 ~ n일차까지 최대 수익
    
    for(int i=n-1; i>=0; i--)
    {
        if(i+t[i]<=n) // 오늘 상담 시작해서 퇴사 날까지 끝난다면
            max_value[i]+= p[i]; // 오늘 시작한 상담의 수익
        
        if(i+t[i]<n) // 오늘 날짜 + 오늘 상담 완료 기간 < 퇴사 전
            //max_value[i]+=max_value[i+t[i]];
            
            // (오늘 날짜 + 상담 완료 기간) 날부터 퇴사 전날까지 최대 수익
            max_value[i]+=*max_element(max_value.begin()+i+t[i], max_value.end());
    }
    
    //Output
    cout<<*max_element(max_value.begin(),max_value.end());
    
    return 0;
}