#include<bits/stdc++.h>
using namespace std;

#define NIL 0
#define INF INT_MAX

int M,N;
vector<int>connections[100001];

int pairU[100001],pairV[100001];
int dist[100001];

// Returns true if there is an augmenting path beginning with free vertex u
bool dfs(int u)
{
    if (u != NIL){
        for (int i=0;i<connections[u].size();i++){
            // Adjacent to u
            int v=connections[u][i];

            // Follow the distances set by BFS
            if (dist[pairV[v]] == dist[u]+1)
            {
                // If dfs for pair of v also returns
                // true
                if (dfs(pairV[v]) == true)
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        // If there is no augmenting path beginning with u.
        dist[u] = INF;
        return false;
    }
    return true;
}

// Returns true if there is an augmenting path, else returns
// false
bool bfs()
{
    queue<int> Q; //an integer queue

    // First layer of vertices (set distance as 0)
    for (int u=1; u<=M; u++){
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL){
            // u is not matched
            dist[u] = 0;
            Q.push(u);
        }

        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }

    // Initialize distance to NIL as infinite
    dist[NIL] = INF;

    // Q is going to contain vertices of left side only.
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();

        // If this node is not NIL and can provide a shorter path to NIL
        if (dist[u] < dist[NIL])
        {
            // Get all adjacent vertices of the dequeued vertex u
            for (int i=0;i<connections[u].size();i++)
            {
                int v = connections[u][i];

                // If pair of v is not considered so far
                // (v, pairV[V]) is not yet explored edge.
                if (dist[pairV[v]] == INF)
                {
                    // Consider the pair and add it to queue
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }

    // If we could come back to NIL using alternating path of distinct
    // vertices then there is an augmenting path
    return (dist[NIL] != INF);
}

// Returns size of maximum matching
int hopcroftKarp()
{
    // Initialize NIL as pair of all vertices
    for(int u=0;u<=M;u++)pairU[u] = NIL;
    for(int v=0;v<=N;v++)pairV[v] = NIL;

    // Initialize result
    int result = 0;

    // Keep updating the result while there is an
    // augmenting path.
    while (bfs())
    {
        // Find a free vertex
        for (int u=1; u<=M; u++)

            // If current vertex is free and there is
            // an augmenting path from current vertex
            if (pairU[u]==NIL && dfs(u)) result++;
    }
    return result;
}

// To add edge from u to v and v to u
void addEdge(int u, int v)
{
    connections[u].push_back(v); // Add u to v’s list.
}

// Driver Program
int main()
{
    M=4;N=4;
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 1);
    addEdge(3, 2);
    addEdge(4, 2);
    addEdge(4, 4);

    cout << "Size of maximum matching is " << hopcroftKarp();

    return 0;
}
