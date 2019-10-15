#include <bits/stdc++.h>

using namespace std;

int N;

void incr_helper(vector<int> &hit_arr, int x, int a, int b, int index){
    if(!(a <= index && index <= b)) return;
    hit_arr[x]++;
    if(a != b){
        int m = (a+b)/2;
        incr_helper(hit_arr, 2*x+1, a, m, index);
        incr_helper(hit_arr, 2*x+2, m+1, b, index); 
    }
}
void incr(vector<int> &hit_arr, int index){
    return incr_helper(hit_arr, 0, 0, N-1, index);
}

int sum_helper(vector<int> &hit_arr, int x, int a, int b, int p, int q){
    if(q < a || b < p) return 0;
    if(p <= a && b <= q) return hit_arr[x];
    int m = (a+b)/2;
    return
        sum_helper(hit_arr, 2*x + 1, a, m, p, q)
      + sum_helper(hit_arr, 2*x+2, m+1, b, p, q);
}
int sum(vector<int> &hit_arr, int p, int q){
    return sum_helper(hit_arr, 0, 0, N-1, p, q);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<int> P(N), Q(N);
    for(int i=0;i<N;i++)
        cin >> P[i];
    for(int i=0;i<N;i++)
        cin >> Q[i];

    vector<int> ord_p(N);
    vector<int> hit_p(4*N, 0);
    for(int i=0;i<N;i++){
        int s = P[i] - sum(hit_p, 0, P[i]);
        ord_p[i] = s;
        //cout << s << endl;
        incr(hit_p, P[i]); 
    }

    vector<int> ord_q(N);
    vector<int> hit_q(4*N, 0);
    for(int i=0;i<N;i++){
        int s = Q[i] - sum(hit_q, 0, Q[i]);
        ord_q[i] = s;
        //cout << s << endl;
        incr(hit_q, Q[i]); 
    }

    vector<int> ord_t(N, 0);
    int mod = 2;
    for(int i=N-2; i>=0; i--, mod++){
        ord_t[i] += ord_p[i];
        ord_t[i] += ord_q[i];

        while(ord_t[i] >= mod){
            if(i!=0) ord_t[i-1]++;
            ord_t[i] -= mod;
        }
        cout << ord_t[i] << endl;
    }

    vector<int> hit_t(4*N, 0);
    // print ord_t
    for(int i=0;i<N;i++){
        int s = ord_t[i] + sum(hit_t, 0, ord_t[i]);
        cout << ord_t[i] << "\t" << s << endl;
        //cout << s << " ";
        incr(hit_t, ord_t[i]);
    }
    cout << endl;

    return 0;
}