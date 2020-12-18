#include "stdio.h"
#include "windows.h"
#include "time.h"
#include "conio.h"
#include "Matrix_graph.h"
#pragma warning (disable : 4996)



int first_false(bool* arr, int size) {
	for (size_t i = 0; i < size; i++){
		if (!arr[i]) { return i;};
	}
	return -1;
}


void DFS(graph* g, int v, bool* visited) {
	printf("%d,", v + 1);
	visited[v] = 1;
	for (size_t i = 0; i < g->size; i++){
		if (g->matrix[v][i] == 1 && visited[i] == 0) {

			DFS(g, i,visited);
		}
	}


}

void component(graph* g) {
	bool* visited = (bool*)calloc(g->size, 1);

	int next_vertex = 0;

	while (next_vertex != -1) {
		DFS(g, next_vertex,visited);
		printf("\n");
		next_vertex = first_false(visited, g->size);
	}

	free(visited);
}

void main()
{
	int ver;
	int size;
	
	printf("\nEnter the probability from 0 to 100: ");
	scanf_s("%d", &ver);
	
	printf("Eneter size of graph:");
	scanf("%d", &size);
	graph* g = init_graph(size);
	srand(time(NULL));
	generate_matrix(g,ver);
	print_graph(g);

	printf("\nComponents:\n");
	component(g);
	
}