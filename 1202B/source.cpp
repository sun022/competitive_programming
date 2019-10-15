#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int64_t> count(10,0);

    for(int i=1;i<s.size();i++){
        int d = (10+s[i]-s[i-1]) % 10;
        count[d]++;
    }

    //for(int i=0;i<10;i++)
    //    cout << i << ":\t" << count[i] << endl;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            // i-j counter
            vector<int> min_insert(10, INT_MAX);
            for(int a=0;a<=10;a++){ 
                for(int b=0;b<=10;b++){
                    if(a==0 && b==0) continue;
                    int v = (a*i + b*j) % 10;
                    min_insert[v] = min(min_insert[v], a+b-1);
                }
            }
            bool possible = true;
            int64_t ret = 0;
            for(int k=0;k<10;k++){
                if(count[k] > 0 && min_insert[k] == INT_MAX)
                    possible = false;
                ret += count[k]*min_insert[k];
            }
            if(!possible)
                ret = -1;
            cout << ret << " ";           
            
        }
        cout << endl;
    }

    return 0;
}