#include <iostream>
using namespace std;

int main()
{
    int N,B,C,i=0;
    long long cnt=0;
    
  //입력
    cin>>N;
    int A[N];
    while(i<N)
        cin>>A[i++];
    cin>>B>>C;
   
  //시험감독
    for(i=0; i<N; i++){
        A[i]-=B; cnt++;
    	if(A[i]<=0) continue;
    	cnt+=A[i]/C;
    	if(A[i]%C) cnt++;
    }
    cout<<cnt;
    return 0;
}
