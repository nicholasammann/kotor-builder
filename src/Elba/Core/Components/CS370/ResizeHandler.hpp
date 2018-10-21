#pragma once

#include <glm/vec3.hpp>

#include "Elba/Core/Component.hpp"

#include "Elba/Graphics/OpenGL/OpenGLSubmesh.hpp"
#include "Elba/Graphics/OpenGL/OpenGLTexture.hpp"

namespace Elba
{

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

  InterpolationMode GetInterpolationMode() const;

  void NearestNeighborInterpolation(std::vector<Pixel>& source, int srcWidth, int srcHeight, 
                                    std::vector<Pixel>& result, int targetWidth, int targetHeight);
  void BilinearInterpolation(std::vector<Pixel>& source, int srcWidth, int srcHeight, 
                             std::vector<Pixel>& result, int targetWidth, int targetHeight);

  void SetImage(const std::vector<Pixel>& image, int width, int height);

private:
  Transform* mTransform;
  Model* mModel;

  InterpolationMode mInterpolationMode;

  std::vector<Pixel> mMasterImage;
  int mMasterWidth;
  int mMasterHeight;

  void OnTextureChange(const TextureChangeEvent& event);
  
  void Interpolate(int screenWidth, int screenHeight);
  void NearestNeighborInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight, std::vector<Pixel>& result);
  Pixel NearestNeighborValue(int x, int y, int width, int height, float widthRatio, float heightRatio, std::vector<Pixel>& src);

  void BilinearInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight, std::vector<Pixel>& result);
  Pixel BilinearValue(int x, int y, int width, int height, float widthRatio, float heightRatio, std::vector<Pixel>& src);

  int mScreenWidth;
  int mScreenHeight;
};

} // End of Elba namespace
