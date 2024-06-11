#ifndef SOURCESOLUTION_H
#define SOURCESOLUTION_H

#include <memory>

#include "ModelSource.h"
#include "ModelSourceFactory.h"
# include <initializer_list>
# include <memory>
# include <map>

#include "AdjacencyListSourceFactory.h"
#include "VertexEdgeSourceFactory.h"
class CreateSolutionCreator
{
public:
    static std::unique_ptr<ModelSourceFactory> createVertexCreator()
    {
        return std::make_unique<VertexEdgeSourceFactory>();
    }
    static std::unique_ptr<ModelSourceFactory> createListCreator()
    {
        return std::make_unique<AdjacencyListSourceFactory>();
    }
};

class SourceSolution
{
    using CreateCreator = std::unique_ptr<ModelSourceFactory>(*)();
    using CallBackMap = std::map<std::string, CreateCreator>;
public:
    SourceSolution() = default;

    SourceSolution(std::initializer_list<std::pair<std::string, CreateCreator>> list);
    bool registration(std::string ext, CreateCreator createfun);
    bool check(std::string id) { return callbacks.erase(id) == 1; }

    std::shared_ptr<ModelSource> create(const std::string &path);
private:
    CallBackMap callbacks;
    // std::map<std::string, size_t> extensions;
    // size_t ext_size = 0;
};

#endif // SOURCESOLUTION_H
