/**
* \file CoreTests.cpp
* \author Nicholas Ammann
* \date 3/10/2018
* \brief Function definitions for CoreModule test functions.
*/

#include <iostream>

#include "Utilities/GlobalKey.hpp"

#include "Tests/CoreTests.hpp"
#include "Tests/TestHelpers.hpp"

namespace Elba
{
  namespace Test
  {
    namespace Core
    {
      void RunAllTests(CoreModule* coreModule)
      {
        // Creating top level objects (parent is root object/game world)
        CreateObjects1(coreModule);
        CreateObjects2(coreModule);
        CreateObjects3(coreModule);
        CreateObjects4(coreModule);
      }

      void CreateObjects1(CoreModule* coreModule)
      {
        PrintTestHeader("Create Objects 1");
        Object* world = coreModule->GetGameWorld();
        CreateObjects(world, 10);
        PrintTestFooter();
      }

      void CreateObjects2(CoreModule* coreModule)
      {
        PrintTestHeader("Create Objects 2");
        Object* world = coreModule->GetGameWorld();
        CreateObjects(world, 100);
        PrintTestFooter();
      }

      void CreateObjects3(CoreModule* coreModule)
      {
        PrintTestHeader("Create Objects 3");
        Object* world = coreModule->GetGameWorld();
        CreateObjects(world, 1000);
        PrintTestFooter();
      }

      void CreateObjects4(CoreModule* coreModule)
      {
        PrintTestHeader("Create Objects 4");
        Object* world = coreModule->GetGameWorld();
        CreateObjects(world, 10000);
        PrintTestFooter();
      }

      void CreateObjects(Object* object, int numObjects)
      {
        for (int i = 0; i < numObjects; i++)
        {
          Object* obj = object->CreateChild();

          GlobalKey guid = obj->GetGuid();

          std::string guidStr = guid.ToStdString();

          std::cout << "Object " << i << " created.  ID: " << guidStr << std::endl;
        }
      }
    }
  }
}