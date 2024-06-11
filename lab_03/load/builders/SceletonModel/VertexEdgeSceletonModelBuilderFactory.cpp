#include "VertexEdgeSceletonModelBuilderFactory.h"
#include "VertexEdgeSceletonModelBuilder.h"

std::shared_ptr<ModelBuilder> VertexEdgeSceletonModelBuilderFactory::create(std::shared_ptr<ModelSource> source)
{
    return std::make_shared<VertexEdgeSceletonModelBuilder>(source);
}
