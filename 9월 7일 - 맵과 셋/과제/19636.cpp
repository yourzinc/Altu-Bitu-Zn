#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

int W0, W1, L0, L, T, D, A0, A;

void solution()
{   
    // 두번째 출력에서 사용할 변수 W1 = 무게 , A0 = 활동 대사량
    W1 = W0;
    A0 = L0;


// 첫번째 출력 계산

    // 일일 에너지 섭취량 - 일일 에너지 소비량
    int energe_change = L - (L0 + A); 

    for(int i=0;i<D;i++) // D일 동안 반복
    {
        W0 += energe_change; // W0 무게에 변화한 에너지량
        if(!W0) { break; } // 무게<=0 이면 중단
    }


// 두번째 출력 계산
    // 일일 에너지 섭취량 - 일일 에너지 소비량
    energe_change = L - (L0 + A);

    for(int i=0;i<D;i++) // D일 동안 반복
    {
        W1 += energe_change; // W1 무게에 변화한 에너지량

        // 임계치보다 에너지량 변화의 절댓값이 크면 활동 대사량 변경
        if(abs(energe_change)>T) A0 += floor(energe_change*1.0/2);
        
        // 일일 에너지 섭취량 - 일일 에너지 소비량
        energe_change = L - A0 - A;

        // 활동대사량<=0 이거나 무게<=0 이면 중단
        if(!A0 || !W1) break;
    }
}

int main()
{
    cin >> W0 >> L0 >> T;
    cin >> D >> L >> A;

    solution();
    
    //출력 1
    if(W0) cout<<W0<<" "<<L0<<"\n";
    else cout<<"Danger Diet"<<"\n";

    //출력 2
    if(!A0 || !W1)
        cout<<"Danger Diet";
    else {  
        cout<<W1<<" "<<A0<<" ";

        // 일일 에너지 섭취량 - 일일 에너지 소비량
        if(L0-A0)   cout<<"YOYO"; else cout<<"NO"; 
    }

    return 0;
}