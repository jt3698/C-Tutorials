#include<bits/stdc++.h>
using namespace std;

int V,E;

struct Edge
{
    int from,to;
    int flow ;
    int C;
    int rev ;

} edges[100001];

vector<int>connections[100001];
int vis[100001],level[100001];

void AddEdge(int from,int to,int cap)
{
    E++;
    connections[from].push_back(E);
    connections[to].push_back(E);

    edges[E].from=from;
    edges[E].to=to;
    edges[E].rev=cap;
    edges[E].flow=0;
    edges[E].C=cap;

    return;
}

// Finds if more flow can be sent from s to t.
// Also assigns levels to nodes.
bool BFS(int s, int t)
{
    for (int i = 1 ; i <= V; i++)
        level[i] = -1;

    level[s] = 0;  // Level of source vertex

    // Create a queue, enqueue source vertex
    // and mark source vertex as visited here
    // level[] array works as visited array also.
    queue<int>q;
    q.push(s);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0;i<connections[u].size();i++){
            Edge &e = edges[connections[u][i]];
            int &real_flow = (u == e.from ? e.flow : e.rev);
            int &dest = (u == e.from ? e.to : e.from);

            if (level[dest] < 0  && real_flow < e.C){
                level[dest] = level[u] + 1;

                q.push(dest);
            }
        }
    }

    // IF we can not reach to the sink we
    // return false else true
    return (level[t] > 0);
}

int sendFlow(int u, int flow, int t)
{
    // Sink reached
    if(u == t)return flow;


    // Traverse all adjacent edges one -by - one.
    for(;vis[u]<connections[u].size();vis[u]++)
    {
        // Pick next edge from adjacency list of u
        Edge &e = edges[connections[u][vis[u]]];
        int &real_flow = (u == e.from ? e.flow : e.rev);
        int &real_backflow = (u == e.from ? e.rev : e.flow);
        int &dest = (u == e.from ? e.to : e.from);

        if(level[dest] == level[u]+1 && real_flow < e.C){
            // find minimum flow from u to t
            int curr_flow = min(flow, e.C - real_flow);

            int temp_flow = sendFlow(dest, curr_flow, t);

            // flow is greater than zero
            if(temp_flow > 0){
                // add flow  to current edge
                real_flow += temp_flow;

                // subtract flow from reverse edge
                // of current edge
                real_backflow -= temp_flow;

                return temp_flow;
            }
        }
    }

    return 0;
}

// Returns maximum flow in graph
int DinicMaxflow(int s, int t)
{
    // Corner case
    if (s == t)
        return -1;

    int total = 0;  // Initialize result

    // Augment the flow while there is path
    // from source to sink
    while (BFS(s, t) == true)
    {
        // store how many edges are visited
        // from V { 0 to V }
        for(int i=1;i<=V;i++)vis[i]=0;

        // while flow is not zero in graph from S to D
        while (int flow = sendFlow(s, INT_MAX, t))

            // Add path flow to overall flow
            total += flow;
    }

    // return maximum flow
    return total;
}

// Driver program to test above functions
int main()
{
    int E_0;
    cin>>V>>E_0;
    for(int i=1;i<=E_0;i++){
        int from,to,cap;
        scanf("%d %d %d",&from,&to,&cap);

        AddEdge(from,to,cap);
    }

    printf("%d\n",DinicMaxflow(1,V));
    return 0;
}

