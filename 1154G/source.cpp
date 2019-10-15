#include <bits/stdc++.h>

using namespace std;

class Prime {
    public:
    vector<bool> primeBool;
    vector<int> primeList;
    int N;
    Prime(const int N): N(N) {
        primeBool = vector<bool>(N+1, true);
        primeBool[0] = primeBool[1] = false;
        for(int n=2;n<=N;n++){
            if(!primeBool[n]) continue;
            for(int k=2*n; k<=N; k+=n)
                primeBool[k] = false;
            primeList.push_back(n);
        }
    }
    bool isPrime(const int x) const {
        if(x<=N) return primeBool[x];
        int i=0;
        while(true) {
            if(primeList[i]*primeList[i] > x) return true;
            if(x % primeList[i] == 0) return false;
            i++;
        }
    }
    int operator[](const int i) const {
        return primeList[i];
    }

    vector<pair<int,int>> primeFactors(int x) const {
        vector<pair<int,int>> fac;
        int i = 0;
        while(x!=1){
            if(primeList[i]*primeList[i] > x){
                fac.push_back({x,1});
                break;
            }
            if(x % primeList[i] == 0){
                int pow = 0;
                do {
                    x /= primeList[i];
                    pow++;
                } while(x % primeList[i] == 0);
                fac.push_back({primeList[i],pow});
            }
            i++;
        }
        return fac;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++)
        cin >> A[i];

    // sort(A.begin(), A.end());
    Prime p(pow(10,4));

    vector<int> m1(pow(10,7)+1, -1);
    vector<int> m2(pow(10,7)+1, -1);
    set<int> seen;
    int64_t min_dup = LLONG_MAX;
    for (int i=0;i<N;i++) {
        if(seen.count(A[i])){
            min_dup = min(min_dup, (int64_t)A[i]);
            continue;
        }
        seen.insert(A[i]);
        // factorize every number
        vector<pair<int,int>> fac = p.primeFactors(A[i]);
        // cout << A[i] << ":\t";
        // for(auto [f,p] : fac)
        //     cout << f << (p==1?"" : "^" + to_string(p)) << " ";
        // cout << endl;

        vector<int> x(fac.size(), 0);
        while(true) {
            int y=1;
            for(int j=0;j<fac.size();j++)
                for(int k=0;k<x[j];k++)
                    y *= fac[j].first;
            // cout << y << " ";
            int ph=i;
            if(m1[y] == -1 || A[ph] < A[m1[y]])
                swap(ph, m1[y]);
            if(m2[y] == -1 || A[ph] < A[m2[y]])
                swap(ph, m2[y]);

            int a = fac.size()-1;
            while(a!=-1 && x[a] == fac[a].second)
                a--;
            if(a==-1) break;
            x[a]++;
            while(++a < fac.size()) x[a] = 0;
        }
    }

    int64_t bestVal = LLONG_MAX;
    pair<int,int> bestIndex;
    for(int i=1;i<m1.size();i++){
        if(m2[i] != -1){
            // cout << (int64_t)m1[i]*m2[i]/i << endl;
            int64_t val = (int64_t)A[m1[i]]*A[m2[i]]/i;
            if(val < bestVal){
                bestVal = val;
                bestIndex = {m1[i], m2[i]};
            }
        }
    }

    if(min_dup < bestVal){
        int found=0;
        for(int i=0;found!=2;i++)
            if(A[i] == min_dup){
                cout << i+1 << " ";
                found++;
            }
        cout << endl;
        return 0;
    }

    if(bestIndex.first > bestIndex.second) swap(bestIndex.first, bestIndex.second);
    cout << bestIndex.first+1 << " " << bestIndex.second+1 << endl;

    return 0;
}