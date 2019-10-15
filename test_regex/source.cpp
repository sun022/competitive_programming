#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string item = "DISH-STRAWBERRY";

    if(regex_match(item, regex("DISH-.*")) && item != "DISH"){
        cout << "!!" << endl;
    }

    return 0;
}