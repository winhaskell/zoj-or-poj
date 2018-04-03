#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cctype>
#define LL long long
#define INF 0x7fffffff
using namespace std;

int n;
int a[10005], ans[10005];

struct node {
	int l, r;
	int v;
};

node s[30005];

void build(int l, int r, int rt) {	//build tree 建树 
	s[rt].l = l;
	s[rt].r = r;
	s[rt].v = r - l + 1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}

int query(int rt, int k) {	// query and delete 查询并且删除 
	s[rt].v --;
	if(s[rt].l == s[rt].r) return s[rt].l;
	else if(k <= s[rt << 1].v) {
		query(rt << 1, k);
	}
	else {
		query(rt << 1 | 1, k - s[rt << 1].v);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	a[1] = 0;
	build(1, n, 1);
	for(int i = n; i >= 1; i --) {	 
		ans[i] = query(1, a[i] + 1);
	}
	for(int i = 1; i <= n; i ++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}


