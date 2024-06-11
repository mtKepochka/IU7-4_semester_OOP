#ifndef VERTEXEDGESceletonMODELBUILDER_H
#define VERTEXEDGESceletonMODELBUILDER_H

#include "SceletonModelBuilder.h"

#include "Edge.h"

#include "SceletonModel.h"
#include "VertexEdgeData.h"

class VertexEdgeSceletonModelBuilder : public SceletonModelBuilder
{
public:
    explicit VertexEdgeSceletonModelBuilder(std::shared_ptr<ModelSource> source);

    virtual bool buildVertex() override;
    virtual bool buildEdge() override;

    virtual std::shared_ptr<BaseModel> get() override;

protected:
    virtual std::shared_ptr<BaseModel> create() override;

private:
    std::vector<Vertex> vertices{};
    std::vector<Edge> edges{};
};

#endif // VERTEXEDGESceletonMODELBUILDER_H
