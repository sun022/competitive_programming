#include <bits/stdc++.h>

using namespace std;

inline bool winner(const int *g, const int p){
    if(g[0] == p && g[1] == p && g[2] == p) return true;
    if(g[3] == p && g[4] == p && g[5] == p) return true;
    if(g[6] == p && g[7] == p && g[8] == p) return true;

    if(g[0] == p && g[3] == p && g[6] == p) return true;
    if(g[1] == p && g[4] == p && g[7] == p) return true;
    if(g[2] == p && g[5] == p && g[8] == p) return true;

    if(g[0] == p && g[4] == p && g[8] == p) return true;
    if(g[2] == p && g[4] == p && g[6] == p) return true;
    return false;
}

inline bool full(const int *g){
    for(int i=0;i<9;i++)
        if(g[i] == 0) return false;
    return true;
}

struct State {
    int nextPlayer; // -1, 0, 1
    int nextGrid; // 0-8 or -1 for any
    array<int, 9> og; // -1, 0, 1
    array<int, 81> g; // -1, 0, 1
};


bool gameOver(const State &x){
    if(x.nextPlayer == 0 || x.nextPlayer == 2 || x.nextPlayer == -2) return true;
    return false;
}

int gameOverWinner(const State &x){
    if(x.nextPlayer == 0){ // game over draw but then most mini-cells wins
        int x_mini = 0;
        int o_mini = 0;
        for(int i=0;i<9;i++){
            x_mini += (x.og[i] == 1);
            o_mini += (x.og[i] == -1);
        }
        if(x_mini > o_mini)
            return 1;
        else if(x_mini < o_mini)
            return -1;
        else
            return 0;
    }
    else if(x.nextPlayer == 2){
        return 1;
    }
    else if(x.nextPlayer == -2){
        return -1;
    }
    throw "error in gameOverWinner()";
}

string to_char(int x){
    if(x == -1) return "O";
    if(x == 1) return "X";
    if(x == 0) return ".";
    throw runtime_error("unexpected value '" + to_string(x) + "'");
}

string to_string(const State &x){
    string s;
    if(!gameOver(x))
        s+= (string)"In progress: " + (x.nextPlayer== 1 ? "X":"O") + " to play (" + to_string(x.nextGrid) + ")\n";
    else{
        int w = gameOverWinner(x);
        if(w == 1) s+= "Game over: X wins\n";
        else if(w == -1) s+= "Game over: O wins\n";
        else if(w == 0) s+= "Game over: Draw\n";
    }
    string s1;
    string s2;
    string s3;
    for(int i=0;i<9;i++){
        s1 += to_char(x.g[9*i + 0]) + to_char(x.g[9*i + 1]) + to_char(x.g[9*i + 2]) + ' ';
        s2 += to_char(x.g[9*i + 3]) + to_char(x.g[9*i + 4]) + to_char(x.g[9*i + 5]) + ' ';
        s3 += to_char(x.g[9*i + 6]) + to_char(x.g[9*i + 7]) + to_char(x.g[9*i + 8]) + ' ';
        if(i % 3 == 2){
            s += s1 + '\n' + s2 + '\n' + s3 + "\n\n";
            s1 = "";s2 = "";s3 = "";
        }
    }
    return s;
}

void get_next_specific_grid(const State &x, int nextGridOveride, vector<State> &ret){
    if(x.og[nextGridOveride] != 0) return;
    for(int i=0;i<9;i++){
        if(x.g[nextGridOveride*9 + i] != 0) continue;
        ret.push_back(x);
        ret.back().g[nextGridOveride*9 + i] = x.nextPlayer;
        
        if(winner(&ret.back().g[nextGridOveride*9], x.nextPlayer)){
            ret.back().og[nextGridOveride] = x.nextPlayer;
            if(winner(&ret.back().og[0], x.nextPlayer))
                ret.back().nextPlayer = 2*x.nextPlayer; // game over player win
            else if(full(&ret.back().og[0]))
                ret.back().nextPlayer = 0; // game over draw
        }
        else if(full(&ret.back().g[nextGridOveride*9])){
            ret.back().og[nextGridOveride] = 2; // draw
            if(full(&ret.back().og[0]))
                ret.back().nextPlayer = 0; // game over draw
        }
        

        ret.back().nextGrid = (ret.back().og[i] == 0 ? i : -1);
        if(ret.back().nextPlayer == 1 || ret.back().nextPlayer == -1)
            ret.back().nextPlayer *= -1;
    }
}

