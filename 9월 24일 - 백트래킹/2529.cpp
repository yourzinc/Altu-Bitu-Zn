#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int a, int b, char opr)
{
    if( (opr=='<' && a<b) || (opr=='>' && a>b) ) return true;
    return false;
}

vector<string> solution(vector<char> v, int k)
{
    vector<string> pass_number;
    
    string answer = "";
    bool flag;

    vector<int> number(10);
    for(int i=0; i<10; i++) number[i]=i;
    
    do
    {
        flag = true;
        for(int i=0; i<k; i++)
        {
            if(!check(number[i],number[i+1],v[i]))
            {
                flag = false;
                break;
            }
        }
        
        if(flag)
        {
            for(int i=0; i<=k; i++) answer+=number[i]+'0';
            pass_number.push_back(answer);
            answer="";
        }
        
        reverse(number.begin()+k+1, number.end());
    } while(next_permutation(number.begin(),number.end()));
    
    return pass_number;
}

int main()
{
    // input
    int k;
    cin>>k;
    
    cin.ignore();
    
    string s;
    getline(cin,s);
    
    vector<char> v;
    
    char c;
    stringstream stream;
    stream.str(s);
    while(stream>>c) v.push_back(c);
    
    // solution
    vector<string> vv = solution(v,k);
    sort(vv.begin(),vv.end());

    // print
    cout<<vv[vv.size()-1]<<"\n";
    cout<<vv[0];
    
    return 0;
}