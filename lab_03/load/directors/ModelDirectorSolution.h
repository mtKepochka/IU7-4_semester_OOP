#ifndef MODELDIRECTORSOLUTION_H
#define MODELDIRECTORSOLUTION_H

#include <memory>

#include "ModelDirector.h"
#include "SceletonModelDirectorFactory.h"

enum class ModelType
{
    SceletonModel
};

class CreateDirectorCreator
{
public:
    static std::unique_ptr<ModelDirectorFactory> createSceletonDirectorCreator()
    {
        return std::make_unique<SceletonModelDirectorFactory>();
    }
};

class ModelDirectorSolution
{
    using CreateCreator = std::unique_ptr<ModelDirectorFactory>(*)();
    using CallBackMap = std::map<int, CreateCreator>;
public:
    ModelDirectorSolution() = default;

    ModelDirectorSolution(std::initializer_list<std::pair<int, CreateCreator>> list);
    bool registration(int id, CreateCreator createfun);
    bool check(int id) { return callbacks.erase(id) == 1; }

    std::unique_ptr<ModelDirector> create(ModelType type);
private:
    CallBackMap callbacks;
};

#endif // MODELDIRECTORSOLUTION_H
