#ifndef ADJACENCYLISTSceletonMODELBUILDER_H
#define ADJACENCYLISTSceletonMODELBUILDER_H

#include "SceletonModelBuilder.h"


#include "AdjacencyList.h"
#include "SceletonModel.h"
#include "AdjacencyListData.h"

class AdjacencyListSceletonModelBuilder : public SceletonModelBuilder
{
public:
    explicit AdjacencyListSceletonModelBuilder(std::shared_ptr<ModelSource> source);

    virtual bool buildVertex() override;
    virtual bool buildEdge() override;

    virtual std::shared_ptr<BaseModel> get() override;

protected:
    virtual std::shared_ptr<BaseModel> create() override;

private:
    std::vector<Vertex> vertices{};
    AdjacencyList adjacencyList{};
};

#endif // ADJACENCYLISTSceletonMODELBUILDER_H
