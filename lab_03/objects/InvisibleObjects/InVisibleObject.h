#ifndef INVISIBLEOBJECT_H
#define INVISIBLEOBJECT_H

#include "BaseObject.h"

class InVisibleObject : public BaseObject
{
public:
    InVisibleObject() = default;
    ~InVisibleObject() = default;

    bool isVisible() const noexcept override { return false; }
};

#endif // INVISIBLEOBJECT_H
