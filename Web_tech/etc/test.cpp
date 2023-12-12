#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class q1 {
public:
    struct Edge {
        int src, dest;
        Edge(int srcc, int destt) : src(srcc), dest(destt) {}
    };

    static bool isCyclic(std::vector<Edge>* graph, int v) {
        unordered_set<int> visited;

        for (int i = 0; i < v; i++) {
            if (visited.find(i) == visited.end()) {
                if (isCyclicUtil(graph, i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    static bool isCyclicUtil(std::vector<Edge>* graph, int v, std::unordered_set<int>& visited, int parent) {
        std::queue<int> q;
        q.push(v);
        visited.insert(v);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (const Edge& e : graph[curr]) {
                if (visited.find(e.dest) == visited.end()) {
                    q.push(e.dest);
                    visited.insert(e.dest);
                } else if (e.dest != parent) {
                    return true; // Cycle detected
                }
            }
        }

        return false;
    }

    static void createGraph(std::vector<Edge>* graph, int v) {
        for (int i = 0; i < v; i++) {
            graph[i] = std::vector<Edge>();
        }

        graph[0].push_back(Edge(0, 1));
        graph[0].push_back(Edge(0, 5));

        graph[1].push_back(Edge(1, 9));
        graph[1].push_back(Edge(1, 5));

        graph[2].push_back(Edge(2, 5));
        graph[2].push_back(Edge(2, 9));

        graph[3].push_back(Edge(3, 2));
        graph[3].push_back(Edge(3, 5));

        graph[4].push_back(Edge(4, 2));
    }

    static void main() {
        int v = 5;
        std::vector<Edge>* graph = new std::vector<Edge>[v];

        createGraph(graph, v);

        std::cout << isCyclic(graph, v) << std::endl; // Output should be true

        delete[] graph;
    }
};

int main() {
    q1::main(); // Call the main function within the q1 class
    return 0;
}
