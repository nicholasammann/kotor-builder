/**
* \file Module.hpp
* \author Nicholas Ammann
* \date 2/24/2018
* \brief Class definition for Module.
*/

#pragma once

namespace Elba
{
class Engine;

/**
* \brief Base class for systems that comprise the engine.
*/
class Module
{
public:
  /**
  * \brief Constructor
  * \param engine The engine, which owns all modules.
  */
  Module(Engine* engine);

  /**
  * \brief Initialize function that Engine will call on each module.
  */
  virtual void Initialize() = 0;

  /**
  * \brief Update function that Engine will call on each module.
  */
  virtual void Update(double dt) = 0;

  /**
  * \brief Getter for the engine.
  * \return A pointer to the engine.
  */
  Engine* GetEngine() const;

private:
  Engine * mEngine;
};
} // End of Elba namespace
