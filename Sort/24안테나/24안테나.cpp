#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int home[200000];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> home[i];
    }
    
    sort(home, home+n);
    
    cout << home[(n-1)/2] << endl;
}