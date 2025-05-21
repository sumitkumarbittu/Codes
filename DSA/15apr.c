/*

#include <stdio.h>
#include <stdbool.h>
 
#define MAX 100
 
int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
 
bool dfs(int v, int n) {
   visited[v] = true;
   recStack[v] = true;
 
   for (int i = 0; i < n; i++) {
       if (graph[v][i]) {
           if (!visited[i]) {
               if (dfs(i, n)) return true;
           } else if (recStack[i]) {
               return true;
           }
       }
   }
 
   recStack[v] = false;
   return false;
}
 
bool isCyclic(int n) {
   for (int i = 0; i < n; i++) {
       visited[i] = false;
       recStack[i] = false;
   }
 
   for (int i = 0; i < n; i++) {
       if (!visited[i]) {
           if (dfs(i, n)) return true;
       }
   }
   return false;
}
 
int main() {
   int n;
   scanf("%d", &n); // number of vertices
 
   // Read adjacency matrix
   for (int i = 0; i < n; i++) {
       char row[MAX];
       scanf("%s", row);
       for (int j = 0; j < n; j++) {
           graph[i][j] = row[j] - '0';
       }
   }
 
   if (isCyclic(n))
       printf("Yes Cycle Exists\n");
   else
       printf("No Cycle Exists\n");
 
   return 0;
}

*/
 
 

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
 
#define MAX 100
#define INF 99999
 
int graph[MAX][MAX];
int parent[MAX];
int dist[MAX];
bool visited[MAX];
 
// Function to find the node with the minimum distance
int minDistance(int n) {
   int min = INF, min_index = -1;
   for (int v = 0; v < n; v++)
       if (!visited[v] && dist[v] <= min) {
           min = dist[v];
           min_index = v;
       }
   return min_index;
}
 
// Function to print path from a node to Akshay's house
void printPath(int node) {
   if (parent[node] == -1) {
       printf("%d ", node);
       return;
   }
   printPath(parent[node]);
   printf("%d ", node);
}
 
// Dijkstra's algorithm from source to all nodes
void dijkstra(int n, int src) {
   for (int i = 0; i < n; i++) {
       dist[i] = INF;
       visited[i] = false;
       parent[i] = -1;
   }
 
   dist[src] = 0;
 
   for (int count = 0; count < n - 1; count++) {
       int u = minDistance(n);
       if (u == -1) break;
       visited[u] = true;
 
       for (int v = 0; v < n; v++) {
           if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
               dist[v] = dist[u] + graph[u][v];
               parent[v] = u;
           }
       }
   }
}
 
int main() {
   int n, akshay;
   printf("Enter number of locations (nodes): ");
   scanf("%d", &n);
 
   printf("Enter the adjacency matrix (0 if no direct road):\n");
   for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++)
           scanf("%d", &graph[i][j]);
 
   printf("Enter Akshay's location index (0 to %d): ", n - 1);
   scanf("%d", &akshay);
 
   printf("\nShortest paths from each friend to Akshay's house (%d):\n\n", akshay);
   for (int i = 0; i < n; i++) {
       if (i == akshay) continue;
       // Run Dijkstra from friend node to get path to Akshay
       dijkstra(n, i);
       printf("Friend at node %d: Distance = %d, Path: ", i, dist[akshay]);
       if (dist[akshay] == INF)
           printf("No path\n");
       else {
           printPath(akshay);
           printf("\n");
       }
   }
 
   return 0;
}
