// 11723.cpp
// 2. Bitmask

#include <iostream>
#include <string>
using namespace std;

// 11010 10101 100010
int main()
{
    int m;
    cin>>m;
    
    
    int s = 0;

    // 입력
    while(m--)
    {
        string ss;
        cin>>ss;

        // 컴퓨터는 2의 보수 체계를 가지고 있기 때문에
        // -1로 초기화시키면 모든 비트가 1이 된다
        if(ss=="all") s = -1다
        // 0으로 초기화하면 모든 비트가 0이 된다
        else if(ss=="empty") s = 0;
        else {      
            int x; 
            cin>>x;
            x--;
            if(ss=="add") s=s|(1<<x); 
            else if(ss=="remove") s=s&~(1<<x);
            else if(ss=="check")
                cout<<s&(1<<x)<<"\n";
            else if(ss=="toggle") s=s^(1<<x);
        }
    }

    return 0;
}