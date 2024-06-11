#ifndef BUILDERSOLUTION_H
#define BUILDERSOLUTION_H

#include <memory>

#include "ModelBuilder.h"
#include "SceletonModelBuilderFactory.h"
# include <initializer_list>
# include <memory>
# include <map>

#include "AdjacencyListSceletonModelBuilderFactory.h"
#include "VertexEdgeSceletonModelBuilderFactory.h"
class CreateBuilderCreator
{
public:
    static std::unique_ptr<SceletonModelBuilderFactory> createVertexCreator()
    {
        return std::make_unique<VertexEdgeSceletonModelBuilderFactory>();
    }
    static std::unique_ptr<SceletonModelBuilderFactory> createListCreator()
    {
        return std::make_unique<AdjacencyListSceletonModelBuilderFactory>();
    }
};

class BuilderSolution
{
using CreateCreator = std::unique_ptr<SceletonModelBuilderFactory>(*)();
    using CallBackMap = std::map<std::string, CreateCreator>;
public:
    BuilderSolution() = default;

    BuilderSolution(std::initializer_list<std::pair<std::string, CreateCreator>> list);
    bool registration(std::string ext, CreateCreator createfun);
    bool check(std::string id) { return callbacks.erase(id) == 1; }

    std::shared_ptr<ModelBuilder> create(const std::string &path, std::shared_ptr<ModelSource> source);
private:
    CallBackMap callbacks;
    // std::map<std::string, size_t> extensions;
    // size_t ext_size = 0;
};

#endif // BUILDERSOLUTION_H
