#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool check(pair<int,int>& x,pair<int,int>& y){
    if(x.second==y.second){
        return x.first<y.first;
    }
    return x.second<y.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int users_count;
    vector<pair<int,int>>user;
    vector<int>a(100);
    cin>>users_count;
    for(int i=0;i<users_count;i++){
        int user_id,bal;
        cin>>user_id>>bal;
        user.emplace_back(user_id,bal);
        a[user_id-1]=bal;
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int fu,tu,amount;
        bool c=true;
        cin>>fu>>tu>>amount;
        if(a[fu-1]>=amount){
            a[fu-1]-=amount;
            a[tu-1]+=amount;
        }
        else{
            c=false;
        }
        if(c){
            cout<<"Success\n";
        }
        else{
            cout<<"Failure\n";
        }
    }
    cout<<"\n";
    for(auto& i:user){
        int b=a[i.first-1];
        i.second=b;
    }
    sort(user.begin(),user.end(),check);
    for(auto i:user){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    return 0;
}
