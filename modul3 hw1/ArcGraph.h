#ifndef UNTITLED_ARCGRAPH_H
#define UNTITLED_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int vertices_count);

    explicit ArcGraph(const IGraph& graph);

    ~ArcGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    struct Pair {
        int from;
        int to;

        Pair(int from, int to);
        Pair() = default;
    };

    int vertices_count;
    std::vector<Pair> vertices;
};

#endif //UNTITLED_ARCGRAPH_H
