#ifndef OBJECTCOMPOSITE_H
#define OBJECTCOMPOSITE_H

#include "BaseObject.h"

class ObjectComposite : public BaseObject
{
public:
    ObjectComposite() = default;
    explicit ObjectComposite(std::shared_ptr<BaseObject> &object);

    virtual int add(const std::shared_ptr<BaseObject> &) override;
    virtual bool remove(int objectId) override;

    bool isVisible() const noexcept override { return true; }

    virtual std::shared_ptr<BaseObject> getObject(int id) override;
    virtual Iterator begin() override;
    virtual Iterator end() override;
    virtual void accept(BaseVisitor& v) override { v.visit(*this); };

private:
    ObjectMap objects_{};
    int objCount = 0;
};;

#endif // OBJECTCOMPOSITE_H
