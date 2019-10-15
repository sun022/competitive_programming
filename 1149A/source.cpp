#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int num_one=0;
    int num_two=0;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x == 1) num_one++;
        if(x == 2) num_two++;
    }

    if(num_one >= 1 && num_two >= 1){
        // do 2 1 {all 2} {all 1}
        cout << "2 1 ";
        num_one--;
        num_two--;
    }
    while(--num_two >= 0)
        cout << "2 ";
    while(--num_one >= 0)
        cout << "1 ";
    cout << endl;

    return 0;
}