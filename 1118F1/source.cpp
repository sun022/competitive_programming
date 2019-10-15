#include <bits/stdc++.h>

using namespace std;
struct Edge;
struct Node {
    int i = -1;
    int k = -1;
    int tmp = 0;
    Node* par;
    vector<Edge*> edges;
    Node(int i,int k):k(k),i(i){}
    Node(int k):k(k){}
};

string p(Node* x){
    return x != nullptr ? to_string(x->i) : "*";
}

struct Edge {
    Node *a,*b;
    int k;
    array<int, 2> tmp;
    Edge(Node *a,Node *b,int k):a(a),b(b),k(k){}
    Edge(){}

    string p(){return p(true);}
    string p(bool x){
        string ai = a != nullptr ? to_string(a->i) : "*";
        string bi = b != nullptr ? to_string(b->i) : "*";
        if(x) return ai + " -> " + bi;
        else return bi + " -> " + ai;
    }
};

vector<Node*> nodes;
vector<Edge*> edges;

void dft_step(stack<tuple<Node*, Edge*>> &s){
    auto& [x,e] = s.top();
    const bool edge_dir = (e->a == x);
    if(++(e->tmp[edge_dir]) == 1) {
        /* ON BEGIN TRAVERSAL OF E (FIXED DIRECTION) */
        // cout << e->p(edge_dir) << endl; 
        Node* y = (edge_dir ? e->b : e->a);
        if(y->tmp++ != 0) return;
        /* ON FIRST ARRIVAL AT Y */
        // cout << y->i << endl;

        y->par = x;

        for(Edge *e1 : y->edges)
            s.push({y,e1});
    } else {
        /* ON END TRAVERSAL OF E (FIXED DIRECTION) */
        // cout << "!" << e->p(edge_dir) << endl;
        s.pop();
    }
}

// DFS through tree, assigning par
void dft(Node* root){
    for(Edge *e : edges) e->tmp = {0,0};
    for(Node *x : nodes) x->tmp = 0;
    auto init_edge = make_unique<Edge>(nullptr, root, 0);

    stack<tuple<Node*, Edge*>> s;
    s.push({nullptr, init_edge.get()});
    while(!s.empty()){
        dft_step(s);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<vector<Node*>> x(K+1);
    for(int i=0;i<N;i++){
        int y;
        cin >> y;
        Node *n = new Node(i, y);
        nodes.push_back(n);
        x[y].push_back(n);
    }

    for(int i=0;i != N-1;i++){
        int a,b;
        cin >> a >> b; a--; b--;
        Edge *e = new Edge(nodes[a], nodes[b], 0);
        edges.push_back(e);
        nodes[a]->edges.push_back(e);
        nodes[b]->edges.push_back(e);
    }

    // for(Edge *e : edges){
    //     cout << e->a->i << " - " << e->b->i << "\t" << e->k << endl;
    // }

    dft(nodes[0]);
    for(Node *x : nodes)
        cout << p(x) << "(" << p(x->par) << ")" << endl;

    // for each colour join them up
    for(int k=1;k<=K;k++) {
        

    }

    // cout << endl;

    // for(Node *x : nodes) {
    //     // cout << x.i << "\t" << x.edges.size() << endl;
    //     cout << x->i << endl;
    //     for(Edge* e : x->edges){
    //         cout << e->a->i << " - " << e->b->i << endl;
    //     }
    //     cout << endl;
    // }

    return 0;
}