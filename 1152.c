//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int peso, origem, destino;
} Aresta;

int n, m;
int id[MAX], sz[MAX];
Aresta arestas[MAX];

int comparar(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int encontrar(int p) {
    if (id[p] == p) return p;
    return id[p] = encontrar(id[p]);
}

void unir(int p, int q) {
    p = encontrar(p);
    q = encontrar(q);
    if (p == q) return;
    if (sz[p] > sz[q]) {
        int temp = p;
        p = q;
        q = temp;
    }
    id[p] = q;
    sz[q] += sz[p];
}

int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }

        long long total = 0;
        for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            total += w;
            arestas[i].peso = w;
            arestas[i].origem = a;
            arestas[i].destino = b;
        }

        qsort(arestas, m, sizeof(Aresta), comparar);

        long long custo = 0;
        for (int i = 0; i < m; i++) {
            int a = arestas[i].origem;
            int b = arestas[i].destino;
            int w = arestas[i].peso;
            if (encontrar(a) != encontrar(b)) {
                unir(a, b);
                custo += w;
            }
        }

        printf("%lld\n", total - custo);
    }

    return 0;
}