#include <iostream>
#include <queue>
#include <stack>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void dfs(const IGraph& graph, void (*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::stack<int> vertices;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            callback(vertex);
            std::vector<int> children = graph.GetNextVertices(vertex);
            for (auto & child : children) {
                if (!visited[child]) {
                    vertices.push(child);
                }
            }
            while (!vertices.empty()) {
                visited[vertices.top()] = true;
                callback(vertices.top());
                std::vector<int> childrenOfChild = graph.GetNextVertices(vertices.top());
                vertices.pop();
                for (auto & child : childrenOfChild) {
                    if (!visited[child]) {
                        vertices.push(child);
                    }
                }
            }
        }
    }
}

void bfs(const IGraph& graph, void (*callback)(int v)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q;

    for (int vertex = 0; vertex < graph.VerticesCount(); ++vertex) {
        if (!visited[vertex]) {
            visited[vertex] = true;
            q.push(vertex);


            while ((!q.empty())) {
                int v = q.front();
                q.pop();
                callback(v);
                std::vector<int> children = graph.GetNextVertices(v);
                for (auto & child : children) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
    }
}

int main() {
    IGraph* graphList = new ListGraph(9);
    graphList->AddEdge(0, 1);
    graphList->AddEdge(1, 2);
    graphList->AddEdge(1, 5);
    graphList->AddEdge(2, 3);
    graphList->AddEdge(3, 4);
    graphList->AddEdge(4, 2);
    graphList->AddEdge(6, 0);
    graphList->AddEdge(0, 7);
    graphList->AddEdge(0, 8);

    std::cout << "---ListGraph---"<< std::endl;
    std::cout << "---DFS---"<< std::endl;
    dfs(*graphList, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;

    std::cout << "---BFS---"<< std::endl;
    bfs(*graphList, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;
    std::cout << std::endl;

    IGraph* graphMatrix = new MatrixGraph(9);
    graphMatrix->AddEdge(0, 1);
    graphMatrix->AddEdge(1, 2);
    graphMatrix->AddEdge(1, 5);
    graphMatrix->AddEdge(2, 3);
    graphMatrix->AddEdge(3, 4);
    graphMatrix->AddEdge(4, 2);
    graphMatrix->AddEdge(6, 0);
    graphMatrix->AddEdge(0, 7);
    graphMatrix->AddEdge(0, 8);

    std::cout << "---MatrixGraph---"<< std::endl;
    std::cout << "---DFS---"<< std::endl;
    dfs(*graphMatrix, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;

    std::cout << "---BFS---"<< std::endl;
    bfs(*graphMatrix, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;
    std::cout << std::endl;

    IGraph* graphSet = new SetGraph(9);
    graphSet->AddEdge(0, 1);
    graphSet->AddEdge(1, 2);
    graphSet->AddEdge(1, 5);
    graphSet->AddEdge(2, 3);
    graphSet->AddEdge(3, 4);
    graphSet->AddEdge(4, 2);
    graphSet->AddEdge(6, 0);
    graphSet->AddEdge(0, 7);
    graphSet->AddEdge(0, 8);

    std::cout << "---SetGraph---"<< std::endl;
    std::cout << "---DFS---"<< std::endl;
    dfs(*graphSet, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;

    std::cout << "---BFS---"<< std::endl;
    bfs(*graphSet, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;
    std::cout << std::endl;

    IGraph* graphArc = new ArcGraph(9);
    graphArc->AddEdge(0, 1);
    graphArc->AddEdge(1, 2);
    graphArc->AddEdge(1, 5);
    graphArc->AddEdge(2, 3);
    graphArc->AddEdge(3, 4);
    graphArc->AddEdge(4, 2);
    graphArc->AddEdge(6, 0);
    graphArc->AddEdge(0, 7);
    graphArc->AddEdge(0, 8);

    std::cout << "---ArcGraph---"<< std::endl;
    std::cout << "---DFS---"<< std::endl;
    dfs(*graphArc, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;

    std::cout << "---BFS---"<< std::endl;
    bfs(*graphArc, [](int v) {
        std::cout << v << " ";
    });

    std::cout << std::endl;
    std::cout << std::endl;

    delete graphList;
    delete graphMatrix;
    delete graphSet;
    delete graphArc;
    return 0;
}
