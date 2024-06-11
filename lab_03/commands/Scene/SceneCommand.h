#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include "Command.h"
#include <vector>

class SceneCommand : public Command {};

class SceneRenderCommand : public SceneCommand
{
public:
    SceneRenderCommand() = default;
    void execute() override;
};

class SceneCreateCompositeCommand : public SceneCommand
{
public:
    SceneCreateCompositeCommand() = delete;
    explicit SceneCreateCompositeCommand(const std::vector<int> &ids);

    void execute() override;

private:
    std::vector<int> ids;
};

#endif // SCENECOMMAND_H
