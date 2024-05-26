#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 1000
#define MAX_EDGES 10000

typedef struct {
    int target;
    int length;
    int cost;
    int direction; // 1 for one-way, 2 for two-way
} Edge;

typedef struct {
    int junction;
    int cost;
} Node;

typedef struct {
    int size;
    Node data[MAX_NODES];
} PriorityQueue;

typedef struct {
    int length;
    int cost;
    int visited; // Boolean flag to check if street is already visited
} Street;

extern Street streets[MAX_EDGES];
extern Edge adjList[MAX_NODES][MAX_EDGES];
extern int adjSize[MAX_NODES];
extern int visited[MAX_NODES];
extern int dist[MAX_NODES];
extern int itinerary[MAX_NODES];
extern int itinerarySize;

void init_priority_queue(PriorityQueue *pq);
void push(PriorityQueue *pq, Node node);
Node pop(PriorityQueue *pq);
void dijkstra(int start);
void dfs(int node, int time_left);
void schedule_cars(int start, int num_cars, int total_time);

#endif // GRAPH_H
