#include <bits/stdc++.h>

using namespace std;

vector<set<int>> A;
vector<set<int>> A1;

vector<int> V;
vector<int> status;
vector<int> z;

bool failed = false;

int f(int i){
    if(status[i] == 2) return V[i];
    if(status[i] == 1) {
        // problems?
        // cout << "???" << endl;
        failed = true;
        return -1;
    }
    status[i] = 1;
    int worse = 0;
    for(auto x : A[i]){
        worse = max(worse, f(z[x]));
    }
    V[i] = worse + 1;
    status[i] = 2;
    return V[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    A = vector<set<int>>(N+M);
    A1 = vector<set<int>>(N+M);
    z = vector<int>(N+M, 0);
    iota(z.begin(), z.end(), 0);
    V = vector<int>(N+M, -1);
    status = vector<int>(N+M, 0);

    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++) {
            if(s[j] == '>') // then dish 1i > dish 2j
                A[i].insert(j+N);            
            else if(s[j] == '<')
                A[j+N].insert(i);
            else {
                A1[i].insert(j+N);
                A1[j+N].insert(i);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(auto x : A1[i]){
            int a = i;
            int b = x;
            if(z[b] < z[a]) swap(a, b);
            if(z[b] == z[a]) continue;
            // merge z[b] into z[a]
            for(auto g : A[z[b]])
                A[z[a]].insert(g);
            A[z[b]].clear();
            z[b] = z[a];
        }
    }

    for(int i=0;i<N+M;i++){
        f(z[i]);
    }

    if(failed){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i=0;i<N;i++)
        cout << V[z[i]] << " ";    
    cout << endl;
    for(int i=0;i<M;i++)
        cout << V[z[i+N]] << " ";
    cout << endl;
    return 0;
}