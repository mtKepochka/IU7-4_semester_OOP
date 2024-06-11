#include "AdjacencyListSceletonModelBuilderFactory.h"
#include "AdjacencyListSceletonModelBuilder.h"

std::shared_ptr<ModelBuilder> AdjacencyListSceletonModelBuilderFactory::create(std::shared_ptr<ModelSource> source)
{
    return std::make_shared<AdjacencyListSceletonModelBuilder>(source);
}
