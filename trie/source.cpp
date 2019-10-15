#include <bits/stdc++.h>

using namespace std;

struct node {
    node *child [26];
    node() {
        cout << "NODE()" << endl;
        for(int i=0;i<26;i++)
            child[i] = nullptr;
    }
    ~node(){
        for(int i=0;i<26;i++)
            delete child[i];
    }
};

struct trie {
    node *root = new node;
    void insert(string s) {
        cout << "INSERT " << s << endl;
        node *cur = root;
        for(int i=0;i<s.size();i++){
            int d = s[i]-'a';
            if(cur->child[d] == nullptr){
                cur->child[d] = new node;
            }
            cur = cur->child[d];
        }
    }
};

int main(){
    trie t;
    t.insert("hello");
    t.insert("goodbye");
    t.insert("hell");
    t.insert("heaven");
    t.insert("cleanbandit");

    return 0;
}