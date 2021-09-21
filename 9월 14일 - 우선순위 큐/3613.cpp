#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main()
{
    bool java=true, cpp=true;

    string s;
    cin>>s;

    vector<int> under_bar;
    vector<int> upper_case;

    // java check
    if('a'> s[0] || s[0] >'z')  java = false;
    if(s[0] == '_') cpp = false;
    
    for(int i=0; i<s.size(); i++)
    {
        // java = false && cpp = false
        if(!java && !cpp) break;

        // java check        
        if(java && s[i]=='_') java = false;
        
        // cpp check
        if( 'A' <= s[i] && s[i] <= 'Z') 
        {   
            if(cpp) cpp = false;
            
            // Uppercase
            upper_case.push_back(i);
        }

        // under_bar
        if(s[i] == '_'){
            if(s[i+1]=='_') cpp = false;
            if(i==s.size()-1) cpp = false;
            
            under_bar.push_back(i);
        }
    }

    if(java && cpp)
        cout<<s;
    else if(java)
    {
        // cout<<"java"<<"\n";
        // java -> cpp
        while(!upper_case.empty())
        {
            int i = upper_case.back();
            s[i] = tolower(s[i]);
            s.insert(i,"_");
            upper_case.pop_back();
        }
        cout<<s;
    }
    else if(cpp)
    {   
        // cout<<"cpp"<<"\n";
        // cpp -> java
        while(!under_bar.empty())
        {
            int j = under_bar.back();
            s.erase(j,1);
            s[j] = toupper(s[j]);
            under_bar.pop_back();
        }
        cout<<s;
    }
    else    cout<<"Error!";

    return 0;
}