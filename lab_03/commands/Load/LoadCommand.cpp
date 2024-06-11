#include "LoadCommand.h"


// #include "load/LoadManagerCreator.h"
#include "ManagerSolution.h"

LoadSceletonCommand::LoadSceletonCommand(const std::string& path)
{
    path_ = path;
}

void LoadSceletonCommand::execute()
{
    // auto loadManager = LoadManagerCreator().get();
    auto loadManager = ManagerSolution::getLoadManager();
    result = loadManager->loadSceletonModel(path_);
}

// int LoadSceletonCommand::getResult()
// {
//     return result;
// }
