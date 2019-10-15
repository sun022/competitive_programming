#include <bits/stdc++.h>

using namespace std;

const vector<pair<int,int>> dir = {
    {1,2},{-1,2},{1,-2},{-1,-2},
    {2,1},{-2,1},{2,-1},{-2,-1}
};

bool canTake(int x1, int y1, int x2, int y2){
    if(abs(x1-x2) == 1 && abs(y1-y2) == 2)
        return true;
    if(abs(x1-x2) == 2 && abs(y1-y2) == 1)
        return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;


    vector<vector<int>> w(N, vector<int>(M, -1));
    {
        queue<tuple<int,int,int>> q;
        w[N/2 - 1][M/2 - 1] = 0;
        q.push({N/2 - 1,M/2 - 1,0});
        
        while(!q.empty()){
            auto [i,j,d] = q.front(); q.pop();
            
            for(auto [di,dj]:dir){
                int i1 = i+di; int j1 = j+dj;
                if(!(0 <= i1 && i1 < N && 0 <= j1 && j1 < M))
                    continue;
                if(w[i1][j1] == -1){
                    w[i1][j1] = d+1;
                    q.push({i1,j1,d+1});
                }
            }
        }
    }
    vector<vector<int>> b(N, vector<int>(M, -1));
    {
        queue<tuple<int,int,int>> q;
        b[N/2][M/2 - 1] = 0;
        q.push({N/2 ,M/2 - 1,0});
        
        while(!q.empty()){
            auto [i,j,d] = q.front(); q.pop();
            
            for(auto [di,dj]:dir){
                int i1 = i+di; int j1 = j+dj;
                if(!(0 <= i1 && i1 < N && 0 <= j1 && j1 < M))
                    continue;
                if(b[i1][j1] == -1){
                    b[i1][j1] = d+1;
                    q.push({i1,j1,d+1});
                }
            }
        }
    }

    //cout << "tth for white:" << w[x1][y1] << endl;
    //cout << "tth for black:" << b[x2][y2] << endl;
    
    bool white;
    if(canTake(x1,y1,x2,y2))
        white = true;
    else if(w[x1][y1] <= b[x2][y2])
        white = true;
    else
        white = false;
    
    cout << (white ? "WHITE" : "BLACK") << endl;
    
    bool nextWhite = true;
    int myX = white ? x1 : x2;
    int myY = white ? y1 : y2;
    int oppX = white ? x2 : x1;
    int oppY = white ? y2 : y1;

    while(true){

        if((nextWhite && white) || (!nextWhite && !white)){
            if(canTake(myX, myY, oppX, oppY)){
                cout << oppX+1 << " " << oppY+1 << endl;
                return 0;
            }
            
            int curDist = white ? w[myX][myY] : b[myX][myY];
            int bestDist = INT_MAX;
            pair<int,int> bestMove;
            for(auto [di,dj]:dir){
                int i1 = myX+di; int j1 = myY+dj;
                if(!(0 <= i1 && i1 < N && 0 <= j1 && j1 < M))
                    continue;
                if(canTake(oppX, oppY, i1, j1)) continue;
                int d = (white ? w[i1][j1]:b[i1][j1]);
                if(d < bestDist){
                    bestDist = d;
                    bestMove = {i1, j1};
                }
            }
            myX = bestMove.first;
            myY = bestMove.second;
            cout << myX+1 << " " << myY+1 << endl;
            if(bestDist == 0) return 0;
        }
        else {
            int x,y; cin >> x >> y; x--; y--;
            if(x == -2)
                return 0;
            oppX = x;
            oppY = y;
            
        }

        nextWhite = !nextWhite;
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << b[i][j] << " ";

    //     }
    //     cout << endl;
    // }


    return 0;
}