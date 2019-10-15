#include <bits/stdc++.h>

using namespace std;

const vector<char> v = {'a','e','i','o','u'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    // factorise into m.n where both >=5
    
    int a=5;
    while(a <= N && N % a != 0) a++;
    int b = N/a;

    if(a>=5 && b>=5 && a*b == N){
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cout << v[(i+j)%5];
            }
            //cout << endl;
        }
        cout << endl;
    }
    else{
        cout << "-1" << endl;
    }

    return 0;
}