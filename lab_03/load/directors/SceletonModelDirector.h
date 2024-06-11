#ifndef SceletonMODELDIRECTOR_H
#define SceletonMODELDIRECTOR_H

#include <memory>

#include "ModelDirector.h"

#include "BaseModel.h"
#include "ModelBuilder.h"

class SceletonModelDirector : public ModelDirector
{
public:
    virtual std::shared_ptr<BaseModel> create(std::shared_ptr<ModelBuilder> builder) override;
};

#endif // SceletonMODELDIRECTOR_H
