#pragma once

#include <memory>

#include <qwidget.h>
#include <qdockwidget.h>

namespace Editor
{
namespace Framework
{

class Workspace;

class Widget : public QWidget
{
public:
  Widget(Workspace* workspace);

  enum DockArea
  {
    Left = Qt::LeftDockWidgetArea,
    Right = Qt::RightDockWidgetArea,
    Top = Qt::TopDockWidgetArea,
    Bottom = Qt::BottomDockWidgetArea,
    All = Qt::AllDockWidgetAreas
  };

  virtual DockArea GetDefaultDockArea() const = 0;
  virtual DockArea GetAllowedDockAreas() const;

  template <typename T>
  T* GetWorkspace() const;

protected:
  std::unique_ptr<QDockWidget> mDockWidget;

private:
  friend class Workspace;
  Workspace* mWorkspace;
};

template <typename T>
T* Widget::GetWorkspace() const
{
  return static_cast<T*>(mWorkspace);
}

} // End of Framework namespace
} // End of Editor namespace
