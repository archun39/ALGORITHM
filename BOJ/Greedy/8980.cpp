#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

struct box{
    int from;
    int to;
    int value;
};

bool compare(box A, box B){
    if(A.to == B.to) return A.from < B.from;
    return A.to < B.to;
}

int n, maxV , m , idx;
int total = 0;
int nowWeight = 0;
int truck[2000];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    
    cin >> n >> maxV;
    
    vector<box> town;

    cin >> m;

    idx = 0;

    for(int i = 0; i < m; i++){
        box tmp;
        cin >> tmp.from >> tmp.to >> tmp.value;

        town.push_back(tmp);
    }

    sort(town.begin(), town.end(), compare);

    for(int i = 0; i < m; i++){

        box b = town[i];

        int tmp = 0;
        for(int j = b.from; j < b.to; j++){
            tmp = max({tmp,truck[j]});
        }

        tmp = min({maxV - tmp, b.value});
        total += tmp;
        for(int j = b.from; j < b.to; j++){
            truck[j] += tmp;
        }
    }


    cout << total << endl;
    return 0;
}