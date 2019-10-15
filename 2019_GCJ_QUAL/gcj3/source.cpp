#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int N;
        cin >> N;
        vector<string> W(N);
        for(int i=0;i<N;i++)
            cin >> W[i];
        vector<vector<int>> v(1, vector<int>(26,-1)); // v[i] is a vector of children of node i
        vector<int> val(1, -1);
        vector<int> count(1, 0);
        vector<bool> endpoint(1, false);
        vector<int> par = {-1};
        int num_nodes = 1;

        for(string word : W){
            int x = 0;
            for(int j=word.size()-1;j>=0;j--){
                int y = word[j]-'A';

                if(v[x][y] == -1){
                    v.emplace_back(26, -1);
                    val.push_back(y);
                    count.push_back(0);
                    par.push_back(x);
                    endpoint.push_back(false);

                    v[x][y] = num_nodes;
                    num_nodes++;
                }

                x = v[x][y];
                count[x]++;
            }
            endpoint[x] = true;
        }

        int ret=0;
        while(true){
            // find least val > 1
            int min=INT_MAX,min_index;
            for(int i=num_nodes-1;i>=0;i--){
                if(count[i] >= 2 && count[i] < min){
                    min = count[i];
                    min_index = i;
                }
            }
            if(min == INT_MAX)
                break;

            ret += 2;
            count[min_index] = 0;
            int i = par[min_index];
            while(i != -1){
                count[i] -= 2;
                i = par[i];
            }
        }
        cout << "Case #" << t << ": " << ret << endl;

        // for(int i=0;i<num_nodes;i++){
        //     if(count[i] > 1)
        //         cout << i << "\t" << (char)('A'+val[i]) << "\t" << count[i] << endl;
        // }
        // cout << endl;
    }
    return 0;
}