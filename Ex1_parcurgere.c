#include <stdio.h>

int adj[6][6] = {0};
int vizitat[6] = {0};
int n = 5;

void adauga_muchie(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int nod) {
    printf("%d ", nod);
    vizitat[nod] = 1;
    for (int i = 1; i <= n; i++)
        if (adj[nod][i] && !vizitat[i]) DFS(i);
}

void BFS(int start) {
    int coada[6], prim = 0, ultim = 0;
    int viz[6] = {0};
    coada[ultim++] = start;
    viz[start] = 1;
    while (prim < ultim) {
        int nod = coada[prim++];
        printf("%d ", nod);
        for (int i = 1; i <= n; i++) {
            if (adj[nod][i] && !viz[i]) {
                viz[i] = 1;
                coada[ultim++] = i;
            }
        }
    }
}

int main() {
    adauga_muchie(1, 2); adauga_muchie(1, 3);
    adauga_muchie(2, 4); adauga_muchie(2, 5);

    printf("Matrice de adiacenta:\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("\nBFS de la nodul 1: "); BFS(1);
    printf("\nDFS de la nodul 1: "); DFS(1);
    return 0;
}
