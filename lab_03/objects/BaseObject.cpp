#include "BaseObject.h"

BaseObject::BaseObject()
{
    transformation = std::make_shared<Transformation>();
}

// Matrix4 BaseObject::getTransformMatrix() const
// {
//     return transformation->getResultMatrix();
// }

std::unique_ptr<Memento> BaseObject::createMemento()
{
    return std::make_unique<Memento>(*transformation.get());
}

void BaseObject::restoreMemento(std::shared_ptr<Memento> memento)
{
    if (memento != nullptr)
        transformation = std::make_shared<Transformation>(memento->getData());
}

std::shared_ptr<Transformation> BaseObject::getTransformation()
{
    return transformation;
}
