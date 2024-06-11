#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include <map>
#include <memory>

#include "BaseVisitor.h"
#include "Vertex.h"

#include "Matrix4.h"

#include "Transformation.h"

#include "Memento.h"

class BaseObject;

using ObjectMap = std::map<int, std::shared_ptr<BaseObject>>;
using Iterator = ObjectMap::iterator;

class BaseObject
{
public:
    BaseObject();
    virtual ~BaseObject() = default;

    virtual void accept(BaseVisitor& v) {};
    //Matrix4 getTransformMatrix() const;
    std::shared_ptr<Transformation> getTransformation();


    virtual bool isVisible() const noexcept = 0;
    virtual bool isComposite() { return  false; }

    virtual int add(const std::shared_ptr<BaseObject> &) { return false; }
    virtual bool remove(int objectId) { return false; }

    virtual std::shared_ptr<BaseObject> getObject(int objectId) {return nullptr; };

    virtual Iterator begin() { return Iterator(); }
    virtual Iterator end() { return Iterator(); }

    std::unique_ptr<Memento> createMemento();
    void restoreMemento(std::shared_ptr<Memento> memento);
protected:
    std::shared_ptr<Transformation> transformation;
};

#endif // BASEOBJECT_H
