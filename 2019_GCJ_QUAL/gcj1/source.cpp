#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H=5;
    int W=4;

    vector<int> map(W);
    for(int i=0;i<W;i++)
        map[i] = (i + 2*(H-1)) % W;

    // FOR strict inequality
    // go through y, come out x = map[y]
    // only prevented from going through x
    // so one of y+1, or y-1 is available, DONE

    // FOR equality (square)
    // 3 things prevented (x, x-1, x+1)
    

    return 0;
}