// 9월 24일 - 백트래킹
// 라이브 코딩

#include <iostream>

using namespace std;

int n,m; //n= 1~n 까지 m= m개의 숫자
int size[8]; //size[]= 만든 순열 저장
bool checked[9]; ///checked[]= 순열 만들 때 사용한 숫자 check하는 것

void solution(int step)
{
    if(step==m) // 마지막 순열 자리+1 일 때
    {
        // print
        for(int i=0; i<step; i++)
            cout<<size[i]<<" "; // 순열 출력
        cout<<"\n";
        
    }
    else
    {
        for(int i=1; i<=n; i++) //1부터 n까지의 숫자 반복
        {
            if(!checked[i]) //i가 사용되지 않았다면
            {
                size[step]=i; // 만들고 있는 순열 뒷자리에 i 를 추가
                checked[i]=true; // i 사용 표시 
                solution(step+1); // (재귀) - 순열의 다음 자리 만들기
                checked[i]=false; // i 사용 표시 해제
            }
        }
    }
}

int main()
{
    //input
    cin>>n>>m;
    
    //solution
    solution(0);
    
    return 0;
}