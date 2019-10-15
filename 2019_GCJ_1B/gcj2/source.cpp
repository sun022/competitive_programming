#include <bits/stdc++.h>

using namespace std;

uint64_t MOD = 9223372036854775808ULL; // 2**63

vector<uint64_t> R = {0, 127, 126, 125, 124, 123, 122};
uint64_t sim(int D){
    vector<uint64_t> r = R;
    for(int d=1;d<=D;d++) {
        for(int x=1;x<=6;x++) {
            if(d % x == 0)
                r[x] = (r[x] + r[x])%MOD;
        }
    }
    int64_t ret=0;
    for(int x=1;x<=6;x++){
        ret = (ret + r[x]) % MOD;
    }
    return ret;
}

int extract(vector<int> x, int start, int end){
    int pow=1;
    int ret=0;
    for(int i=0;i<end-start;i++){
        ret += x[start+i]*pow;
        pow*=2;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, W;
    cin >> T >> W;
    for(int t=1;t<=T;t++){
        vector<int> ret(7);
        vector<int> x(63); // up to x[62] = 2^62
        uint64_t resp;

    ////////////////////////////////////////////////////////////////////////////////////////////////

        cout << "185" << endl;    
        //resp = sim(185);
        cin >> resp;
        for(int i=0;i<63;i++){
            x[i] = (resp&1);
            resp>>=1;
        }

        //ret[1] = extract(x, 185, 185+7);
        //ret[2] = extract(x, 92, 92+7);
        //ret[3] = extract(x, 61, 61+7); // LOST
        ret[4] = extract(x, 46, 46+7);
        ret[5] = extract(x, 37, 37+7);
        ret[6] = extract(x, 30, 30+7);

    /////////////////////////////////////////////////////////////////////////////////////////////////
        
        cout << "56" << endl;    
        //resp = sim(56);
        cin >> resp;
        
        // subtract r4 * 2**14
        // subtract r5 * 2**11
        // subtract r6 * 2**9
        resp -= ret[4] << 14;
        resp -= ret[5] << 11;
        resp -= ret[6] << 9;

        for(int i=0;i<63;i++){
            x[i] = (resp&1);
            resp>>=1;
        }

        ret[1] = extract(x, 56, 63);
        ret[2] = extract(x, 28, 35);
        ret[3] = extract(x, 18, 25); // tainted by R4 BUT WE KNOW R4
        // ret[4] = extract(x, 14, 21);
        // ret[5] = extract(x, 11, 18);
        // ret[6] = extract(x, 9, 16);
    //////////////////////////////////////////////////////////////////////////////////
        for(int i=1;i<=6;i++){
            cout << ret[i] << " ";
        }
        cout << endl;

        int correct;
        cin >> correct;
        if(correct == -1) break;
    }

    return 0;
}