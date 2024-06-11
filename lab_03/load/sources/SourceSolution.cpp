#include "SourceSolution.h"

#include <filesystem>

// #include "AdjacencyListSourceFactory.h"
// #include "VertexEdgeSourceFactory.h"

SourceSolution::SourceSolution(std::initializer_list<std::pair<std::string, CreateCreator>> list)
{
    for (auto elem : list)
        this->registration(elem.first, elem.second);
}

bool SourceSolution::registration(std::string ext, CreateCreator createfun)
{
    // extensions[ext] = ext_size;
    // ext_size++;
    return callbacks.insert(CallBackMap::value_type(ext, createfun)).second;
}

std::shared_ptr<ModelSource> SourceSolution::create(const std::string &path)
{
    std::filesystem::path p(path);
    std::string ext = p.extension().string();

    // size_t id = extensions[ext];

    CallBackMap::const_iterator it = callbacks.find(ext);

    if (it == callbacks.end())
    {
        return nullptr;
    }

    auto sourceFactory = it->second();

    return sourceFactory->create(path);

    // if (ext == ".stdvec")
    // {
    //     auto sourceFactory = std::make_unique<VertexEdgeSourceFactory>();
    //     return sourceFactory->create(path);
    // }
    // else if (ext == ".listvec")
    // {
    //      auto sourceFactory = std::make_unique<AdjacencyListSourceFactory>();
    //     return sourceFactory->create(path);
    // }

    // return nullptr;
}
