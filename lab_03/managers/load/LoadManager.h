#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>

#include "SourceSolution.h"
#include "BuilderSolution.h"
#include <BaseManager.h>

class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() override = default;
    LoadManager(const LoadManager &) = delete;

    int loadSceletonModel(const std::string &path);
};

#endif // LOADMANAGER_H
