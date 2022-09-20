#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &v);
void printAnswer(vector<int> v);
void swap(int *a, int *b);

int main(){
    int N;
    cin >> N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }

    
    sort(v);
    printAnswer(v);


}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(vector<int> &v){
    int idx = 0;
    int max = 0;
    while(idx<v.size()){
        int targetIdx;
        for(int i=idx; i<v.size(); i++){
            if(max < v[i]){
                max = v[i];
                targetIdx = i;
            }
        }
        swap(&v[targetIdx],&v[idx]);
        max = 0;
        idx++;
    }
}

void printAnswer(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}