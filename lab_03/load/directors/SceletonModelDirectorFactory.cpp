#include "SceletonModelDirectorFactory.h"

#include "SceletonModelDirector.h"

std::unique_ptr<ModelDirector> SceletonModelDirectorFactory::create()
{
    return std::make_unique<SceletonModelDirector>();
}
