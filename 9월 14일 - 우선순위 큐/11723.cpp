#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> set(20);
    
    for(int i=0; i<20; i++)
    	set[i] = 0;
    
    int m;
    cin>>m;
    
    string str;
    int x;
    
    while(m--)
    {
    	cin>>str;
    	if(str=="all") for(int i=0; i<20; i++) set[i] = 1;
    	else if(str=="empty") for(int i=0; i<20; i++) set[i] = 0;
    	else
    	{
    		int x;
    		cin>>x;
    		if(str=="add")	set[x-1]=1;
    		else if(str=="remove")	set[x-1] =0;
    		else if(str=="check"){ if(set[x-1]) cout<<1<<"\n"; else cout<<0<<"\n"; }
    		else if(str=="toggle"){ set[x-1] = -set[x-1] +1; }
    	}
    }
    return 0;
}