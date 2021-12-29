#include <qtimer.h>

#include "Editor/KotorBuildPlanner/KotorBuildPlanner.hpp"

#include "Editor/KotorBuildPlanner/Equipment/Equipment.hpp"
#include "Editor/KotorBuildPlanner/FinalStats/FinalStats.hpp"
#include "Editor/KotorBuildPlanner/InitialCharacter/InitialCharacter.hpp"
#include "Editor/KotorBuildPlanner/LevelUpDecisions/LevelUpDecisions.hpp"
#include "Editor/KotorBuildPlanner/Menus/FileMenu.hpp"


namespace Editor
{

KotorBuildPlanner::KotorBuildPlanner(Framework::MainWindow* mainWindow)
: Workspace(mainWindow)
{
  //QTimer::singleShot(30, [this]()
  //{
  //  Update();
  //});
}

bool KotorBuildPlanner::Initialize()
{
  Framework::MainWindow* mainWindow = GetMainWindow();

  // Add menus
  AddMenu<FileMenu>(this);

  // Add widgets
  AddWidget<Equipment>(this);
  AddWidget<FinalStats>(this);
  AddWidget<InitialCharacter>(this);
  AddWidget<LevelUpDecisions>(this);

  return true;
}

void KotorBuildPlanner::Shutdown()
{
}

void KotorBuildPlanner::Update()
{
}

} // End of Editor namespace
