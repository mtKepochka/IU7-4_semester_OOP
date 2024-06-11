#include "ModelDirectorSolution.h"

ModelDirectorSolution::ModelDirectorSolution(std::initializer_list<std::pair<int, CreateCreator>> list)
{
    for (auto elem : list)
        this->registration(elem.first, elem.second);
}

bool ModelDirectorSolution::registration(int id, CreateCreator createfun)
{
    return callbacks.insert(CallBackMap::value_type(id, createfun)).second;
}

std::unique_ptr<ModelDirector> ModelDirectorSolution::create(ModelType type)
{
    CallBackMap::const_iterator it = callbacks.find(static_cast<int>(type));

    if (it == callbacks.end())
    {
        return nullptr;
    }

    auto directorFactory = it->second();

    return directorFactory->create();

    // if (type == ModelType::SceletonModel)
    // {
    //     auto directorFactory = std::make_unique<SceletonModelDirectorFactory>();
    //     return directorFactory->create();
    // }
    // return nullptr;
}
