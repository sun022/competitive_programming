#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, A, B;
    cin >> N >> M >> A >> B;
    int64_t g, x, y, z;
    cin >> g >> x >> y >> z;

    vector<vector<int>> h(N, vector<int>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            h[i][j] = g;
            g = (g*x + y) % z;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << h[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>> min_row(N, vector<int>(M));
    for(int i=0;i<N;i++){
        deque<int> q; // store indices of h[i]

        for(int j=0;j<M;j++){            
            if(q.size() != 0 && q.front() == j - B)
                q.pop_front();

            int val = h[i][j];
            while(q.size()!=0 && h[i][q.back()] >= val)
                q.pop_back();
            q.push_back(j);

            min_row[i][j] = h[i][q.front()];
        }
    }

    vector<vector<int>> min(N, vector<int>(M));
    for(int j=0;j<M;j++){
        deque<int> q; // store indices of h[*][j]

        for(int i=0;i<N;i++){            
            if(q.size() != 0 && q.front() == i - A)
                q.pop_front();

            int val = min_row[i][j];
            while(q.size()!=0 && min_row[q.back()][j] >= val)
                q.pop_back();
            q.push_back(i);

            min[i][j] = min_row[q.front()][j];
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << min_row[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << min[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int64_t sum = 0;
    for(int i=A-1;i<N;i++){
        for(int j=B-1;j<M;j++){
            sum += min[i][j];
        }
    }

    cout << sum << endl;
    return 0;
}