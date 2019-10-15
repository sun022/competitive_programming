#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        int P,Q;
        cin >> P >> Q;

        int minX=0, maxX = Q, minY = 0, maxY = Q;

        vector<int> X(Q+1, 0);
        vector<int> Y(Q+1, 0);
        for(int i=0;i<P;i++){
            int x,y;
            char d;
            cin >> x >> y >> d;
            if(d == 'E')
                X[x+1]++;
            if(d == 'W')
                X[x]--;
            
            if(d == 'N')
                Y[y+1]++;
            if(d == 'S')
                Y[y]--;
        }

        int ySum=0,xSum=0;
        int yBest = INT_MIN, xBest = INT_MIN;
        int yVal = 0, xVal = 0;
        for(int i=0;i<=Q;i++){
            ySum += Y[i];
            xSum += X[i];
            //cout << i << ":" << sum << endl;
            if(ySum > yBest){
                yBest = ySum;
                yVal = i;
            }
            if(xSum > xBest){
                xBest = xSum;
                xVal = i;
            }
        }
        cout << "Case #" << t << ": " << xVal << " " << yVal << endl;
    }

    return 0;
}