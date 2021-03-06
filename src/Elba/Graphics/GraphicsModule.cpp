/**
* \file GraphicsModule.cpp
* \author Nicholas Ammann
* \date 2/24/2018
* \brief Class definition for GraphicsModule.
*/

#include <iostream>

#include "Elba/Engine.hpp"

#include "Elba/Graphics/GraphicsModule.hpp"

namespace Elba
{
GraphicsModule::GraphicsModule(Engine* engine)
  : Module(engine)
{
}

void GraphicsModule::RegisterForDraw(GlobalKey key, DrawCallback callback)
{
  mDrawCallbacks.emplace_back(std::make_pair(key, callback));
}

bool GraphicsModule::DeregisterForDraw(GlobalKey key)
{
  auto result = std::find_if(mDrawCallbacks.begin(), mDrawCallbacks.end(), 
  [key](const std::pair<GlobalKey, DrawCallback>& pair) 
  {
    if (key.ToStdString() == pair.first.ToStdString())
    {
      return true;
    }
    return false;
  });

  if (result != mDrawCallbacks.end())
  {
    mDrawCallbacks.erase(result);
    return true;
  }

  return false;
}

void GraphicsModule::RegisterForResize(GlobalKey key, ResizeCallback callback)
{
  mResizeCallbacks.emplace_back(std::make_pair(key, callback));
}

bool GraphicsModule::DeregisterForResize(GlobalKey key)
{
  auto result = std::find_if(mResizeCallbacks.begin(), mResizeCallbacks.end(),
    [key](const std::pair<GlobalKey, ResizeCallback>& pair)
  {
    if (key.ToStdString() == pair.first.ToStdString())
    {
      return true;
    }
    return false;
  });

  if (result != mResizeCallbacks.end())
  {
    mResizeCallbacks.erase(result);
    return true;
  }

  return false;
}

void GraphicsModule::OnResize(const ResizeEvent& event)
{
  mScreenWidth = static_cast<int>(event.newSize.x);
  mScreenHeight = static_cast<int>(event.newSize.y);

  for (auto cb : mResizeCallbacks)
  {
    cb.second(event);
  }
}

const PointLight& GraphicsModule::GetLight() const
{
  return mPointLight;
}

void GraphicsModule::SetLightIntensity(float value)
{
  mPointLight.SetIntensity(value);
}

} // End of Elba namespace
