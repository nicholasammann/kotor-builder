#include <iostream>

#include "Editor/KotorBuildPlanner/FinalStats/FinalStats.hpp"
#include "Editor/KotorBuildPlanner/KotorBuildPlanner.hpp"

namespace Editor
{

FinalStats::FinalStats(KotorBuildPlanner* workspace)
  : Framework::Widget(workspace)
  , mLayout(new QVBoxLayout(this))
  , mLabel(new QLabel("Final Stats"))
{
  setWindowTitle("FinalStats");
  mLayout->addWidget(mLabel);
}

Framework::Widget::DockArea FinalStats::GetDefaultDockArea() const
{
  return DockArea::Top;
}

} // End of Editor namespace

