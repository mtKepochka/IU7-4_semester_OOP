#ifndef ADJACENCYLISTSceletonMODELBUILDERFACTORY_H
#define ADJACENCYLISTSceletonMODELBUILDERFACTORY_H

#include "SceletonModelBuilderFactory.h"

class AdjacencyListSceletonModelBuilderFactory : public SceletonModelBuilderFactory
{
public:
    virtual std::shared_ptr<ModelBuilder> create(std::shared_ptr<ModelSource> source) override;
};

#endif // ADJACENCYLISTSceletonMODELBUILDERFACTORY_H
