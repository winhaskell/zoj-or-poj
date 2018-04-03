#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
int n,ml,cnt[15000];
 
struct star
{
	int x,y;
	bool operator <(const star &p) const
	{
		if(y<p.y) return 1;
		if(y>p.y) return 0;
		if(x<p.x) return 1;
		return 0;
	}
}s[15000];
 
struct node
{
	bool b;
	int d;
	node *l,*r;
}mem[64000],*root;
 
inline void ins(int i)
{
	int L=0,R=32000,m,lev=0;
	node *p=root;
	while(1)
	{
		m=L+R>>1;
		p->d++;
		if(L==R)
		{
			lev+=p->d-1;
			cnt[lev]++;
			break;
		}
		if(p->b)
		{
			p->b=0;
			p->l=&mem[ml++];
			p->l->b=1;
			p->l->d=0;
			p->r=&mem[ml++];
			p->r->b=1;
			p->r->d=0;
		}
		if(i<=m)
		{
			R=m;
			p=p->l;
		}
		else
		{
			lev+=p->l->d;
			L=m+1;
			p=p->r;
		}
	}
}
 
int main()
{
	int i,j,k;
	while(~scanf("%d",&n))
	{
		ml=0;
		root=&mem[ml++];
		root->b=1;
		root->d=0;
		memset(cnt,0,sizeof cnt);
		for(i=0;i<n;i++) scanf("%d%d",&s[i].x,&s[i].y);
		sort(s,s+n);
		for(i=0;i<n;i++) ins(s[i].x);
		for(i=0;i<n;i++) printf("%d\n",cnt[i]);
	}
	return 0;
}
