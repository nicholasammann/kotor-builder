#include "Editor/Framework/Widget.hpp"

namespace Editor
{
namespace Framework
{

class Workspace;

class CollapsibleWidget : public Widget
{
public:
  CollapsibleWidget(Workspace* workspace);

  virtual DockArea GetDefaultDockArea() const;
  virtual DockArea GetAllowedDockAreas() const;

private:

};

} // End of Framework namespace
} // End of Editor namespace