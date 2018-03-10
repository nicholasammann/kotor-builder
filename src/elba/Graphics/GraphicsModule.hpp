/**
* \file GraphicsModule.hpp
* \author Nicholas Ammann
* \date 2/24/2018
* \brief Class definition for GraphicsModule.
*/

#pragma once

#include "Framework/Module.hpp"

namespace Elba
{
  class Engine;

  /**
  * \brief Module for the graphics system. Manages rendering.
  */
  class GraphicsModule : public Module
  {
  public:
    /**
    * \brief Constructor
    * \param engine The engine, which owns all modules.
    */
    GraphicsModule(Engine* engine);

    /**
    * \brief Initialize function called by Engine. Initializes GraphicsModule.
    */
    void Initialize() override;

    /**
    * \brief Update function called by Engine. Updates graphics.
    */
    void Update() override;

  };

}