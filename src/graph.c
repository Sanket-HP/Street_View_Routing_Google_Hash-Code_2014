#include <limits.h>
#include "graph.h"

void init_priority_queue(PriorityQueue *pq) {
    pq->size = 0;
}

void push(PriorityQueue *pq, Node node) {
    int i = pq->size++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (pq->data[p].cost <= node.cost) break;
        pq->data[i] = pq->data[p];
        i = p;
    }
    pq->data[i] = node;
}

Node pop(PriorityQueue *pq) {
    Node result = pq->data[0];
    Node temp = pq->data[--pq->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left >= pq->size) break;
        int min = (right < pq->size && pq->data[right].cost < pq->data[left].cost) ? right : left;
        if (pq->data[min].cost >= temp.cost) break;
        pq->data[i] = pq->data[min];
        i = min;
    }
    pq->data[i] = temp;
    return result;
}

void dijkstra(int start) {
    PriorityQueue pq;
    init_priority_queue(&pq);
    for (int i = 0; i < MAX_NODES; i++) dist[i] = INT_MAX;
    dist[start] = 0;
    push(&pq, (Node){start, 0});
    while (pq.size > 0) {
        Node u = pop(&pq);
        if (visited[u.junction]) continue;
        visited[u.junction] = 1;
        for (int i = 0; i < adjSize[u.junction]; i++) {
            Edge edge = adjList[u.junction][i];
            int v = edge.target;
            int cost = edge.cost;
            if (dist[u.junction] + cost < dist[v]) {
                dist[v] = dist[u.junction] + cost;
                push(&pq, (Node){v, dist[v]});
            }
        }
    }
}

void dfs(int node, int time_left) {
    if (time_left <= 0) return;
    for (int i = 0; i < adjSize[node]; i++) {
        Edge edge = adjList[node][i];
        if (!streets[i].visited && time_left >= edge.cost) {
            streets[i].visited = 1;
            itinerary[itinerarySize++] = edge.target;
            dfs(edge.target, time_left - edge.cost);
        }
    }
}

void schedule_cars(int start, int num_cars, int total_time) {
    for (int i = 0; i < num_cars; i++) {
        itinerarySize = 0;
        itinerary[itinerarySize++] = start;
        dfs(start, total_time);
        printf("%d\n", itinerarySize);
        for (int j = 0; j < itinerarySize; j++) {
            printf("%d\n", itinerary[j]);
        }
    }
}
