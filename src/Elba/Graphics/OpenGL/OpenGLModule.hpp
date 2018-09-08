#pragma once

#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Elba/Graphics/GraphicsModule.hpp"

namespace Elba
{

/**
* \brief OpenGL implementation of graphics module.
*/
class OpenGLModule : public GraphicsModule
{
public:
  /**
  * \brief Constructor
  * \param engine The engine, which owns all modules.
  */
  OpenGLModule(Engine* engine);

  /**
  * \brief Initialize function called by Engine. Initializes GraphicsModule.
  */
  void Initialize() final;

  /**
  * \brief Update function called by Engine. Updates graphics.
  */
  void Update() final;

  /**
  * \brief Window/context agnostic rendering calls.
  */
  void Render() final;

private:
  GLFWwindow * mWindow;

};

} // End of Elba namespace


