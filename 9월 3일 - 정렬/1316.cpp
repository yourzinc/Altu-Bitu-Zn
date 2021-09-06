#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(string s){
  vector<char> checked;
    
	char present = s[0];
	checked.push_back(present);
	
	for(int i=1; i<s.size(); i++)
	{
		auto it = find(checked.begin(), checked.end(), s[i]);
		if(it == checked.end()){ present = s[i]; checked.push_back(present); }
		else if(present == s[i]) continue;
		else return false; 
	}
	return true;
}

int main()
{
    int N,cnt=0;
    string str;
    cin>>N;
    while(N--)
    {
        cin>>str;
        if(check(str)) cnt++;
    }
    cout<<cnt;
    return 0;
}