#include <qfiledialog.h>

#include "Editor/Framework/Workspace.hpp"
#include "Editor/KotorBuildPlanner/Menus/FileMenu.hpp"


namespace Editor
{

FileMenu::FileMenu(Framework::Workspace* workspace)
  : Framework::Menu("File", workspace)
{
}

} // End of Editor namespace

