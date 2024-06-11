#ifndef ADJACENCYLISTDATA_H
#define ADJACENCYLISTDATA_H

#include "SceletonModelData.h"

#include <vector>

#include "Vertex.h"
#include "Edge.h"
#include "AdjacencyList.h"

class AdjacencyListData : public SceletonModelData
{
public:
    AdjacencyListData(std::vector<Vertex> vertices, AdjacencyList adjacencyList);
    const std::vector<Vertex>& getVertices() const;
    const std::vector<Edge>& getEdges() const;

    void addVertex(const Vertex& vertex);
    void addEdge(const Edge& edge);

private:
    std::vector<Vertex> vertices_;
    AdjacencyList adjacencyList_;
};

#endif // ADJACENCYLISTDATA_H
