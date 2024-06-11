#include "HistoryCommand.h"

// #include "history/HistoryManagerCreator.h"
#include "ManagerSolution.h"

SaveStateCommand::SaveStateCommand(int id)
{
    objectId = id;
}
void SaveStateCommand::execute()
{
    // auto manager = HistoryManagerCreator().get();
    auto manager = ManagerSolution::getHistoryManager();
    manager->saveState(objectId);
}

RestoreStateCommand::RestoreStateCommand(int id)
{
    objectId = id;
}
void RestoreStateCommand::execute()
{
    // auto manager = HistoryManagerCreator().get();
    auto manager = ManagerSolution::getHistoryManager();
    manager->getPrevState(objectId);
}

