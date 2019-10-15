#include <bits/stdc++.h>

using namespace std;

// https://cp-algorithms.com/string/suffix-array.html
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}
vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        reverse(A[i].begin(), A[i].end());
    }

    string t;
    for(int i=0;i<N;i++){
        cout << A[i] << endl;        
        vector<int> sa = suffix_array_construction(A[i]);

        int o = 0;
        auto L = sa.begin();
        auto R = sa.end();

        int best = 0;
        while(true){
            char c = t[t.size()-1-o];
            if(t.size() <= o)
                break;

            L = lower_bound(L, R, c, [&A, i, o](int e, char val){return A[i][e-o] < val;});
            R = upper_bound(L, R, c, [&A, i, o](int e, char val){return A[i][e-o] < val;});
            cout << c << endl;
            cout << distance(sa.begin(), L) << " " << distance(sa.begin(), R) << endl;
            if(*L + o == A[i].size())
                best = o; 
            if(L <= R)
                o++;
            else
                break;
        }
        cout << "best:" << best << endl;
        for(int j=o; j<A[i].size(); j++)
            t += A[i][A[i].size()-1-j];
        cout << t << endl;
    }

    return 0;
}