void get_next(const State &x, vector<State> &ret){
    // if x.nextGrid is set, we can play in any of those empty squares
    if(x.nextGrid != -1) 
        get_next_specific_grid(x, x.nextGrid, ret);
    else {
        for(int i=0;i<9;i++)
            get_next_specific_grid(x, i, ret);
    }
}

double get_score(int nextPlayer, int w, int d, int l, int N){
    int t = w + d + l;
    if(nextPlayer != 1 && nextPlayer != -1)
        throw runtime_error("unexpected player: '" + to_string(nextPlayer) + "'");
    if(t == 0)
        return 1000;
    
    if(nextPlayer == -1){
        //swap(w, l);
        w = t-w;
    }
    
    return (double)w/t + sqrt(2)*sqrt(log(N)/t);
}

int main(){
    srand(time(0));
    // lets try to find the optimal move for some specific state s    
    State s;
    s.nextPlayer = 1;
    s.nextGrid = -1;
    for(int i=0;i<9;i++) s.og[i] = 0;
    for(int i=0;i<81;i++) s.g[i] = 0;

    // lets add max of 1 leaf per sim
    vector<State> treeState;
    vector<bool> treeLeaf; // 1 = leaf, 0 = not leaf
    vector<int> treeStateWin;
    vector<int> treeStateDraw;
    vector<int> treeStateLoss;

    vector<vector<int>> treeChildren;

    treeState.push_back(s);
    treeLeaf.push_back(true);
    treeStateWin.push_back(0);
    treeStateDraw.push_back(0);
    treeStateLoss.push_back(0);
    treeChildren.push_back({});

    for(int sim=1;sim<=10000; sim++){
        vector<int> path;
        int stateIndex = 0;
        path.push_back(0);
        while(!treeLeaf[stateIndex]){ 
            int bestIndex = -1;
            double bestScore;
            for(auto y : treeChildren[stateIndex]){
                double score = get_score(treeState[stateIndex].nextPlayer, treeStateWin[y], treeStateDraw[y], treeStateLoss[y], treeStateWin[stateIndex] + treeStateDraw[stateIndex] + treeStateLoss[stateIndex]);
                if(bestIndex == -1 || score >= bestScore){
                    bestIndex = y;
                    bestScore = score;
                }
            }
            stateIndex = bestIndex;
            path.push_back(stateIndex);
        }

        // cout << "tree sim length:" << path.size() << endl;

        // when we have reached a leaf node
        // only expand if we actually explored this node before
        
        if(treeStateWin[stateIndex]+treeStateDraw[stateIndex]+treeStateLoss[stateIndex] != 0 && !gameOver(treeState[stateIndex])){
            int prevSize = treeState.size();
            vector<State> valid_next;
            get_next(treeState[stateIndex], valid_next);
            // cout << "expanded leaf of size " << valid_next.size() << endl;
            
            for(int k = 0; k < valid_next.size(); k++){
                treeState.push_back(valid_next[k]);
                treeLeaf.push_back(true);
                treeStateWin.push_back(0);
                treeStateDraw.push_back(0);
                treeStateLoss.push_back(0);
                treeChildren.push_back({});
                treeChildren[stateIndex].push_back(prevSize + k);
            }
            treeLeaf[stateIndex] = false;

            stateIndex = prevSize + rand() % valid_next.size();
            path.push_back(stateIndex);
        }
        // cout << "simulating remainder of game with randomness from state " << stateIndex << endl;
        State x = treeState[stateIndex];
        
        // cout << to_string(x);


        // lets do a random sim (random over valid moves)
        while(!gameOver(x)){

            vector<State> valid_next;
            get_next(x, valid_next);
            
            if(valid_next.size() == 0){
                cerr << "!" << endl; exit(0);
            }

            // pick random
            x = valid_next[rand() % valid_next.size()];
        }

        int gameRes = gameOverWinner(x);
        // update win stats for states on path
        for(auto s : path){
            treeStateWin[s] += (gameRes == 1);
            treeStateDraw[s] += (gameRes == 0);
            treeStateLoss[s] += (gameRes == -1);
        }
        // cout << endl;
        // cout << to_string(x);
    }

    for(int i=0;i<=81;i++){
        cout << i << "\t" << treeStateWin[i] << "\t" << treeStateDraw[i] << "\t" << treeStateLoss[i] << endl;
    }

    return 0;
}