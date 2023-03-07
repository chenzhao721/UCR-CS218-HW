#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
 


// Data structure to store a graph edge
struct Edge {
    int source, dest, weight;
};
 
// Data structure to store a heap node
struct Node {
    int vertex, weight;
};

int *dist;
vector<Edge> *adjlist;
 
void print_route(vector<int> const &prev, int i)
{
    if (i < 0) {
        return;
    }
 
    print_route(prev, prev[i]);
    cout << i << " ";
}
 
// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node &lhs, const Node &rhs) const {
        return lhs.weight > rhs.weight;
    }
};
 
// Run Dijkstra¡¯s algorithm on the given graph
void findShortestPaths(int source, int cities)
{
    // create a min-heap and push source node having distance 0
    priority_queue<Node, vector<Node>, comp> min_heap;
	Node tempnode;
	tempnode.vertex=source;
	tempnode.weight=0;

    min_heap.push(tempnode);

 
    // distance from the source to itself is zero
    dist[source] = 0;
 
    // boolean array to track vertices for which minimum
    // cost is already found
    vector<bool> done(cities, false);
    done[source] = true;
 
    // stores predecessor of a vertex (to a print path)
    vector<int> prev(cities, -1);
 
    // run till min-heap is empty
    while (!min_heap.empty())
    {
        // Remove and return the best vertex
        Node node = min_heap.top();
        min_heap.pop();
 
        // get the vertex number
        int u = node.vertex;
 
        // do for each neighbor `v` of `u`
        for (vector<Edge>::iterator i= adjlist[u].begin();i<adjlist[u].end();i++)
        {
            int v = (*i).dest;
            int weight = (*i).weight;
 
            // Relaxation step
            if (!done[v] && (dist[u] + weight) < dist[v])
            {
                dist[v] = dist[u] + weight;
                prev[v] = u;
				tempnode.vertex = v;
                tempnode.weight = dist[v];
                min_heap.push(tempnode);
            }
        }
 
        // mark vertex `u` as done so it will not get picked up again
        done[u] = true;
    }
 
    //for (int i = 0; i < cities; i++)
    //{
    //    if (i != source && dist[i] != INT_MAX)
   //     {
   //         cout << "Path (" << source << " ¡ª> " << i << "): Minimum cost = "
    //             << dist[i] << ", Route = [ ";
   //        //print_route(prev, i);
   //         cout << "]" << endl;
   //     }
   // }
}
 
int main()
{
    int temp;
	int i;
    int cities, roads;
	int output=0;

    scanf("%d", &cities);
	scanf("%d", &roads);

	adjlist = new vector<Edge>[cities];
	dist = new int[cities];
	int *price = new int[cities];
	int *income = new int[cities];

	for(i=0;i<cities;i++){
		scanf("%d", &price[i]);
	}

	 // set initial distance from the source to `v` as INFINITY
	for(i=0;i<cities;i++)
		dist[i] = INT_MAX;

    Edge newedge;

    for(i=0;i<roads;i++){
		scanf("%d %d %d", &newedge.source, &newedge.dest, &newedge.weight);
		adjlist[newedge.source].push_back(newedge);

		temp = newedge.source;
		newedge.source = newedge.dest;
		newedge.dest = temp;

        adjlist[newedge.source].push_back(newedge);

	}
    
 
    // total number of nodes in the graph
    findShortestPaths(0, cities);

    for(i=0;i<cities;i++){
		if(price[i]-2*dist[i]>output)
			output = price[i]-2*dist[i];
	}

	printf("%d\n", output);

 
    return 0;
}

