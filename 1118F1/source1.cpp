#include <bits/stdc++.h>

using namespace std;
struct Node;
struct Edge {
    Node *a,*b;
    int k;
    int tmp=0;
    Edge(Node *a,Node *b,int k):a(a),b(b),k(k){}
    Edge(){}
};

struct Node {
    int i = -1;
    int k = -1;
    vector<Edge*> edges;
    Node(int i,int k):k(k),i(i){}
    Node(int k):k(k){}
};

vector<Node*> nodes;
vector<Edge*> edges;

// bool conflict=false;
// bool f(int k, Node *x) {
//     bool ret = x->k == k;
//     if(x->k != 0 && x->k != k)
//         return 0;
//     for(Edge *e : x->edges) {
//         if(e->tmp != 0)
//             continue;
//         e->tmp = 1;
//         Node* y = (e->a != x ? e->a : e->b);
//         //cout << x->i << " - " << y->i << endl;
//         bool f_y = f(k, y);
//         ret = f_y || ret;
//         e->tmp = 2;

//         if(f_y){
//             if(e->k != 0)
//                 conflict = true;
//             e->k = k;
//         }
//         // cout << y->i << " - " << x->i << endl;
//     }
//     if(ret)
//         x->k = k;
//     cout << x->i << ": " << ret << endl;
//     return ret;
// }

bool g(Node *x)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<vector<Node*>> x(3);
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

    // join all the red points
    // join all the blue points

    // O(K*N) -> bad    
    // for(int k=1;k<=2;k++){
    //     for(Edge *e : edges) e->tmp = 0;
    //     f(k, x[k][0]);
    // }

    for(Edge *e : edges){
        cout << e->a->i << " - " << e->b->i << "\t" << e->k << endl;
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