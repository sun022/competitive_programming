#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> req(N);
    for(int i=0;i<N;i++)
        req[i] = (A[i]+1)/2;


    int s = 0;
    for(int i=0;i<N;i++)
        if(A[i] > A[s])
            s = i;

    vector<int> ans(N, -1);

    int j = s;
    deque<int> q;
    bool done = false;
    for(int i=s;;){
        // cout << i << endl;
        while(q.size() != 0 && A[i] < req[q.front()]){
            // then we resolve value for q.top()
            //while(j <= q.front()){
            while((j-s+N)%N <= (q.front()-s+N)%N){
                ans[j] = (i>j ? i-j : i+N-j);
                // cout << j << ": " << ans[j] << endl;
                j = (j+1) % N;
            }
            q.pop_front();
        }


        // int r = req[q.front()];
            // either, A[i] meets r and A[i] > A[q.top]     (r changes)
            //         A[i] meets r and A[i] <= A[q.top] 
            // or A[i] doesn't meet r

        while(q.size() != 0 && A[i] >= A[q.back()])
            q.pop_back();

        q.push_back(i);    

        // cout << "queue:\t";
        // for(int i=0;i<q.size();i++)
        //     cout << A[q[i]] << " ";
        // cout << endl;    

        i = (i+1)%N;
        if(i == s) break;
    }

    if(ans[s] != -1){

        // resolve those remaining in the queue
        while(q.size() != 0){
            // then we resolve value for q.top()
            while((j-s+N)%N <= (q.front()-s+N)%N){
                int t = s+ans[s];
                ans[j] = (s>j ? s-j : s+N-j) + ans[s];
                // cout << j << ": " << ans[j] << endl;
                j = (j+1) % N;
                if(j == s) break;
            }
            q.pop_front();
        }


    }

    for(int i=0;i<N;i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}