#include <stdio.h>
#include <stdbool.h>

int adj[10][10], viz[10], n;

bool exista_drum(int start, int stop) {
    if (start == stop) return true;
    viz[start] = 1;
    for (int i = 1; i <= n; i++)
        if (adj[start][i] && !viz[i])
            if (exista_drum(i, stop)) return true;
    return false;
}

int main() {
    n = 4;
    adj[1][2] = 1; adj[2][3] = 1; adj[3][4] = 1; 
    
    int s = 1, d = 4;
    if (exista_drum(s, d)) printf("Exista drum intre %d si %d", s, d);
    else printf("Nu exista drum.");
    return 0;
}
