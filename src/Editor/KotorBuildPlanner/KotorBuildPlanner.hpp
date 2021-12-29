#pragma once

#include "Editor/Framework/Workspace.hpp"

namespace Editor
{

class KotorBuildPlanner : public Framework::Workspace
{
public:
  KotorBuildPlanner(Framework::MainWindow* mainWindow);

  bool Initialize() final;
  void Shutdown() final;

  void Update();

private:

};

} // End of Editor namespace
