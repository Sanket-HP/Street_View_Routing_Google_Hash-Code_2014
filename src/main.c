#include <stdio.h>
#include "graph.h"

Street streets[MAX_EDGES];
Edge adjList[MAX_NODES][MAX_EDGES];
int adjSize[MAX_NODES];
int visited[MAX_NODES];
int dist[MAX_NODES];
int itinerary[MAX_NODES];
int itinerarySize;

int main() {
    int N, M, T, C, S;
    scanf("%d %d %d %d %d", &N, &M, &T, &C, &S);
    for (int i = 0; i < N; i++) {
        double lat, lon;
        scanf("%lf %lf", &lat, &lon);
    }
    for (int i = 0; i < M; i++) {
        int A, B, D, C, L;
        scanf("%d %d %d %d %d", &A, &B, &D, &C, &L);
        adjList[A][adjSize[A]++] = (Edge){B, L, C, D};
        if (D == 2) adjList[B][adjSize[B]++] = (Edge){A, L, C, D};
        streets[i] = (Street){L, C, 0};
    }
    dijkstra(S);

    // Output the number of cars
    printf("%d\n", C);
    schedule_cars(S, C, T);

    return 0;
}
