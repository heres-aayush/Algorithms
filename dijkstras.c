#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 5        // Number of vertices
#define INF 9999   // Representation of infinity

/* --------------------- Data Structures --------------------- */

// Node in the priority queue (min-heap)
typedef struct {
    int vertex;  // Vertex number
    int dist;    // Current best distance from the source
} PQNode;

// Structure for the min-heap (priority q=ueue)
typedef struct {
    int size;           // Current number of elements in heap
    int capacity;       // Maximum capacity of the heap
    int *pos;           // pos[v] gives the current index of vertex v in the heap
    PQNode *array;      // Array of heap nodes
} MinHeap;

/* --------------------- Min-Heap Helper Functions --------------------- */

// Create a new min-heap with given capacity
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (PQNode*)malloc(capacity * sizeof(PQNode));
    return minHeap;
}

// Swap two nodes of the min-heap
void swapPQNode(PQNode *a, PQNode *b) {
    PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify at a given index (maintains the min-heap property)
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size && minHeap->array[left].dist < minHeap->array[smallest].dist)
        smallest = left;
    
    if (right < minHeap->size && minHeap->array[right].dist < minHeap->array[smallest].dist)
        smallest = right;
    
    if (smallest != idx) {
        // Update positions
        minHeap->pos[minHeap->array[smallest].vertex] = idx;
        minHeap->pos[minHeap->array[idx].vertex] = smallest;
        // Swap nodes
        swapPQNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the min-heap is empty
bool isEmpty(MinHeap* minHeap) {
    return (minHeap->size == 0);
}

/* --------------------- Extract-Min Function --------------------- */

// Extracts and returns the node with the minimum distance
PQNode ExtractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap)) {
        PQNode empty = {-1, INT_MAX};
        return empty;
    }
    
    // Store the root node
    PQNode root = minHeap->array[0];
    
    // Replace root with last node
    PQNode lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    
    // Update position of last node
    minHeap->pos[lastNode.vertex] = 0;
    minHeap->pos[root.vertex] = minHeap->size - 1;
    
    // Reduce heap size and heapify root
    minHeap->size--;
    minHeapify(minHeap, 0);
    
    return root;
}

/* --------------------- Decrease-Key Function --------------------- */

// Decreases the distance value of vertex 'v' in the min-heap to 'dist'
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    // Get the index of v in the heap array
    int i = minHeap->pos[v];
    
    // Update the distance value
    minHeap->array[i].dist = dist;
    
    // Bubble up while the heap property is violated
    while (i > 0 && minHeap->array[i].dist < minHeap->array[(i - 1) / 2].dist) {
        // Update positions of current node and its parent
        minHeap->pos[minHeap->array[i].vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2].vertex] = i;
        // Swap with parent
        swapPQNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/* --------------------- Dijkstra's Algorithm Helper Functions --------------------- */

// Initialize distances and min-heap for all vertices
void InitializeSingleSource(int dist[], MinHeap *minHeap, int src) {
    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        minHeap->array[v].vertex = v;
        minHeap->array[v].dist = INF;
        minHeap->pos[v] = v;
    }
    // Set the source vertex distance to 0
    dist[src] = 0;
    minHeap->array[src].dist = 0;
    
    // All vertices are initially in the heap
    minHeap->size = V;
}

// Relaxation function: update distance of vertex v from source if a shorter path is found via u
void Relax(int graph[V][V], int u, int v, int dist[], MinHeap* minHeap) {
    // If there is an edge from u to v, and the path through u offers a shorter path
    if (graph[u][v] != INF && graph[u][v] != 0 && dist[u] != INF &&
        dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
        decreaseKey(minHeap, v, dist[v]);
    }
}

/* --------------------- Dijkstra's Algorithm --------------------- */

void dijkstra(int graph[V][V], int src) {
    int dist[V];  // dist[] will hold the shortest distances from src
    
    // Create a min-heap for vertices
    MinHeap* minHeap = createMinHeap(V);
    
    // Initialize distances and min-heap
    InitializeSingleSource(dist, minHeap, src);
    
    // Process vertices until the min-heap is empty
    while (!isEmpty(minHeap)) {
        // Extract the vertex with the minimum distance value
        PQNode minNode = ExtractMin(minHeap);
        int u = minNode.vertex;
        
        // For every vertex v, try to relax the edge from u to v
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && graph[u][v] != 0)
                Relax(graph, u, v, dist, minHeap);
        }
    }
    
    // Print the final shortest distances
    printf("Vertex\tDistance from Source (vertex %d)\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t INF\n", i);
        else
            printf("%d \t %d\n", i, dist[i]);
    }
    
    // Free the min-heap memory
    free(minHeap->array);
    free(minHeap->pos);
    free(minHeap);
}

/* --------------------- Main Function --------------------- */

int main() {
    // Graph represented as a length matrix (∞ is represented by INF = 9999)
    int graph[V][V] = {
        {0,   10,  INF, 5,   INF},
        {INF, 0,   1,   2,   INF},
        {INF, INF, 0,   INF, 4},
        {INF, 3,   9,   0,   2},
        {7,   INF, 6,   INF, 0}
    };
    
    // Run Dijkstra's algorithm from source vertex 0 (representing 's')
    dijkstra(graph, 0);
    
    return 0;
}
