/**
* \file PhysicsModule.cpp
* \author Nicholas Ammann
* \date 2/24/2018
* \brief Member function definitions for PhysicsModule.
*/

#include "Engine.hpp"
#include "Physics/PhysicsModule.hpp"

namespace Elba
{
  PhysicsModule::PhysicsModule(Engine* engine) 
    : Module(engine)
    , mFactory(NewUnique<PhysicsFactory>(this))
  {
  }

  void PhysicsModule::Initialize()
  {
  }

  void PhysicsModule::Update()
  {
  }

  PhysicsFactory* PhysicsModule::GetFactory() const
  {
    return mFactory.get();
  }
}