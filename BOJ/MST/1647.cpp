#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct house{
    int A;
    int B;
    int Cost;
};

bool compare(house A, house B){
    return A.Cost < B.Cost ? true : false;
}

int N, M;

vector<house> h;
int parent[100001];

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        house tmp;
        cin >> tmp.A >> tmp.B >> tmp.Cost;
        h.push_back(tmp);
    }

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }
}

int getParent(int num){
    if(parent[num] == num) return num;
    return getParent(parent[num]);
}

bool isCycle(house home){
    int a = getParent(home.A);
    int b = getParent(home.B);
    if(a == b) return true;
    return false;
}

void unionParent(house home){
    int a = getParent(home.A);
    int b = getParent(home.B);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int MST(){

    int totalCost = 0;

    sort(h.begin(), h.end(), compare);
    
    int cnt = 0;
    for(int i = 0; i < M; i++){
        if(cnt == N-2) break;
        house home = h[i];
        if(!isCycle(home)){
            totalCost += home.Cost;
            unionParent(home);        
            cnt++;
        }
    }
    return totalCost;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input();
    cout << MST() << endl;
    
    return 0;
}
