#include <stdio.h>

int adj[10][10], n;
int valori[10] = {0, 50, 10, 30, 80, 20}; 

int distanta_bfs(int start, int stop) {
    if (start == stop) return 0;
    int dist[10], coada[10], p = 0, u = 0;
    for (int i = 1; i <= n; i++) dist[i] = -1;

    coada[u++] = start;
    dist[start] = 0;

    while (p < u) {
        int nod = coada[p++];
        for (int i = 1; i <= n; i++) {
            if (adj[nod][i] && dist[i] == -1) {
                dist[i] = dist[nod] + 1;
                if (i == stop) return dist[i];
                coada[u++] = i;
            }
        }
    }
    return -1;
}

int main() {
    n = 5;
    
    adj[2][1] = adj[1][2] = 1; adj[1][3] = adj[3][1] = 1;
    adj[3][5] = adj[5][3] = 1; adj[5][4] = adj[4][5] = 1;

    int min_idx = 1, max_idx = 1;
    for (int i = 2; i <= n; i++) {
        if (valori[i] < valori[min_idx]) min_idx = i;
        if (valori[i] > valori[max_idx]) max_idx = i;
    }

    printf("Nod minim: %d (val %d), Nod maxim: %d (val %d)\n", min_idx, valori[min_idx], max_idx, valori[max_idx]);
    printf("Distanta: %d", distanta_bfs(min_idx, max_idx));
    return 0;
}
