#include <iostream>

#include "Editor/KotorBuildPlanner/LevelUpDecisions/LevelUpDecisions.hpp"
#include "Editor/KotorBuildPlanner/KotorBuildPlanner.hpp"

namespace Editor
{

LevelUpDecisions::LevelUpDecisions(KotorBuildPlanner* workspace)
  : Framework::Widget(workspace)
  , mLayout(new QVBoxLayout(this))
  , mLabel(new QLabel("Level Up Decisions"))
{
  setWindowTitle("LevelUpDecisions");
  mLayout->addWidget(mLabel);
}

Framework::Widget::DockArea LevelUpDecisions::GetDefaultDockArea() const
{
  return DockArea::Top;
}

} // End of Editor namespace

