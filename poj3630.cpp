1.	#include<stdio.h>  
2.	#include<string.h>  
3.	  
4.	const int maxnode = 10000*10+10;  
5.	  
6.	struct Trie{  
7.	    int ch[maxnode][10];  
8.	    int val[maxnode];  
9.	    int sz;  
10.	  
11.	    void init() { sz = 1; memset(ch[0], 0, sizeof(ch[0])); }  
12.	  
13.	    bool insert(char *s, int v){  
14.	        int len = strlen(s);  
15.	        int u = 0;  
16.	        int id, i;  
17.	        for(i = 0; i < len; i++){  
18.	            id = s[i]-'0';  
19.	  
20.	            if(!ch[u][id]){  
21.	                val[sz] = 0;  
22.	                memset(ch[sz], 0, sizeof(ch[sz]));  
23.	                ch[u][id] = sz++;  
24.	            }  
25.	            u = ch[u][id];  
26.	            if(val[u]) return true;  
27.	            else if(i == (len-1)){  
28.	                for(int j = 0; j <= 9; j++)  
29.	                if(ch[u][j])  
30.	                return true;  
31.	            }//else if(i == (len-1) && !val[u]) return true;  
32.	  
33.	        }  
34.	        val[u] = v;  
35.	        return false;   
36.	    }  
37.	}trie;  
38.	  
39.	int main()  
40.	{  
41.	    int T;  
42.	    scanf("%d", &T);  
43.	    while(T--)  
44.	    {  
45.	        int n;  
46.	        char str[11];  
47.	        bool flag = true;  
48.	        scanf("%d", &n);  
49.	        trie.init();  
50.	        while(n--)  
51.	        {  
52.	            scanf("%s", str);  
53.	            if(trie.insert(str, 1)) { flag = false; break; }  
54.	        }  
55.	        if(n > 1) while(n--) scanf("%s", str);  
56.	  
57.	        if(flag) printf("YES\n");  
58.	        else printf("NO\n");  
59.	    }  
60.	    return 0;  
61.	}  
