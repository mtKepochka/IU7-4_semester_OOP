#ifndef VERTEXEDGESceletonMODELBUILDERFACTORY_H
#define VERTEXEDGESceletonMODELBUILDERFACTORY_H

#include "SceletonModelBuilderFactory.h"

class VertexEdgeSceletonModelBuilderFactory : public SceletonModelBuilderFactory
{
public:
    virtual std::shared_ptr<ModelBuilder> create(std::shared_ptr<ModelSource> source) override;
};

#endif // VERTEXEDGESceletonMODELBUILDERFACTORY_H
