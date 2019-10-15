#include <bits/stdc++.h>

using namespace std;

int M,N;

int dist_going_right(int s, int f){
    if(f >= s) return f-s;
    else return M-s+f;
}
int dist_going_left(int s, int f){
    return dist_going_right(f,s);
}

int dist(int a, int b){
    return min(dist_going_right(a,b), dist_going_right(b,a));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    vector<int> A(N),B(N);
    for(int i=0;i<N;i++)
        cin >> A[i];
    for(int i=0;i<N;i++)
        cin >> B[i];

    vector<int> z(N); iota(z.begin(), z.end(), 0);
    sort(z.begin(), z.end(), [&A](int i, int j){return A[i] < A[j];});

    vector<int> w(N); iota(w.begin(), w.end(), 0);
    sort(w.begin(), w.end(), [&B](int i, int j){return B[i] < B[j];});

    // need a 'root' candidate with nonzero distance to vacancy
    int r=0;
    while(r!=N){
        int val = B[w[r]];
        int u = 0, v = N;
        while(u != v){
            int m = (u+v)/2;
            if(A[z[m]] >= val)
                v = m;
            else
                u = m+1;
        }

        if(A[z[u]] == val)
            r++;
        else
            break;
    }
    if(r == N){
        cout << "0" << endl;
        return 0;
    }

    // cout << r << endl;

    // lets assume first candidate goes right 
    int64_t dist1 = 0;
    vector<int> match1(N);
    {
        int c = B[w[r]];
        int v_ind = 0;
        for(int i=0;i<N;i++)
            if(dist_going_right(c, A[z[i]]) < dist_going_right(c, A[z[v_ind]]))
                v_ind = i;

        match1[r] = v_ind;
        dist1 += dist(B[w[r]], A[z[v_ind]]);
        v_ind = (v_ind + 1) % N;
        for(int i=r+1;i!=r;){
            match1[i] = v_ind;
            // we simply pair candiate at B[w[i]] with vacancy at A[z[v_ind]]
            dist1 += dist(B[w[i]], A[z[v_ind]]);
            v_ind = (v_ind + 1) % N;    
            i = (i + 1) % N;
        }
    }

    // lets assume first candidate goes LEFT 
    int64_t dist2 = 0;
    vector<int> match2(N);
    {
        int c = B[w[r]];
        int v_ind = N-1;
        for(int i=N-1;i>=0;i--)
            if(dist_going_left(c, A[z[i]]) < dist_going_left(c, A[z[v_ind]]))
                v_ind = i;
        cout << "0:" << dist_going_left(c, A[z[v_ind]]) << endl;
        match2[r] = v_ind;
        dist2 += dist(B[w[r]], A[z[v_ind]]);
        v_ind = (v_ind + N - 1) % N;
        for(int i=(N+r-1)%N;i!=r;){
            match2[i] = v_ind;
            // we simply pair candiate at B[w[i]] with vacancy at A[z[v_ind]]

            cout << i << ":" << dist(B[w[i]], A[z[v_ind]]) << endl;
            dist2 += dist(B[w[i]], A[z[v_ind]]);
            v_ind = (v_ind + N - 1) % N;
            i = (i + N - 1) % N;
        }
       
    }

    cout << dist1 << endl;
    cout << dist2 << endl;

    vector<int> work(N);
    if(dist1 < dist2){
        for(int i=0;i<N;i++)
            work[z[match1[i]]] = w[i];
    }
    else {
        for(int i=0;i<N;i++)
            work[z[match2[i]]] = w[i];
    }

    cout << min(dist1, dist2) << endl;
    for(int i=0;i<N;i++)
        cout << work[i]+1 << " ";
    cout << endl;
    return 0;
}