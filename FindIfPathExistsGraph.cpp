//
// Created by ljw on 16/09/21.
//

#include <unordered_set>
#include <queue>
#include "FindIfPathExistsGraph.h"

//  https://leetcode.com/problems/find-if-path-exists-in-graph/
namespace  FindIfPathExistsGraph {
    typedef  std::vector<std::vector<int>> Edges;
    class Graph {
    public:
        Graph(int n, const Edges& edges)  : adjacency(n) {
            for (int src = 0; src < edges.size(); src++) {
                auto dest = edges[src];
                for (const auto& d: dest) {
                    adjacency[src].insert(d);
                }
            }
        }

        std::vector<std::unordered_set<int>> adjacency;
    };
    bool validPath(int n, std::vector<std::vector<int>>& edges, int start, int end) {
        Graph graph(n, edges);
        std::vector<bool> mark(n, false);
        std::queue<int> q;
        q.push(start);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (mark[node])
                continue;

            for (auto n1: graph.adjacency[node]) {
                if (n1 == end)
                    return true;
                q.push(n1);
            }
            mark[node] = true;
        }
        return false;
    }

    std::vector<std::vector<int>> generate(int n, const std::vector<std::tuple<int, int>> edges) {
        std::vector<std::vector<int>> adjacency(n);
        for (const auto& e: edges) {
            auto index = &adjacency[std::get<0>(e)];
            index->push_back(std::get<1>(e));
        }
        return adjacency;
    }
};