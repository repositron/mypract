//
// Created by ljw on 11/12/20.
//

#ifndef MYPRACT_GRAPH_H
#define MYPRACT_GRAPH_H


#include <unordered_set>
#include <vector>
#include <memory>
#include <stack>
#include <queue>


class Graph;
namespace graphUtil {
    std::unique_ptr<Graph> read(const std::string &filename);
};

class Graph {
public:
    Graph(size_t V) :
        numberVertices(V), adj(V) {
    }
    void addEdge(int v, int w) {
        adj[v].insert(w);
        adj[w].insert(v);
        numberEdges++;
    }

    int numberVertices = 0;
    int numberEdges = 0;
    std::vector<std::unordered_set<int>> adj;
};

class DepthFirstSearch
{
public:
    DepthFirstSearch(const Graph& g, int source)
        : marked(g.numberVertices),
          edgeTo(g.numberVertices),
          source(source)
    {
        dfs(g, source);
    }
    void dfs(const Graph& g, int v) {
        marked[v] = true;
        for (int w: g.adj[v]) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(g, w);
            }
        }
    }

    bool hasPathTo(int v) {
        return marked[v];
    }

    std::deque<int> pathTo(int v) {
        if (!hasPathTo(v))
            return {};
        std::deque<int> path;
        for (int x = v; x != source; x = edgeTo[x])
            path.push_front(x);
        path.push_front(source);
        return path;
    }

private:
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int source = 0;
};

class BreadthFirstPaths {
public:
    BreadthFirstPaths(const Graph& g, int source) :
        source(source)
    {
        bfs(g, source);
    }
    void bfs(const Graph& g, int source) {
        std::queue<int> queue;
        marked[source] = true;
        queue.push(source);
        while (!queue.empty())
        {
            int v = queue.back();
            for (int w: g.adj[v]) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    marked[w] = true;
                    queue.push(w);
                }
            }
        }
    }

    bool hasPathTo(int v) {
        return marked[v];
    }
    
    std::deque<int> pathTo(int v) {
        if (!hasPathTo(v))
            return {};
        std::deque<int> path;
        for (int x = v; x != source; x = edgeTo[x])
            path.push_front(x);
        path.push_front(source);
        return path;
    }
private:
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    int source = 0;
};

#endif //MYPRACT_GRAPH_H
