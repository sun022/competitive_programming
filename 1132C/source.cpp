#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    //N = 5000; Q=5000;

    vector<int> L(Q), R(Q);
    vector<int> paint(N, 0);

    for(int i=0;i<Q;i++){
        cin >> L[i] >> R[i];
        //L[i]=1; R[i]=5000;
        L[i]--; R[i]--;
    }

    for(int i=0;i<Q;i++){
        for(int k=L[i]; k <= R[i]; k++)
            paint[k]++;
    }
    // for(int i=0;i<N;i++)
    //     cout << paint[i] << " ";
    // cout << endl;

    vector<int> one(N), two(N), three(N);
    for(int i=0;i<N;i++){
        one[i] = (i!=0 ? one[i-1] : 0) + (paint[i] >= 1 ? 1 : 0);
        two[i] = (i!=0 ? two[i-1] : 0) + (paint[i] >= 2 ? 1 : 0);
        three[i] = (i!=0 ? three[i-1] : 0) + (paint[i] >= 3 ? 1 : 0);
        // cout << one[i] << "\t" << two[i] << "\t" << three[i] << endl;
    }

    int best = 0;
    for(int a=0; a < Q;a++) {
        for(int b=a+1; b < Q;b++) {
            int score = 0;
            // cout << a << " " << b << endl;
            // calc loss
            array<pair<int,int>, 4> v = {
                make_pair(L[a], 1),
                make_pair(R[a]+1, -1),
                make_pair(L[b], 1),
                make_pair(R[b]+1, -1)
            };
            sort(v.begin(), v.end(), [](auto i, auto j){return i.first < j.first;});
            int x = 0;
            int n = 0;
            for(auto p : v){
                if(x <= p.first-1) {
                    if(n == 0)
                        score += one[p.first-1] - (x!=0 ? one[x-1] : 0);
                    else if(n == 1)
                        score += two[p.first-1] - (x!=0 ? two[x-1] : 0);
                    else if(n == 2)
                        score += three[p.first-1] - (x!=0 ? three[x-1] : 0);
                }
                // cout << x << " to " << p.first-1 << " = " << n << "\t" << score << endl;
                n += p.second;
                x = p.first;
            }
            // cout << x << " to " << N-1 << " = " << n << endl;
            if(x <= N-1) {
                score += one[N-1] - (x!=0 ? one[x-1] : 0);
            }

            // cout << score << endl;
            best = max(best, score);
        }
    }
    cout << best << endl;

    return 0;
}