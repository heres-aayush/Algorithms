#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 5 //number of vertices
#define INF INT_MAX

typedef struct Node
{
	int vertex ;
	int weight; 
	struct Node* next ; 
}Node;

//adjacency list
typedef struct 
{
	Node* head; 
} adjList ;


typedef struct minHeapNode
{
	int vertex ; 
	int dist ; // distance from the source 
}heapNode;

typedef struct minHeap
{
	int size; 
	int capacity; //check if required
	int *pos;
	heapNode** array ; 
} minHeap ;

Node * createNewNode(int vertex , int weight)
{
	Node* temp  = (Node*) malloc ( sizeof(Node));
	temp->vertex = vertex ; 
	temp -> weight = weight;
	temp -> next = NULL;
	
	return temp ;
}	

adjList* createNewList()
{
		adjList* lists = (adjList *) malloc (V * sizeof(adjList));
		for(int i  =0  ; i < V ; i++)
		{
			
			lists[i].head = NULL ; 
		}
		return lists ; 
}

void addEdge (adjList* list , int source , int weight , int dest)
{
	Node * desti = createNewNode(dest , weight);

	if (list[source].head == NULL) {
		list[source].head = desti;
		return;
	}

	Node* temp = list[source].head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = desti;
}

void display(adjList * lists)
{
	for(int i = 0 ; i < V ; i++)
	{
		printf("%d " , i) ;
		Node* temp  = lists[i].head ; 
		while(temp != NULL)
		{
			printf (" --> %d ( %d )" , temp->vertex , temp->weight);
			temp = temp->next ;
		}
		printf("--> NULL\n");
	}
}		

minHeap* createMinHeap(int capacity)
{
	minHeap* temp =  (minHeap* )malloc (sizeof(minHeap));
	temp ->size = 0  ;
	temp -> capacity = capacity ; 
	temp -> pos = ( int * ) malloc ( V * sizeof(int)) ;
	temp->array = (heapNode**) malloc (capacity * sizeof(heapNode*));
	return temp;
}

heapNode* newMinHeapNode(int vertex , int distance)
{
	heapNode * temp = (heapNode*) malloc(sizeof(heapNode));
	temp->vertex = vertex;
	temp->dist = distance;
	return temp ; 
}

void swapNode (heapNode ** n1 , heapNode** n2 )
{
	heapNode* temp = *n1 ;
	*n1 = *n2 ; 
	*n2 = temp ;
}

void relax(minHeap * heap , int vertex , int dist)
{
	int i = heap->pos[vertex] ; 
	heap->array[i] -> dist = dist  ;
	while( i && heap->array[i]->dist < heap->array[(i-1)/2] -> dist)
	{
		heap->pos[heap->array[i]->vertex] = (i-1)/2; 
		heap->pos[heap->array[(i-1)/2]->vertex] = i ; 
		swapNode(&(heap->array[i]), &(heap->array[(i-1)/2])) ; 
		i = (i-1)/2; 
	}
}

void minHeapify(minHeap* heap , int idx)
{
	int smallest  = idx ; 
	int left= 2*idx + 1;
	int right = 2*idx +2 ; 
	if(left < heap->size && heap->array[left] -> dist < heap->array[smallest]->dist )
			smallest = left ;
	if(right < heap->size && heap-> array[right]->dist < heap->array[smallest]->dist)
			smallest =  right ; 
	if(smallest!=idx)
	{
		heapNode* smallestNode = heap->array[smallest]; 
		heapNode* idxNode= heap->array[idx]; 
		heap->pos[smallestNode->vertex] = idx ;
		heap->pos[idxNode->vertex] = smallest ; 
		swapNode(&heap->array[smallest] , &heap->array[idx]);
		minHeapify(heap , smallest ); 
	}
}		

heapNode* extractMin ( minHeap* heap)
{
	if(heap->size ==0 )
		return NULL;
	heapNode* root = heap->array[0] ; 
	heapNode * lastNode = heap->array[heap->size -1] ; 
	heap->pos[root->vertex] = heap->size-1;
	heap->array[0] = lastNode;
	heap->pos[lastNode->vertex]=0 ; 
	heap->size--; 
	minHeapify(heap,0) ;
	return root ; 
}
	
void printPath(int parent[] , int i )
{
	if(parent[i]==-1)
	{
		printf("%d", i) ; 
		return ;
	}
	printPath(parent, parent[i]); 
	printf("-> %d" , i);
}

int isInMinHeap(minHeap *minHeap, int v) {
    if (minHeap->pos[v] < minHeap->size)
        return 1;
    return 0;
}


void dijkstras(adjList * list, int source)
{
	//initialize_single_source
	int parent[V];
	int dist[V] ; //distance
	int total = 0 ;
	//sab vertices ke liye alag alag heap banega
	minHeap* heap = createMinHeap(V);
	for(int i = 0 ; i < V ; i++)
	{
		parent[i] = -1; 
		dist[i] = INF ;
		heap->pos[i] = i ; // har vertices ka heap position 
		heap->array[i] = newMinHeapNode(i, dist[i]);
	}
	//creating of heap form source 
	heap->pos[source] = source ; //nt
	heap->array[source]->dist= 0 ; 
	heap -> size  = V ;
	dist[source]= 0 ; 

	while(heap->size!=0)
	{
		heapNode* min  = extractMin(heap);
		int u = min->vertex ; 
		Node* temp = list[u].head ; 
		while(temp!= NULL) 
		{
			int v = temp->vertex; 
			//comment 207-211 if prims
			/*
			if(temp->weight + dist[u] < dist[v] )
			{
				dist[v] = temp->weight+dist[u];
				parent[v] = u ; 
				relax(heap, v, dist[v]) ; // to adapt to the new change
			}
 			*/
			
			//uncomment if prims
			if(isInMinHeap(heap ,v ) && temp->weight < dist[v] )
			{
				dist[v] = temp->weight ; 
				parent[v] = u ; 
				total+= temp->weight;
				relax(heap, v, dist[v]);
			}
			
			temp= temp->next ;
		}
	}
	//printing prims
								printf("Edge \tWeight\n");
							int totalWeight = 0;
							for (int i = 0; i < V; ++i) {
								if (parent[i] != -1) {
									printf("%d - %d\t%d\n", parent[i], i, dist[i]);
									totalWeight += dist[i];
								}
							}
							printf("Total MST Weight: %d\n", totalWeight); 
							printf("Tot is:  %d" , total) ;
							
	//printing dijkstras
					/*	printf("Vertex\tDistance\tPath\n");
						for(int i = 0 ; i < V ; i++)
						{
							printf("%d\t%d\t\t" , i, dist[i] );
							printPath(parent, i);  // sending the parent array 
							printf("\n");
						}*/
}

int main()
{
	adjList* lists = createNewList();
	addEdge (lists, 0 , 10 , 1);
	addEdge (lists, 0 , 5 , 3);
	addEdge (lists, 1 , 1 , 2);
	addEdge (lists, 1 , 2 , 3);
	addEdge (lists, 2, 4 , 4);
	addEdge (lists, 3 , 3 , 1);
	addEdge (lists, 3, 9 , 2);
	addEdge (lists, 3 , 2 , 4);
	addEdge (lists, 4 , 7 , 0);
	addEdge (lists, 4 , 6 , 2);
	display(lists);
	dijkstras(lists, 0) ; 
	return 0;
}