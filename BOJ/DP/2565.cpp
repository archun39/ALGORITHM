#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAXV 500 + 1
using namespace std;

//LIS

struct line{
    int a;
    int b;
    
};

int n;
vector<line> v;

int DP[MAXV];

bool compare(line A, line B){
    return A.a < B.a;
}


void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        line tmp;
        cin >> tmp.a >> tmp.b;
        v.push_back(tmp);
    }
}

void process(){
    
    
    for(int i = 0; i < n; i++){
        if(DP[i] == 0) DP[i] = 1;
        for(int j = 0; j < i; j++){
            if(v[i].b > v[j].b) {
                if(DP[i] < DP[j] + 1){
                    
                    DP[i] = max(DP[i], DP[j] + 1);
                }
            }
        }
    }
    

    int answer = 0;
    for(int i = 0; i <n; i++){
        if(answer < DP[i]) answer = DP[i];
    }
    

    cout << n - answer << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    sort(v.begin(), v.end(), compare);
    process();

}