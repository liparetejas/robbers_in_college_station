/* Dijkstra's single source shortest path algorithm */
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<unordered_map>
using namespace std;

// Time: E.log(V)
vector<int> dijkstra(int src, int n, 
		vector<vector<pair<int, int>>>& adjList) {
    vector<int> shortestDistances(n, INT_MAX);
    shortestDistances[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int curr = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto adjNodePair : adjList[curr]) {
            int adjNode = adjNodePair.first;
            int w = adjNodePair.second;
            if(d+w < shortestDistances[adjNode]) {
                shortestDistances[adjNode] = d+w;
                pq.push({shortestDistances[adjNode], adjNode});
            }
        }
    }
    return shortestDistances;
}

int main()
{
	int nodes, edges;
    cin >> nodes >> edges;
	vector<vector<pair<int, int>>> adjList(nodes+1); 
	for(int i=0; i<edges; i++) {
	    int u, v, w;
	    cin >> u >> v >> w;
	    adjList[u].push_back({v, w});
	    adjList[v].push_back({u, w}); 
	}	
    vector<int> shortestDistances = dijkstra(1, nodes+1, adjList);
	vector<int> destinations = {6, 8, 9, 15, 16, 22};
	for(int d : destinations) {
		cout << "Distance of " << d << " from 1 is " << 
				shortestDistances[d] << endl;
	}
    return 0;
}

/*
Input:
22 28
 1  2 1
 1 11 1
 2  3 1
 2 21 2
 3  4 1
 3  8 2
 4  5 1
 5  6 2
 5  7 1
 5 22 1
 6  7 1
 7  8 1
 8  9 1
 9 10 1
 9 19 2
10 11 1
10 18 2
11 17 1
11 12 2
12 13 2
13 14 2
13 21 1
14 15 1
14 16 1
14 20 1
16 17 2
17 18 2
20 21 2
20 22 1
21 22 2

Output:
Distance of 1 from 1 is 0
Distance of 2 from 1 is 1
Distance of 3 from 1 is 2
Distance of 4 from 1 is 3
Distance of 5 from 1 is 4
Distance of 6 from 1 is 6
Distance of 7 from 1 is 5
Distance of 8 from 1 is 4
Distance of 9 from 1 is 3
Distance of 10 from 1 is 2
Distance of 11 from 1 is 1
Distance of 12 from 1 is 3
Distance of 13 from 1 is 3
Distance of 14 from 1 is 5
Distance of 15 from 1 is 6
Distance of 16 from 1 is 6
Distance of 17 from 1 is 2
Distance of 18 from 1 is 4
Distance of 19 from 1 is 5
Distance of 20 from 1 is 4
Distance of 21 from 1 is 2
Distance of 22 from 1 is 2147483647
*/