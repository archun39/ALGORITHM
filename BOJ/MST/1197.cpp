#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

struct edge{
    int a;
    int b;
    int c; //weight
};

int parent[10000];

bool compareEdge(edge a, edge b){
    //오름차순
    return a.c < b.c ? true : false;
}

void init(int v){
    for(int i = 1; i <= v; i++){
        parent[i] = i;
    }
}

int getParent(int num){
    if(parent[num] == num) return num;
    return getParent(parent[num]);
}

bool isCycle(edge e){
    int a = getParent(e.a);
    int b = getParent(e.b);
    
    return a == b ? true : false;

}

void unionParent(edge e){
    int a = getParent(e.a);
    int b = getParent(e.b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int mst(vector<edge> &list){

    int totalValue = 0;

    sort(list.begin(), list.end(), compareEdge);

    for(int i = 0; i < list.size(); i++){
        if(!isCycle(list[i])){
            totalValue += list[i].c;
            unionParent(list[i]);
        }
    }

    return totalValue;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int v, e;
    cin >> v >> e;

    vector<edge> list(e);

    for(int i = 0; i < e; i++){
        edge tmp;
        cin >> tmp.a >> tmp.b >> tmp.c;

        list[i] = tmp;

    }

    init(v);
    cout << mst(list) << endl; 


    return 0;
}