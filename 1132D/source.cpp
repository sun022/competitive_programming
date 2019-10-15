#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int64_t> A, B;

// is possible with x
bool f(double x){
    auto cmp = [](pair<double,double> a, pair<double,double> b) { return a.first > b.first;};
    priority_queue<pair<double,double>, vector<pair<double,double>>, decltype(cmp) > q(cmp);
    for(int i=0;i<N;i++){
        q.push(make_pair((double)A[i]/B[i], x/B[i]));
    }

    int t;
    for(t=0;t<K-1;t++){
        auto p = q.top();
        // cout << t << "\tplugging into " << p.second << " " << p.first << " -> " << p.first + (long double)x/B[p.second] << endl;
        
        if(p.first < (double)t - 1e-12){
            // cout << "failed" << endl;
            return false;
        }
        p.first += p.second;
        q.pop();
        q.push(p);
    }
    auto p = q.top();
    if(p.first < (double)t - 1e-12){
        // cout << "end failed: " << p.first << endl;
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    A = vector<int64_t>(N);
    B = vector<int64_t>(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> B[i];

    
    int64_t a=0,b=LLONG_MAX;
    if(f(0)){
        cout << 0 << endl;
        return 0;
    }
    if(!f(b)){
        cout << -1 << endl;
        return 0;
    }
    // f(a) false, f(b) true
    while(a + 1 != b){
        // cout << a << "," << b << endl;
        int64_t m = (a+b)/2;
        bool fm  = f((double)m);
        if(fm)
            b=m;
        else
            a=m;        
    }
    cout << b << endl;

    return 0;
}