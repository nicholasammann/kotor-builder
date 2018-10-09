/**
* \file Shader.hpp
* \author Nicholas Ammann
* \date 3/10/2018
* \brief Class definition for Shader.
*/

#pragma once

#include <string>
#include <gl/glew.h>

namespace Elba
{
/**
* \brief Contains vertex and fragment shader information
*/
class OpenGLShaderProgram
{
public:
  /** 
  * \brief Constructor
  * \param name The arbitrary name we give this shader set.
  * \param vertPath The path to the vertex shader.
  * \param fragPath The path to the fragment shader.
  */
  OpenGLShaderProgram(const char* name, const char* vertPath, const char* fragPath);

  /**
  * \brief Set this as the currently active shader for OpenGL
  */
  void UseShaderProgram();

  // utility uniform functions
  void SetBool(const std::string& name, bool value);
  void SetInt(const std::string& name, int value);
  void SetFloat(const std::string& name, float value);

  unsigned int GetShaderProgram() const;
  unsigned int GetVertShader() const;
  unsigned int GetFragShader() const;

  std::string GetName();
  std::string GetVertPath();
  std::string GetFragPath();

private:
  std::string mName;
  std::string mVertPath;
  std::string mFragPath;

  unsigned int mShaderProgram;
  unsigned int mVertShader;
  unsigned int mFragShader;
};

} // End of Elba namespace