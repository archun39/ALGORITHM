#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 10000 + 1
#define INF 1e9
using namespace std;

struct road{
    int startPos;
    int endPos;
    int len;
};

int n, d;
vector<road> v;
int highWay[MAX];


bool cmp(road A, road B){
    return A.startPos < B.startPos;
}

void input(){
    cin >> n >> d;

    for(int i = 0; i <  n; i++){
        road r;
        cin >> r.startPos >> r.endPos >> r.len;
        v.push_back(r);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 1; i < MAX; i++){
        highWay[i] = INF;
    }
}

int process(){


    for(int i = 0; i <= d; i++){
        
        for(int j = 0; j < v.size(); j++){
            
            if(v[j].startPos != i) continue;
            if(highWay[v[j].endPos] > v[j].len + highWay[i]){
                highWay[v[j].endPos] = v[j].len + highWay[v[j].startPos];
                //cout << v[j].startPos << " : " << v[j].endPos<<endl;
            }
        }
        if(highWay[i+1] == INF) highWay[i+1] = highWay[i]+1;
        else{
            highWay[i+1] = min(highWay[i+1],highWay[i]+1);
        }
        //cout << i << " : " << highWay[i] << endl;
    }

    return highWay[d];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();
    cout << process() << endl;
}