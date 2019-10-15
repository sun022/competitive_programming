#include <bits/stdc++.h>

using namespace std;

int p1_lose(){
    cout << "cslnb" << endl;
    return 0;
}
int p1_win(){
    cout << "sjfnb" << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    // check init state for instalose
    bool swit = false;
    int dup = 0;
    int dupIndex;
    for(int i=0;i+1 < N;i++){
        if(A[i] == A[i+1]){
            dup++;
            dupIndex = i;
        }
    }
    if(dup >= 2){
        return p1_lose();
    }
    if(dup == 1){
        int amm = A[dupIndex];
        if(amm == 0) {
            return p1_lose();
        }

        A[dupIndex]--;
        if(dupIndex-1 >= 0 && A[dupIndex] == A[dupIndex-1]) {
            return p1_lose();
        }
        swit = true;
    }

    // now we assume all distinct, ordered, so neither player is forced out until 0,1,2,3,4,5,6,7....

    int64_t diff = (swit ? 1 : 0);
    //cout << diff << endl;
    for(int i=0;i < N;i++){
        diff += A[i] - i;
        // diff %= 2;
    }
    //cout << diff << endl;

    if(diff % 2 == 1){
        return p1_win();
    }
    return p1_lose();
}