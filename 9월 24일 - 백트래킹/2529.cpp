#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void solution(vector<char> v, int k)
{
    string answer = "";
    
    vector<bool> number(10) ={0}; // 사용한 숫자 check
    
    for(int i=0; i<k; k++)
    {
        if(v[i]=='<')
        {

        }
        else //v[i]=='>'
        {
            
        }
    }
}

int main()
{
    // input
    int k;
    cin>>k; //k= 부동호 문자의 개수
    
    cin.ignore();
    
    string s;
    getline(cin,s);
    
    vector<char> v;
    
    char c;
    stringstream stream;
    stream.str(s);
    while(stream>>c) v.push_back(c);
    
    // solution
    solution(v,k);
    
    // print

    return 0;
}
