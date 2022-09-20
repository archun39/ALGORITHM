#include <stdio.h>
#include <iostream>
using namespace std;

int N,K;

void swap(int *a, int *b);
void change(int A[], int B[]);

int main(){
    
    cin >> N >> K;
    int A[N];
    int B[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        cin >> B[i];
    }

    for(int i=0; i<K; i++){
        change(A,B);
    }
    int answer =0;
    for(int i=0; i<N; i++){
        answer += A[i];
    }
    cout << answer << endl;
    
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void change(int A[], int B[]){
    int minA = 1e9;
    int maxB = 0;
    int idxA;
    int idxB;
    for(int i=0; i<N; i++){
        if(minA > A[i]) {
            minA = A[i];
            idxA = i;
        }
    }
    for(int i=0; i<N; i++){
        if(maxB < B[i]) {
            maxB = B[i];
            idxB = i;
        }
    }
    swap(&A[idxA],&B[idxB]);
}
