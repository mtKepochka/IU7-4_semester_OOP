#include "BuilderSolution.h"

#include <filesystem>

// #include "AdjacencyListSceletonModelBuilderFactory.h"
// #include "VertexEdgeSceletonModelBuilderFactory.h"

#include <QDebug>

BuilderSolution::BuilderSolution(std::initializer_list<std::pair<std::string, CreateCreator>> list)
{
    for (auto elem : list)
        this->registration(elem.first, elem.second);
}

bool BuilderSolution::registration(std::string ext, CreateCreator createfun)
{
    // extensions[ext] = ext_size;
    // ext_size++;
    return callbacks.insert(CallBackMap::value_type(ext, createfun)).second;
}

std::shared_ptr<ModelBuilder> BuilderSolution::create(const std::string &path, std::shared_ptr<ModelSource> source)
{
    std::filesystem::path p(path);
    std::string ext = p.extension().string();

    // size_t id = extensions[ext];

    CallBackMap::const_iterator it = callbacks.find(ext);

    if (it == callbacks.end())
    {
        return nullptr;
    }

    auto builderFactory = it->second();

    return builderFactory->create(source);

    // if (ext == ".listvec")
    // {
    //     auto builderFactory = std::make_unique<AdjacencyListSceletonModelBuilderFactory>();
    //     return builderFactory->create(source);
    // }

    // auto builderFactory = std::make_unique<VertexEdgeSceletonModelBuilderFactory>();
    // return builderFactory->create(source);
}
