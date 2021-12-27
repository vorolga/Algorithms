#include <cassert>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices_count) {
    vertices.resize(vertices_count);
    for (size_t i = 0; i < vertices_count; ++i) {
        vertices[i].resize(vertices_count);
        for (size_t j = 0; j < vertices_count; ++j) {
            vertices[i][j] = 0;
        }
    }
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
    vertices.resize(graph.VerticesCount());

    for (size_t i = 0; i < graph.VerticesCount(); ++i) {
        vertices[i].resize(graph.VerticesCount());
        for (size_t j = 0; j < graph.VerticesCount(); ++j) {
            vertices[i][j] = 0;
        }

        std::vector<int> nextVartices = graph.GetNextVertices(i);
        for (size_t j : nextVartices) {
            vertices[i][j] = 1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    assert(from < vertices.size() && from >= 0);
    assert(to < vertices.size() && to >= 0);

    vertices[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return vertices.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[vertex][i] == 1) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex < vertices.size() && vertex >= 0);

    std::vector<int> result;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i][vertex] == 1) {
            result.push_back(i);
        }
    }
    return result;
}
