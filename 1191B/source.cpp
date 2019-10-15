#include <bits/stdc++.h>

using namespace std;

bool good_pair(string a, string b, int tol){
    if(a[1] != b[1]) return false;
    int A = a[0];
    int B = b[0];
    return abs(A-B) <= tol;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    if(s1 == s2 && s2 == s3){
        cout << "0" << endl; return 0;
    }
    // run:
    int y = good_pair(s1,s2,1) + good_pair(s1,s3,1) + good_pair(s2,s3,1);
    if(y == 2 && s1 != s2 && s1 != s3 && s2 != s3){
        cout << "0" << endl; return 0;
    }


    // 1 iff two identical, or two adj, same suit
    if(good_pair(s1,s2, 2) || good_pair(s1,s3, 2) ||good_pair(s2,s3, 2)){
        cout << "1" << endl; return 0;
    }

    

    cout << "2" << endl;
    return 0;
}