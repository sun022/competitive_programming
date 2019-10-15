#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    if(N < M) {
        cout << "1" << endl;
        return 0; 
    }

    // lets solve N,M assuming we solved n,M n<N

    // then, the FINAL gem is either 0 or 1
    // if 1 then there's f(n-1, m) of these
    // if 0 then that fixes m gems and so there's f(n-m, m) of these

    list<int> x(M, 1);
    // offset = 0; // x[i] = f[offset + i];

    int zeros = 0;
    for(int n = M; n <= N; n++){
        // f[n] = f[n-1] + f[n-M];
        x.push_back(x.back() + x.front());
        if(x.back() >= 1000000007)
            x.back() -= 1000000007;
        x.pop_front();
        // offset++;

        if(x.back() == 0)
            zeros++;
        else
            zeros=0;
        
        if(zeros == M)
            break;
    }
    cout << x.back() << endl;

    return 0;
}