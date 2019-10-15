
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int N;
const vector<pair<int,int>> d = {{0,1}, {-1,0}, {0,-1}, {1,0}};

void rotate(int& i, int& j, int rot){
    int i_copy = i;
    if(rot == 1){
        i = j;
        j = (N-1) - i_copy;
    }
    if(rot == -1){
        i = (N-1)-j;
        j = i_copy;
    }
    if(rot == 2){
        i = (N-1)-i;
        j = (N-1)-j;
    }
}

int main() {    
    cin >> N; cin.ignore();
    cerr << N << endl;

    vector<vector<string>> m(6, vector<string>(N));
    for(int s=0;s<6;s++){
        for (int i = 0; i < N; i++) {
            cin >> m[s][i]; cin.ignore();
            cerr << m[s][i] << endl;
        }
    }
    string side;
    cin >> side; cin.ignore();
    cerr << side << endl;
    bool follow_left = (side == "L");

    int start_i,start_j,start_s;
    int start_dir;
    
    for(int s=0;s<6;s++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(m[s][i][j] != '0' && m[s][i][j] != '#'){
                    if(m[s][i][j] == '>') start_dir = 0;
                    if(m[s][i][j] == '^') start_dir = 1;
                    if(m[s][i][j] == '<') start_dir = 2;
                    if(m[s][i][j] == 'v') start_dir = 3;
                    m[s][i][j] = '0';
                    start_i = i;
                    start_j = j;
                    start_s = s;
                    cerr << "start " << start_j << "," << start_i << endl;
                }
            }
        }
    }
    
    vector<vector<vector<int>>> count(6, vector<vector<int>>(N, vector<int>(N, 0)));
    int cur_i = start_i;
    int cur_j = start_j;
    int s = start_s;
    int dir = start_dir;
    
    int t=0;
    bool moved = false;

    do {
        // look forward, else turn
        auto [di, dj] = d[dir];
        int ni = cur_i + di; 
        int nj = cur_j + dj;
        int ns = s;
        int nd = dir;

        if(!(ni >= 0 && ni < N && nj >=0 && nj < N)){
            int rot;
            ni = (ni + N) % N;
            nj = (nj + N) % N;
            // revise based on s(6) and dir(4)
            if(s == 0){
                if(dir == 0){      ns = 3; rot = 1; }
                else if(dir == 1){ ns = 5; rot = 0; }
                else if(dir == 2){ ns = 1; rot = -1;}
                else if(dir == 3){ ns = 2; rot = 0; }
            }
            else if(s == 1){
                if(dir == 0){      ns = 2; rot = 0; }
                else if(dir == 1){ ns = 0; rot = 1; }
                else if(dir == 2){ ns = 5; rot = 2;}
                else if(dir == 3){ ns = 4; rot = -1; }
            }
            else if(s == 2){
                if(dir == 0){      ns = 3; rot = 0; }
                else if(dir == 1){ ns = 0; rot = 0; }
                else if(dir == 2){ ns = 1; rot = 0;}
                else if(dir == 3){ ns = 4; rot = 0; }
            }
            else if(s == 3){
                if(dir == 0){      ns = 5; rot = 2; }
                else if(dir == 1){ ns = 0; rot = -1; }
                else if(dir == 2){ ns = 2; rot = 0;}
                else if(dir == 3){ ns = 4; rot = 1; }
            }
            else if(s == 4){
                if(dir == 0){      ns = 3; rot = -1; }
                else if(dir == 1){ ns = 2; rot = 0; }
                else if(dir == 2){ ns = 1; rot = 1;}
                else if(dir == 3){ ns = 5; rot = 0; }
            }
            else if(s == 5){
                if(dir == 0){      ns = 3; rot = 2; }
                else if(dir == 1){ ns = 4; rot = 0; }
                else if(dir == 2){ ns = 1; rot = 2;}
                else if(dir == 3){ ns = 0; rot = 0; }
            }
            else {
                cerr << "ERROR" << endl;
                return 0;
            }
            rotate(ni, nj, rot);
            nd = (dir - rot + 40) % 4;
        }

        // if(ni >= 0 && ni < N && nj >=0 && nj < N && m[ni][nj] == '0'){
        if(m[ns][ni][nj] == '0'){
            cur_i=ni;
            cur_j=nj;
            s = ns;
            dir = nd;

            moved = true;
            dir = (dir + (follow_left ? 1 : 3)) % 4;
            count[ns][ni][nj]++;
            
        }
        else {
            dir = (dir + (follow_left ? 3 : 1)) % 4;
            // cerr << "rot" << dir << endl;
        }
        // cerr << "[" << s << "] " << cur_j << "," << cur_i << "\t" << dir << endl;
        
    } while(!(s == start_s && cur_i == start_i && cur_j == start_j && (dir == start_dir || moved)));
    
    for(int s=0;s<6;s++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(m[s][i][j] == '#')
                    cout << '#';
                else
                    cout << count[s][i][j];                
            }
            cout << endl;
        }
    }
}