#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    set<int> A;
    for(int i=0;i<N;i++){
        int z; cin >> z;
        A.insert(z);
    }

    int S = A.size();
    if(S == 1){
        cout << "0" << endl;
        return 0;
    }
    if(S == 2){
        auto it = A.begin();
        int x = *it; it++;
        int y = *it; it++;
        if((y-x)%2 == 0)
            cout << (y-x)/2 << endl;
        else
            cout << y-x << endl;     
        return 0;
    }
    if(S == 3){
        auto it = A.begin();
        int x = *it; it++;
        int y = *it; it++;
        int z = *it; it++;

        if((z-x)%2 == 0 && (x+z)/2 == y)
            cout << z-y << endl;
        else
            cout << "-1" << endl;
        return 0;        
    }
    if(S>=4){
        cout << "-1" << endl;        
    }
    return 0;
}