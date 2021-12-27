#include <cassert>
#include "ListGraph.h"

ListGraph::ListGraph(int vertices_count) {
    vertices.resize(vertices_count);
}

ListGraph::ListGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());
    for (size_t i = 0; i < vertices.size(); ++i) {
        vertices[i] = graph.GetNextVertices(i);
    }
}

void ListGraph::AddEdge(int from, int to) {
    assert(from < vertices.size() && from >= 0);
    assert(to < vertices.size() && to >= 0);

    vertices[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;

    for (int parent = 0; parent < vertices.size(); ++parent) {
        for (auto &child : vertices[parent]) {
            if (child == vertex) {
                result.push_back(parent);
                break;
            }
        }
    }

    return result;
}