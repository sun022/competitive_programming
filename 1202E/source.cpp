#include <bits/stdc++.h>

using namespace std;

// https://gist.github.com/gongzhitaao/5e9d8f80aaba60e14a2c
// int kmp(const string &T, const string &P) {
//   if (P.empty()) return 0;

//   vector<int> pi(P.size(), 0);
//   for (int i = 1, k = 0; i < P.size(); ++i) {
//     while (k && P[k] != P[i]) k = pi[k - 1];
//     if (P[k] == P[i]) ++k;
//     pi[i] = k;
//   }

//   for (int i = 0, k = 0; i < T.size(); ++i) {
//     while (k && P[k] != T[i]) k = pi[k - 1];
//     if (P[k] == T[i]) ++k;
//     if (k == P.size()) return i - k + 1;
//   }

//   return -1;
// }

int count3(const string &T, const string &P) {
	// lets find the last(technically penultimate) occurence of every suffix
	vector<int> occ(P.size(), -1);
	int j = T.size()-2;
	for(int i=P.size()-1; i>=0; i--) {
		if(P[i] == T[j]
	}


	int ret = 0;
	int comp = 0;
	for(int i=0;i+P.size()-1<T.size();i++) { // checking if T[i : i+N-1] matches P
		bool match = true;
		for(int j=P.size() - 1;j >= 0;j--){
			comp++;
			if(T[i] != P[j]){
				match = false;
				break;
			}
		}
		if(match) ret++;
	}
	cout << comp << " comparisons" << endl;
	return ret;
}

int count2(const string &T, const string &P) {
	int ret = 0;
	int comp = 0;
	for(int i=0;i+P.size()-1<T.size();i++) { // checking if T[i : i+N-1] matches P
		bool match = true;
		for(int j=P.size() - 1;j >= 0;j--){
			comp++;
			if(T[i+j] != P[j]){
				match = false;
				break;
			}
		}
		if(match) ret++;
	}
	cout << comp << " comparisons" << endl;
	return ret;
}

int count1(const string &T, const string &P) {
	int ret = 0;
	int comp = 0;
	for(int i=0;i+P.size()-1<T.size();i++){
		bool match = true;
		for(int j=0;j<P.size();j++){
			comp++;
			if(T[i+j] != P[j]){
				match = false;
				break;
			}
		}
		if(match) ret++;
	}
	cout << comp << " comparisons" << endl;
	return ret;
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << count1("aaabaaababbaaababaaabbaabaaabaaaabaabb", "aaabaa") << endl;
    cout << count2("aaabaaababbaaababaaabbaabaaabaaaabaabb", "aaabaa") << endl;
    cout << count3("aaabaaababbaaababaaabbaabaaabaaaabaabb", "aaabaa") << endl;

    return 0;
}