#pragma once

#include <glm/vec3.hpp>

#include "Elba/Core/Component.hpp"

#include "Elba/Graphics/OpenGL/OpenGLSubmesh.hpp"

namespace Elba
{

struct Pixel
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

class Transform;
class Model;

class ResizeHandler : public Component
{
public:
  ResizeHandler(Object* parent);

  void Initialize() final;

  void Resize(int screenWidth, int screenHeight);

  enum InterpolationMode
  {
    None,
    NearestNeighbor,
    Bilinear
  };

  void SetInterpolationMode(InterpolationMode mode);

private:
  Transform* mTransform;
  Model* mModel;

  InterpolationMode mInterpolationMode;

  std::vector<Pixel> mMasterImage;
  int mMasterWidth;
  int mMasterHeight;

  void OnTextureChange(const TextureChangeEvent& event);
  
  void Interpolate(int screenWidth, int screenHeight);
  unsigned char* NearestNeighborInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight);

  unsigned char* BilinearInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight);
  Pixel BilinearValue(int x, int y, float widthRatio, float heightRatio);

  int mScreenWidth;
  int mScreenHeight;
};

} // End of Elba namespace
