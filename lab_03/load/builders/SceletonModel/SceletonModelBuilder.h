#ifndef SceletonMODELBUILDER_H
#define SceletonMODELBUILDER_H

#include <memory>

#include <ModelBuilder.h>

#include <SceletonModel.h>

class SceletonModelBuilder : public ModelBuilder
{
public:
    SceletonModelBuilder() = default;
    ~SceletonModelBuilder() = default;

    virtual bool buildVertex()  = 0;
    virtual bool buildEdge() = 0;

    virtual std::shared_ptr<BaseModel> get() = 0;

protected:
    virtual std::shared_ptr<BaseModel> create() = 0;
};

#endif // SceletonMODELBUILDER_H
