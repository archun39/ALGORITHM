#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int a,b,v;
void input(){
    cin >> a >> b >> v;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();

    int leastH = v - a;
    int oneDay = a - b;
    int answer ;
    if(v == a) answer = 1;
    else if(leastH < oneDay) answer = 2;
    else {
        if(leastH % oneDay == 0) answer = leastH / oneDay +1;
        else answer = leastH / oneDay + 2;
    }
    cout << answer << endl;

}