#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

struct flower{
    int start;
    int end;
    int period;
};

int n;
vector<flower> v;
int leftV, rightV;

bool cmp(flower A, flower B){
    if(A.start == B.start) return A.period > B.period;
    return A.start < B.start; 
}

int changeDay(int m, int d){
    int day = 0;
    for(int i = 1; i < m; i++){
        if(i == 2) day += 28;
        else if((i < 8 && i % 2 != 0) || (i >= 8 && i % 2 == 0)) day += 31;
        else day += 30;
    }
    return day + d;
}
void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        flower f;
        f.start = changeDay(a,b);
        f.end = changeDay(c,d);
        if(f.start > rightV || f.end < leftV) continue;
        if(f.start < leftV) f.start = leftV;
        if(f.end > rightV) f.end = rightV;
        f.period = f.end - f.start;
        v.push_back(f);
    }
}

int process(){
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        //cout << "flower :: " << v[i].start << " : " << v[i].end << " : " << v[i].period << endl;
    }
    
    bool findFlower = false;
    int countFlower = 0;
    int idx = 0;
    while(leftV < rightV){
        //cout << "while : " << leftV << " : " << rightV << endl;
        int maxP = 0;
        for(int i = idx; i < v.size(); i++){
            if(v[i].end <= leftV) continue;
            if(v[i].start > leftV) continue;
            //cout << v[i].period << endl;
            findFlower = true;
            if(maxP < v[i].end){
                maxP = v[i].end;
                idx = i;
            }
        }

        if(!findFlower) return 0;
        flower f = v[idx];
        leftV = f.end;
        countFlower++;
        findFlower = false;
    }
    return countFlower;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    leftV = changeDay(3,1);
    rightV = changeDay(11,30) + 1;
    //cout << " --- " << endl;
    //cout << leftV <<" : " <<rightV << endl;
    input();
    
    cout << process();

}