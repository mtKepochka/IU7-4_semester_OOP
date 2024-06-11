#include "AdjacencyListSceletonModelBuilder.h"

AdjacencyListSceletonModelBuilder::AdjacencyListSceletonModelBuilder(std::shared_ptr<ModelSource> source)
{
    source_ = source;
}

bool AdjacencyListSceletonModelBuilder::buildVertex()
{
    if (!part)
        ++part;

    if (part != 1) return false;

    std::optional<Vertex> maybeVertex{};
    maybeVertex = source_->nextVertex();
    while (maybeVertex.has_value())
    {
        vertices.push_back(maybeVertex.value());
        maybeVertex = source_->nextVertex();
    }

    return true;
}
bool AdjacencyListSceletonModelBuilder::buildEdge()
{
    if (part == 1)
        ++part;

    if (part != 2) return false;

    std::optional<Edge> maybeEdge{};
    maybeEdge = source_->nextEdge();
    while (maybeEdge.has_value())
    {
        adjacencyList.add(maybeEdge.value().getFirstInd(), maybeEdge.value().getSecondInd());
        maybeEdge = source_->nextEdge();
    }

    return true;
}

std::shared_ptr<BaseModel> AdjacencyListSceletonModelBuilder::get()
{
    if (!model_) { model_ = create(); }

    return model_;
}

std::shared_ptr<BaseModel> AdjacencyListSceletonModelBuilder::create()
{
    if (part == 2)
    {
        auto modelData = std::make_shared<AdjacencyListData>(vertices, adjacencyList);

        model_ = std::make_shared<SceletonModel>(modelData);
    }

    return model_;
}

