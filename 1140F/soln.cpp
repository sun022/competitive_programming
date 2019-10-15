#include <bits/stdc++.h>
#define maxn 300043
using namespace std;

long long cur=0;
int crt=0;
int *id[maxn*80];
int value[maxn*80];
int s1[maxn*2],s2[maxn*2];
int f[maxn*2];

void change(int &a,int b) {
	id[crt]=&a;
	value[crt]=a;
	a=b;
	crt++;
}
void rollback() {
	crt--;
	(*id[crt])=value[crt];
}
int find(int x) {
	if(f[x]==x) return x;
	return find(f[x]);
}
void merge(int a,int b) {
	a=find(a);
	b=find(b);
	if(a==b) return;
	cur-=s1[a]*1ll*s2[a];
	cur-=s1[b]*1ll*s2[b];
	if(s1[a]+s2[a]<s2[b]+s2[b])
		swap(a,b);
	change(f[b],a);
	change(s1[a],s1[a]+s1[b]);
	change(s2[a],s2[a]+s2[b]);
	cur+=s1[a]*1ll*s2[a];
}
void init() {
	for(int i=0; i<300000; i++) {
		f[i]=i;
		f[i+300000]=i+300000;
		s1[i]=1;
		s2[i+300000]=1;
	}
}
vector< pair<int,int> > V[maxn*4];
void add(int v,int l,int r,int L,int R,pair<int,int> val) {
	if(L >= R) return;
	if(L == l && R == r)
		V[v].push_back(val);
	else {
		int m = (l + r) / 2;
		add(v * 2 +1, l, m, L, min(R, m), val);
		add(v * 2 +2, m, r, max(m, L), R, val);
	}
}
long long ans[maxn];
void dfs(int root,int l,int r) {
	long long lastt=cur;
	int state=crt;
	for(auto q:V[root])
		merge(q.first,q.second+300000);
	if(l==r-1) {
		ans[l]=cur;
	} else {
		int mid=(l+r)/2;
		dfs(root*2+1,l,mid);
		dfs(root*2+2,mid,r);
	}
	while(crt!=state) rollback();
	cur=lastt;
}
int main() {
	int n;
	int a,b;
	scanf("%d",&n);
	map<pair<int,int>,int> M;
	for(int i=0; i<n; i++) {
		scanf("%d%d",&a,&b);
		a--,b--;
		pair<int,int> p=make_pair(a,b);
		if(M.count(p)) {
			add(0,0,n,M[p],i,p);
			M.erase(p);
		} else {
			M[p]=i;
		}
	}
	for(auto x:M)
		add(0,0,n,x.second,n,x.first);
	init();
	dfs(0,0,n);
	for(int i=0; i<n; i++) printf("%lld ",ans[i]);

}