#include <cstdio>
using namespace std;
#define INF 99999999

int Dis[101][101];

int main()
{
    int N;
    while (scanf("%d", &N) && N) {
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j)
                Dis[i][j] = INF;
            Dis[i][i] = 0;
        }
 
        for (int i = 1; i <= N; ++i) {
            int t, x, w;
            scanf("%d", &t);
            for (int j = 0; j < t; ++j) {
                scanf("%d %d", &x, &w);
                Dis[i][x] = w;
            }
        }
 
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    if (Dis[i][k] + Dis[k][j] < Dis[i][j])
                        Dis[i][j] = Dis[i][k] + Dis[k][j];

        
        int Min = INF;
        int Min_pos;
        bool Disjoint = true;
        for (int i = 1; i <= N; ++i) {
            int Max_length = 0;   
            bool Reachable = true;
            for (int j = 1; j <= N; ++j) {
                if (Dis[i][j] == INF) {
                    Reachable = false;
                    break;
                }
                else if (Dis[i][j] > Max_length)
                    Max_length = Dis[i][j];
            }
            if (Reachable == true) {
                Disjoint = false;
                if (Max_length < Min) {
                    Min = Max_length;
                    Min_pos = i;
                }
            }
        }
         
        if (Disjoint) puts("disjoint");
        else printf("%d %d\n", Min_pos, Min);
    }
}
