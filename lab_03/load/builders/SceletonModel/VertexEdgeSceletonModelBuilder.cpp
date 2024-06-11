#include "VertexEdgeSceletonModelBuilder.h"

VertexEdgeSceletonModelBuilder::VertexEdgeSceletonModelBuilder(std::shared_ptr<ModelSource> source)
{
    source_ = source;
}

bool VertexEdgeSceletonModelBuilder::buildVertex()
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

bool VertexEdgeSceletonModelBuilder::buildEdge()
{
    if (part == 1)
        ++part;

    if (part != 2) return false;

    std::optional<Edge> maybeEdge{};
    maybeEdge = source_->nextEdge();
    while (maybeEdge.has_value())
    {
        edges.push_back(maybeEdge.value());
        maybeEdge = source_->nextEdge();
    }

    return true;
}

std::shared_ptr<BaseModel> VertexEdgeSceletonModelBuilder::get()
{
    if (!model_) { model_ = create(); }

    return model_;
}

std::shared_ptr<BaseModel> VertexEdgeSceletonModelBuilder::create()
{
    if (part == 2)
    {
        auto modelData = std::make_shared<VertexEdgeData>(vertices, edges);

        model_ = std::make_shared<SceletonModel>(modelData);
    }

    return model_;
}
