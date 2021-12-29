#include <iostream>

#include "Editor/KotorBuildPlanner/Equipment/Equipment.hpp"
#include "Editor/KotorBuildPlanner/KotorBuildPlanner.hpp"

namespace Editor
{

Equipment::Equipment(KotorBuildPlanner* workspace)
  : Framework::Widget(workspace)
  , mLayout(new QVBoxLayout(this))
  , mLabel(new QLabel("Equipment"))
{
  setWindowTitle("Equipment");
  mLayout->addWidget(mLabel);
}

Framework::Widget::DockArea Equipment::GetDefaultDockArea() const
{
  return DockArea::Top;
}

} // End of Editor namespace

