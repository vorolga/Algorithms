#include <set>
#include <vector>
#include <cassert>

#include "SetGraph.h"

SetGraph::SetGraph(int vertices_count) {
    vertices.resize(vertices_count);
}

SetGraph::SetGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());

    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);

        for (size_t j : nextVertices) {
            vertices[i].insert(j);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    assert(from < vertices.size() && from >= 0);
    assert(to < vertices.size() && to >= 0);

    vertices[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result(vertices[vertex].begin(), vertices[vertex].end());
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;

    for (int parent = 0; parent < vertices.size(); ++parent) {
        if (vertices[parent].count(vertex) != 0) {
            result.push_back(parent);
        }
    }

    return result;
}
