#include "LoadManager.h"

#include "LoadException.h"
#include "ManagerSolution.h"
#include "ModelDirectorSolution.h"

int LoadManager::loadSceletonModel(const std::string &path)
{
    SourceSolution source_solution;
    BuilderSolution builder_solution;
    ModelDirectorSolution director_solution;

    auto sceneManager = ManagerSolution::getSceneManager();

    auto scene = sceneManager->getScene();
    source_solution.registration(".stdvec", &CreateSolutionCreator::createVertexCreator);
    builder_solution.registration(".stdvec", &CreateBuilderCreator::createVertexCreator);
                           // std::unique_ptr<ModelSourceFactory>(new VertexEdgeSourceFactory())
    /*std::make_unique<VertexEdgeSourceFactory>()*/
    source_solution.registration(".listvec", &CreateSolutionCreator::createListCreator);
    builder_solution.registration(".listvec", &CreateBuilderCreator::createListCreator);
                           // std::unique_ptr<ModelSourceFactory>(new AdjacencyListSourceFactory())
    /*std::make_unique<AdjacencyListSourceFactory>()*/

    auto source = source_solution.create(path);
    // auto source = SourceSolution::create(path);

    if (source == nullptr)
        throw WrongSourceError(__FILE__, __LINE__, "Unknown source type");

    auto builder = builder_solution.create(path, source);

    director_solution.registration(static_cast<int>(ModelType::SceletonModel), &CreateDirectorCreator::createSceletonDirectorCreator);

    auto director = director_solution.create(ModelType::SceletonModel);

    return scene->addObject(director->create(builder));
}
