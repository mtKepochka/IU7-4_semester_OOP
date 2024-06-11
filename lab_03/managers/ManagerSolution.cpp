#include "ManagerSolution.h"

#include "draw/DrawManagerCreator.h"
#include "camera/CameraManagerCreator.h"
#include "scene/SceneManagerCreator.h"
#include "transform/TransformManagerCreator.h"
#include "load/LoadManagerCreator.h"
#include "history/HistoryManagerCreator.h"

std::shared_ptr<DrawManager> ManagerSolution::getDrawManager()
{
    static auto manager = DrawManagerCreator().get();
    return manager;
}

std::shared_ptr<SceneManager> ManagerSolution::getSceneManager()
{
    static auto manager = SceneManagerCreator().get();
    return manager;
}

std::shared_ptr<CameraManager> ManagerSolution::getCameraManager()
{
    static auto manager = CameraManagerCreator().get();
    return manager;
}

std::shared_ptr<TransformManager> ManagerSolution::getTransformManager()
{
    static auto manager = TransformManagerCreator().get();
    return manager;
}

std::shared_ptr<LoadManager> ManagerSolution::getLoadManager()
{
    static auto manager = LoadManagerCreator().get();
    return manager;
}

std::shared_ptr<HistoryManager> ManagerSolution::getHistoryManager()
{
    static auto manager = HistoryManagerCreator().get();
    return manager;
}
