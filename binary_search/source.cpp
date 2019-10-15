#include <bits/stdc++.h>

using namespace std;

// int bin_search(int u, int v, const function<bool (const int)> F){
//     while(u!=v){        
//         int m = (u+v) >> 1;
//         if(F(m))
//             v = m;
//         else
//             u = m+1;
//     }
//     return u;
// }

int bin_search(int v, const function<bool (const int)> F){
    v >>= 1;
    int u = v;
    v++;

    while(v!=0){
        v >>= 1;
        u += (F(u) ? v : -v);
    }
    return u;
}

int main(){
    srand(time(0));
    int N = 1048575;
    vector<int> X(N);
    iota(X.begin(), X.end(), 0);

    // int r = rand()%(N+1);
    // cout <<r << endl;

    //std::chrono::high_resolution_clock t1,t2;
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        for(int i=0;i<10000000;i++){
            int r = rand()%(N+1);
            int g = bin_search(N,[&X,r](const int i){return X[i]<r;});
            // if(r!=g){cout << "ERROR:" << i << ":" << r << "," << g << endl;return 0;}
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
        std::cout << duration << " milliseconds" << endl;
    }
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        for(int i=0;i<10000000;i++){
            int r = rand()%(N+1);
            auto p = lower_bound(X.begin(), X.end(), 1, [r](int i, int j){return (i>=r) < j;});
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
        std::cout << duration << " milliseconds" << endl;
    }   
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        for(int i=0;i<10000000;i++){
            int r = rand()%(N+1);
            auto h = lower_bound(X.begin(), X.end(), r);
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
        std::cout << duration << " milliseconds" << endl;
    } 
    
    // cout << distance(X.begin(), h) << endl;

    
    // cout << distance(X.begin(), p) << endl;

    // int u = 0;
    // int v = N;
    // while(u!=v){
    //     cout << u << "," << v << endl;
    //     int m = (u+v)/2;
    //     if(X[m])
    //         v = m;
    //     else
    //         u = m+1;
    // }
    // cout << u << endl;

    return 0;
}