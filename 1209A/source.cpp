#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    
    sort(A.begin(), A.end());
    
    vector<int> colours;
    for(auto x : A){
        bool painted = false;
        for(int i=0;i != colours.size(); i++){
            int c = colours[i];
            if(x % c == 0){
                painted = true;
                // do nothing
            }
        }
        if(!painted)
            colours.push_back(x);
    }

    cout << colours.size() << endl;

    return 0;
}