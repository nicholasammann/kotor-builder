#include <iostream>

#include "Editor/KotorBuildPlanner/InitialCharacter/InitialCharacter.hpp"
#include "Editor/KotorBuildPlanner/KotorBuildPlanner.hpp"

namespace Editor
{

InitialCharacter::InitialCharacter(KotorBuildPlanner* workspace)
  : Framework::Widget(workspace)
  , mLayout(new QVBoxLayout(this))
  , mLabel(new QLabel("Initial Character"))
{
  setWindowTitle("InitialCharacter");
  mLayout->addWidget(mLabel);
}

Framework::Widget::DockArea InitialCharacter::GetDefaultDockArea() const
{
  return DockArea::Top;
}

} // End of Editor namespace

