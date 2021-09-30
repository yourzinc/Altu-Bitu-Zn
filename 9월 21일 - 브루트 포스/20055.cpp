// 진행중입니다
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

int main()
{
    
    //Input
    int n, k; //n= 컨베이어 벨트의 길이 //k= 내구도가 0인 칸의 최대 개수
    cin>>n>>k;
    cin.ignore();
    
    deque<pair<int, bool>> belt; //deque
    
    string str, a;
    getline(cin,str);
    
    stringstream ss(str);
    
    while(ss>>a){
        pair<int, bool> p = make_pair(stoi(a),false);
        belt.push_back(p);
    }
    
    //Solution
        //conveyor_belt[0]= 1번 칸이 있는 올리는 위치
        //conveyor_belt[n-1]= n번 칸이 있는 내리는 위치
    
    int cnt=0, step=0;
    //cnt =내구도가 0인 칸의 개수
    //step =실행중인 단계
    
    int qq=0;
    while(cnt<k) //k개 이상이면 과정을 종료
    {
        step++;
        
        for(int i=0; i<2*n; i++)
        {
            cout<<belt[i].first<<" "<<belt[i].second<<"\n";
        }
        cout<<"---"<<"\n";
        
        belt.push_front(belt.back()); //한칸 회전
        belt.pop_back();
        
        belt[n-1].second = false; //내리는 위치- 로봇 즉시 내린다
        
        
       
        
        for(int i=n-2; i>=0; i-- )
        {
            if(belt[i].second && belt[i+1].first>0 && !belt[i+1].second ) //로봇이 있다면
            {
                //i-1번째 벨트 위의 로봇 앞으로 이동
                belt[i+1].first--;
                belt[i+1].second=true;
                belt[i].second=false;
                cout<<"move "<<i<<"to "<<i+1<<"\n";
            }
        }
        
        //올리는 위치- 로봇 올린다
        if(belt[0].first) belt[0].second=true;
        
        cnt=0;
        //내구도 0인 칸의 개수 확인
        for(int i=0; i<2*n; i++)
            if(!belt[i].first) cnt++;
        
    }
    
    //Print
    cout<<step;
    
    return 0;
}
