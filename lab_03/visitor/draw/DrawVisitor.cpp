#include "DrawVisitor.h"

#include "glm_wrapper.h"
#include <QDebug>
DrawVisitor::DrawVisitor(std::shared_ptr<BaseDrawer> drawer, std::shared_ptr<BaseCamera> camera)
{
    drawer_ = std::move(drawer);
    camera_ = std::move(camera);
}

void DrawVisitor::visit(Scene &scene)
{
    for (auto& [_, i]: scene)
        // if (i->isVisible())
            i->accept(*this);
}

void DrawVisitor::visit(ObjectComposite& group)
{
    std::shared_ptr<Transformation> trans = group.getTransformation();
    Matrix4 displacement = trans->getResultMatrix();
    addTransformContext(displacement);

    for (const auto& [_, object]: group)
    {
        // qDebug() << "ABOBA";
        object->accept(*this);
    }

    addTransformContext(inverse(displacement));
}

void DrawVisitor::visit(SceletonModel &model)
{
    const auto modelData = model.data_;

    std::shared_ptr<Transformation> trans = model.getTransformation();
    const auto model_matrix = trans->getResultMatrix();


    Matrix4 view_matrix = camera_->getViewMatrix();
    // Matrix4 projection_matrix = camera_->getProjectionMatrix();
    // projection_matrix = translate(projection_matrix, Vector3(1211/2.0,719/2.0,1));
    // projection_matrix = scale(projection_matrix, Vector3(1211/2.0,719/2.0,0));
    // Matrix4 matr = projection_matrix * view_matrix * context * model_matrix;
    Matrix4 matr = view_matrix * context * model_matrix;

    const auto& vertices = modelData->getVertices();


    for (const auto& edge: modelData->getEdges())
    {
        Vertex v1 = vertices[edge.getFirstInd()];
        Vertex v2 = vertices[edge.getSecondInd()];

        Vector3 vec1 = matr * Vector3(v1.getX(), v1.getY(), v1.getZ());
        Vector3 vec2 = matr * Vector3(v2.getX(), v2.getY(), v2.getZ());

        drawer_->drawLine(
            vec1[0], vec1[1],
            vec2[0], vec2[1]);
    }
}


void DrawVisitor::visit(BaseCamera &camera)
{

}


void DrawVisitor::clearTransformContext()
{
    context = Matrix4(1.0);
}
void DrawVisitor::addTransformContext(const Matrix4 &ctx)
{
    context = context * ctx;
}
