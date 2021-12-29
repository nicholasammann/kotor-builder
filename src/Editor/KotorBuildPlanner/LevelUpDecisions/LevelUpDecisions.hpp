#pragma once

#include <qcolordialog.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qlabel.h>

#include "Editor/Framework/Widget.hpp"

namespace Editor
{
class KotorBuildPlanner;

class LevelUpDecisions : public Framework::Widget
{
public:
  LevelUpDecisions(KotorBuildPlanner* workspace);

  virtual DockArea GetDefaultDockArea() const;

private:

  QVBoxLayout* mLayout;

  QLabel* mLabel;

};

} // End of Editor namespace

