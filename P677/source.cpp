#include <bits/stdc++.h>

using namespace std;

int main(){
    map<tuple<int,int,int>, int> m;

    m[{2,0,0}] = 1;

    for(int N=3;N<=100;N++){
        cout << "N:" << N << endl;
        map<tuple<int,int,int>, int> m_next;
        for(auto [k,v] : m){
            auto [a,b,c] = k;

            if(a>0) m_next[{a,b+1,c}] += a*v;
            if(b>0) m_next[{a+1,b-1,c+1}] += b*v;
            if(c>0) m_next[{a+1,b,c-1}] += c*v;        
        }
        m = m_next;
        //for(auto [k,v] : m){
        //    auto [a,b,c] = k;
        //    cout << "[" << a << "," << b << "," << c << "]\t" << v << endl;
        //}
        cout << m.size() << endl;

    }

    for(auto [k,v] : m){
           auto [a,b,c] = k;
           cout << "[" << a << "," << b << "," << c << "]\t" << v << endl;
        }

    return 0;
}