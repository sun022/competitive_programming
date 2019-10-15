#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t N, D, E;
    cin >> N >> D >> E;
    E *= 5;

    int64_t best = N;
    for(int x=0;;x++) {
        if(x*D > N) break;
        int y = (N - x*D) / E;

        best = min(best, N - x*D - y*E);
    }

    cout << best << endl;

    return 0;
}