#include <bits/stdc++.h>

using namespace std;

vector<int> treeMaxA(4*100000);
vector<int> treeMinA(4*100000);
vector<int> treeMaxB(4*100000);
vector<int> treeMinB(4*100000);
vector<int64_t> treeSize(4*100000);
vector<int> A,B;

void build(int node, int start, int end)
{
    if(start == end){
        treeMaxA[node] = A[start];
        treeMinA[node] = A[start];
        treeMaxB[node] = B[start];
        treeMinB[node] = B[start];
        treeSize[node] = 1;
    }
    else
    {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        treeMaxA[node] = max(treeMaxA[2*node], treeMaxA[2*node+1]);
        treeMinA[node] = min(treeMinA[2*node], treeMinA[2*node+1]);
        treeMaxB[node] = max(treeMaxB[2*node], treeMaxB[2*node+1]);
        treeMinB[node] = min(treeMinB[2*node], treeMinB[2*node+1]);
        treeSize[node] = treeSize[2*node] + treeSize[2*node + 1];
    }
    cout << "[" << start << "," << end << "]=\t"
        << treeMinA[node]<<"-"<<treeMaxA[node] << "\t"
        << treeMinB[node]<<"-"<<treeMaxB[node] << endl;
    
    int x1 = treeMinA[node];
    int x2 = treeMinB[node];
    int y1 = treeMaxA[node];
    int y2 = treeMaxB[node];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    A = vector<int>(N);
    B = vector<int>(N);

    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) cin >> B[i];

    build(0, 0, N-1);

    return 0;
}