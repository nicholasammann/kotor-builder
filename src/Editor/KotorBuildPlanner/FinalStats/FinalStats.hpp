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

class FinalStats : public Framework::Widget
{
public:
  FinalStats(KotorBuildPlanner* workspace);

  virtual DockArea GetDefaultDockArea() const;

private:

  QVBoxLayout* mLayout;

  QLabel* mLabel;

};

} // End of Editor namespace

