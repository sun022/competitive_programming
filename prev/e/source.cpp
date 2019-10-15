#include <bits/stdc++.h>

using namespace std;



struct Node {
    int value; // t
    Node *left;
    Node *right;

    int s=0;

    Node(int val, int s) {
        this->value = val;
        this->s = s;
    }

    // Node(int val, Node left, Node right) {
    //     this->value = val;
    //     this->left = left;
    //     this->right = right;
    // }
};

class BST {

    private:
    Node *root;

    void addHelper(Node *root, int val, int s) {
        if (root->value > val) {
            if (!root->left) {
                root->left = new Node(val, s);
            } else {
                addHelper(root->left, val, s);
            }
        } else {
            if (!root->right) {
                root->right = new Node(val, s);
            } else {
                addHelper(root->right, val, s);
            }
        }
    }

    void printHelper(Node *root) {
        if (!root) return;
        printHelper(root->left);
        cout<<root->value<<'(' << root->s << ") ";
        printHelper(root->right);
    }

    int nodesCountHelper(Node *root) {
        if (!root) return 0;
        else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
    }

    int heightHelper(Node *root) {
        if (!root) return 0;
        else return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

    void printMaxPathHelper(Node *root) {
        if (!root) return;
        cout<<root->value<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    bool deleteValueHelper(Node* parent, Node* current, int value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == NULL || current->right == NULL) {
                Node* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->root = temp;
                }
            } else {
                Node* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                int temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    public:
    void add(int val, int s) {
        if (root) {
            this->addHelper(root, val, s);
        } else {
            root = new Node(val, s);
        }
    }

    void print() {
        printHelper(this->root); 
    }

    int nodesCount() {
        return nodesCountHelper(root);
    }

    int height() {
        return heightHelper(this->root);
    }

    void printMaxPath() {
        printMaxPathHelper(this->root);
    }

    bool deleteValue(int value) {
        return this->deleteValueHelper(NULL, this->root, value);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // int N;
    // cin >> N;
    // vector<int> A(N);
    // for(int i=0;i<N;i++)
    //     cin >> A[i];

    BST *bst = new BST();
    int q;
    cin >> q;

    for(int i=0;i<q;i++) {
        char type;
        cin >> type;
        if(type == '1') {
            int t,s;
            cin >> t >> s;
            cout << endl << "adding " <<t << " " << s << endl;
            bst->add(t, s);
            cout << "done" << endl;
        }
        else if(type == '2') {
            int t;
            cin >> t;
            bst->print();
            cout << endl << "deleting " << t << endl;
            bst->deleteValue(t);
            cout << "done" << endl;
        }
        else if(type == '3') {
            int l,r,v;
            cin >> l >> r >> v;
            // bst->print();
            // cout << endl;
        }
    }
    cout << "mmm" << endl;
    // cout<<"Nodes count: "<<bst->nodesCount() << endl;
    // cout<<"Height: "<<bst->height() << endl;
    bst->print();
    // bst->add(11);
    // bst->add(1);
    // bst->add(6);
    // bst->add(-1);
    // bst->add(-10);
    // bst->add(100);
    // bst->print();
    // cout<<endl;
    // cout<<"Nodes count: "<<bst->nodesCount();
    // cout<<endl;
    // cout<<"Height: "<<bst->height();
    // cout<<endl;
    // cout<<"Max path: ";
    // bst->printMaxPath();
    // cout<<endl;
    // bst->deleteValue(11);
    // cout<<"11 removed: ";
    // bst->print();
    // cout<<endl;
    // cout<<"1 removed: ";
    // bst->deleteValue(1);
    // bst->print();
    // cout<<endl;
    // cout<<"-1 removed: ";
    // bst->deleteValue(-1);
    // bst->print();
    // cout<<endl;
    // cout<<"6 removed: ";
    // bst->deleteValue(6);
    // bst->print();
    // cout<<endl;
    // cout<<"-10 removed: ";
    // bst->deleteValue(-10);
    // bst->print();
    // cout<<endl;
    // cout<<"100 removed: ";
    // bst->deleteValue(100);
    // cout<<endl;
    return 0;

    return 0;
}