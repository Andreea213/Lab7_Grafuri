#include <stdio.h>
#include <stdbool.h>

int adj[10][10], viz[10], n;

bool are_ciclu(int nod, int parinte) {
    viz[nod] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[nod][i]) {
            if (!viz[i]) {
                if (are_ciclu(i, nod)) return true;
            } else if (i != parinte) return true;
        }
    }
    return false;
}

int main() {
    n = 3;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][1] = adj[1][3] = 1; 

    if (are_ciclu(1, -1)) printf("Graful contine cel putin un ciclu.");
    else printf("Graful nu are cicluri.");
    return 0;
}
