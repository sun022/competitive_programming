#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int x = 0;
    for(auto c : s)
        x += (c == '1');

    vector<int> A(N) ,B(N);
    for(int i=0;i<N;i++)
        cin >> A[i] >> B[i];

    for(int t=0;t<240;t++){
        int y = 0;
        for(int i=0;i<N;i++){
            if(t >= B[i] && (t-B[i]) % A[i] == 0){
                // toggle i
                s[i] = (s[i] == '1' ? '0' : '1');
            }
            y += (s[i] == '1');
        }
        x = max(x, y);
    }
    cout << x << endl;
    return 0;
}