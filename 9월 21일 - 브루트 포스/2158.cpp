#include <iostream>

using namespace std;

int main()
{
    long int r, b; // r=빨간색 타일의 수, b=갈색 타일의 수
    // 8<=r<<=5,000  1<=b<=2,000,000
    // r+b = 2,005,000
    
    cin>>r>>b;
    
    int c = r+b; // c= 직사각형 넓이
    
    for(int i=3; i<c; i++)
    {
        if(c%i==0 && (c/i-2)*(i-2)==b)
        {
            cout<<c/i<<" "<<i;
            break;
        }
    }
    
    return 0;
}
