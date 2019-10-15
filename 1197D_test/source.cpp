//author Forsaken
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.in", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.out", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 4e5;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
il int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll quick_pow(ll base, ll index, ll p) {
	ll res = 1;
	while (index) {
		if (index & 1)res = res * base % p;
		base = base * base % p;
		index >>= 1;
	}
	return res;
}
int a[maxn + 5];
struct Node {
	ll tag, M;
	Node *lc, *rc;
	Node() { tag = 0; M = -1ll << 60; lc = rc = NULL; }
	void push_down() {
		if (tag) {
			lc->M += tag; lc->tag += tag;
			rc->M += tag; rc->tag += tag;
			tag = 0;
		}
	}
	void push_up() { M = max(lc->M, rc->M); }
}*rt[10];
 
void build(Node* &p, int l, int r) {
	p = new Node(); if (l == r) return;
	int mid = l + r >> 1;
	build(p->lc, l, mid); build(p->rc, mid + 1, r);
}
 
void updata(Node* p, int l, int r, int L, int R, ll  val)
{
	if (L>R) return;
	if (L <= l&&r <= R) { p->M += val; p->tag += val; return; }
	p->push_down();
	int mid = l + r >> 1;
	if (L <= mid) updata(p->lc, l, mid, L, R, val);
	if (mid<R) updata(p->rc, mid + 1, r, L, R, val);
	p->push_up();
}
 
void updata2(Node* p, int l, int r, int pos, ll val)
{
	if (l == r) { p->M = p->tag = val; return; }
	p->push_down();
	int mid = l + r >> 1;
	if (pos <= mid) updata2(p->lc, l, mid, pos, val);
	else updata2(p->rc, mid + 1, r, pos, val);
	p->push_up();
}
 
ll dp[maxn], sum[maxn];
int k;
 
int n, m;
int id(int x)
{
	return (x) / m + 1;
}
 
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)a[i] = read_int(), sum[i] = sum[i - 1] + a[i];
 
	int N = n / m + 2;
	for(int i = 0; i < m; ++i)build(rt[i], 1, N);
 
	updata2(rt[0], 1, N, 1, -k);
 
	ll ans = 0;
	dp[0] = 0;
	for(int i = 1; i <= n; ++i)dp[i] = -1ll << 60;
	for (int i = 1; i <= n; ++i){
		ll M = -1ll << 60;
		for(int j = 0; j < m; ++j) M = max(M, rt[j]->M);
		dp[i] = max(dp[i - 1], M + sum[i]);
		ans = max(ans, dp[i]);
		updata(rt[i%m], 1, N, 1, id(i) - 1, -k);
		updata2(rt[i%m], 1, N, id(i), -sum[i] - k);
	}
	outld(ans);
	return 0;
}