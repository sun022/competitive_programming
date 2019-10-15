#include <bits/stdc++.h>

using namespace std;

bool f(const map<int,int> &x){
    if(x.size() == 0) return false;
    if(x.size() == 1){
        auto [Aval, Acount] = *(x.begin());
        return (Aval == 1 || Acount == 1);
    }
    if(x.size() > 2) return false;
    auto [Aval, Acount] = *(x.begin());
    auto [Bval, Bcount] = *(next(x.begin()));

    if(Aval == 1 && Acount == 1) return true;
    if(Bval == Aval + 1 && Bcount == 1) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i]; A[i]--;
    }

    vector<int> count(100000, 0);
    map<int, int> x;
    int ret=0;
    for(int i=0;i<N;i++){
        if(count[A[i]] != 0){
            x[count[A[i]]]--;
            if(x[count[A[i]]] == 0)
                x.erase(count[A[i]]);
        }
        count[A[i]]++;
        x[count[A[i]]]++;

        // check if count is of the form {n, n, n, n+1}, or {n, n, n, n, 1} (or {1,1,1,1,1}) (or {n}
        if(f(x)){
            ret = i+1;
            //cout << ret << endl;
        }   
    }
    cout << ret << endl;

    return 0;
}