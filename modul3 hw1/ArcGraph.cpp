#include <vector>
#include <cassert>
#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices_count) : vertices_count(vertices_count) {}

ArcGraph::ArcGraph(const IGraph &graph) {
    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        std::vector<int> nextVertices = graph.GetNextVertices(i);

        for (size_t j : nextVertices) {
            vertices.emplace_back(i, j);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    assert(from < vertices_count && from >= 0);
    assert(to < vertices_count && to >= 0);

    vertices.emplace_back(Pair(from, to));
}

int ArcGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;
    for (auto &pair : vertices) {
        if (pair.from == vertex) {
            result.push_back(pair.to);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;
    for (auto &pair : vertices) {
        if (pair.to == vertex) {
            result.push_back(pair.from);
        }
    }
    return result;
}

ArcGraph::Pair::Pair(int from, int to)  : from(from), to(to) {}
