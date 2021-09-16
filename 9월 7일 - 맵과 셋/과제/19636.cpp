#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void solution(int W0, int L0, int T, int D, int L, int A)
{
    int W1 = W0;
    int A0 = L0;

    int energe_change = L - L0 - A;

    for(int i=0;i<D;i++)
    {
        W0 += energe_change;
        if(!W0) { break; }
    }

    energe_change = L - A0 - A;

    for(int i=0;i<D;i++)
    {
        W1 += energe_change;
        if(T+energe_change<0) A0 += floor(energe_change*1.0/2);
        
        energe_change = L - A0 - A;
        if(!A0 || !W1) break;
    }

    
    //print
    if(W0) cout<<W0<<" "<<L0<<"\n";
    else cout<<"Danger Diet"<<"\n";


    if(!A0 || !W1) cout<<"Danger Diet";
    else {    cout<<W1<<" "<<A0<<" ";
                if(L0-A0)   cout<<"YOYO"; else cout<<"NO";    }
}

int main()
{
    int W0, L0, T, D, L, A;

    cin >> W0 >> L0 >> T;
    cin >> D >> L >> A;

    solution(W0, L0, T, D, L, A);

    return 0;
}