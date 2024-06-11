#ifndef SceletonMODELBUILDERFACTORY_H
#define SceletonMODELBUILDERFACTORY_H

#include <memory>

#include "ModelBuilder.h"

class SceletonModelBuilderFactory
{
public:
    virtual ~SceletonModelBuilderFactory() = default;
    virtual std::shared_ptr<ModelBuilder> create(std::shared_ptr<ModelSource> source) = 0;
};

#endif // SceletonMODELBUILDERFACTORY_H
