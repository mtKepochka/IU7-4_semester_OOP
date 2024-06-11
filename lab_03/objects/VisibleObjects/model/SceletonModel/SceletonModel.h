#ifndef SceletonMODEL_H
#define SceletonMODEL_H

#include "BaseModel.h"

#include "SceletonModelData.h"

class SceletonModel : public BaseModel
{
public:
    SceletonModel() = default;
    explicit SceletonModel(const std::shared_ptr<SceletonModelData> &data) :
        data_(data) { }
    SceletonModel(const SceletonModel &model);

    ~SceletonModel() override = default;

    virtual void accept(BaseVisitor& v) override { v.visit(*this); };



protected:
    friend class DrawVisitor;
    std::shared_ptr<SceletonModelData> data_{ nullptr };
};

#endif // SceletonMODEL_H
