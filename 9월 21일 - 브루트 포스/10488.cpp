#include <iostream>
#include <vector>

using namespace std;

vector<int> tri_number;

int solution(int n)
{
    int i,j,k;
    
    for(i=0; i<tri_number.size(); i++){
        for(j=0; j<tri_number.size(); j++){
            for(k=0; k<tri_number.size(); k++){
                if(!(n-tri_number[k]-tri_number[j]-tri_number[i])) return 1;
            }
        }
    }
    return 0;
}

int main()
{
    //Input
    int t;
    cin>>t;
    
    for(int i=1; i*(i+1)/2 < 1000 ; i++)
        tri_number.push_back(i*(i+1)/2);
    
    
    while(t--)
    {
        int k;
        cin>>k;

        //Output
        cout<<solution(k)<<"\n";
    }
    return 0;
}