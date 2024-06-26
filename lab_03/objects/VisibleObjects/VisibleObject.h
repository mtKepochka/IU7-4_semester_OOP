#ifndef VISIBLEOBJECT_H
#define VISIBLEOBJECT_H

#include "BaseObject.h"

class VisibleObject : public BaseObject
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    bool isVisible() const noexcept override { return true; }
};

#endif // VISIBLEOBJECT_H
