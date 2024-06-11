#ifndef BASEVISITOR_H
#define BASEVISITOR_H

class Scene;
class ObjectComposite;
class SceletonModel;
class BaseCamera;

class BaseVisitor
{
public:
    virtual void visit(Scene &scene) = 0;
    virtual void visit(ObjectComposite& group) = 0;
    virtual void visit(SceletonModel &model) = 0;
    virtual void visit(BaseCamera &camera) = 0;
};

#endif // BASEVISITOR_H
