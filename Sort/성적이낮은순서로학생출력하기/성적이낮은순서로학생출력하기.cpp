#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<pair<int,string>> v;
    for(int i=0; i<N; i++){
        string name;
        int num;
        cin >> name >> num;
        v.push_back({num,name});
    }
    sort(v.begin(),v.end());

    for(int i=0; i<N; i++){
        string name = v[i].second;
        cout << name << " ";
    }
}
