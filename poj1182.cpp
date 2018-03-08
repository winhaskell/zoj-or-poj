#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
const int N=50002;  
int k,n;  
int parent[N*3];  
void init(int n)  
{  
    for(int i=1;i<=n;i++)  
        parent[i]=i;  
}  
int find(int x)  
{  
    return parent[x]==x?x:find(parent[x]);  
}  
void unite(int x,int y)  
{  
    x=find(x);  
    y=find(y);  
    if(x==y)  
        return;  
    parent[x]=y;  
}  
bool same(int x,int y)  
{  
    return find(x)==find(y);  
}  
int main()  
{  
    scanf("%d%d",&n,&k);  
    init(n*3);  
    int d,x,y;  
    int lie=0;  
    for(int i=1;i<=k;i++)  
    {  
        scanf("%d%d%d",&d,&x,&y);  
        if(x>n||y>n||x<1||y<1||(d==2&&x==y))//不合法的输入  
        {  
            lie++;  
            continue;  
        }  
        int t=d;  
        if(t==1)  
        {  
            if(same(x,y+n)||same(x,y+2*n))//不在一个种类里面  
                lie++;  
            else  
            {  
                unite(x,y);//合并为同一种类，3种  
                unite(x+n,y+n);  
                unite(x+2*n,y+2*n);  
            }  
        }  
        else  
        {  
            if(same(x,y)||same(x,y+2*n))//如果x和y同一种类或y吃x  
                lie++;  
            else  
            {  
                unite(x,y+n);//三种情况为x吃y  
                unite(x+n,y+2*n);  
                unite(x+2*n,y);  
            }  
        }  
    }  
    cout<<lie<<endl;  
    return 0;  
}  
