#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;


int process(vector<pair<int,int>> v, int n){

    
    int dp[17] = {0,};

    for(int i = n; i > 0; i--){
        int time = v[i-1].first;
        int pay = v[i-1].second;
        
        if(i + time <= n + 1){

            dp[i] = max({dp[i+1], dp[i+time] + pay});
        }
        else dp[i] = dp[i+1];
    }    
    
    return dp[1];

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> v;

    for(int i = 1; i <= n; i++){
        int t, p;
        cin >> t >>p;
        v.push_back({t,p});
    
    }

    int answer = process(v,n);

    cout << answer << endl;

}
