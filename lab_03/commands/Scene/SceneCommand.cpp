#include "SceneCommand.h"

// #include "draw/DrawManagerCreator.h"
#include "ManagerSolution.h"

void SceneRenderCommand::execute()
{
    // auto manager = DrawManagerCreator().get();
    auto manager = ManagerSolution::getDrawManager();
    manager->drawScene();
}

SceneCreateCompositeCommand::SceneCreateCompositeCommand(const std::vector<int> &ids)
{
    this->ids = std::move(ids);
}

void SceneCreateCompositeCommand::execute()
{
    auto manager = ManagerSolution::getSceneManager();
    manager->createComposite(ids);
}
