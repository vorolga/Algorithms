#ifndef UNTITLED_SETGRAPH_H
#define UNTITLED_SETGRAPH_H

#include <set>
#include "IGraph.h"

class SetGraph : public IGraph {
public:
    explicit SetGraph(int vertices_count);

    explicit SetGraph(const IGraph& graph);

    ~SetGraph() {}

    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> vertices;
};

#endif //UNTITLED_SETGRAPH_H
