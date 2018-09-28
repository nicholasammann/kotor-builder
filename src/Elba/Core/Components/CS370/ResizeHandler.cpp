#include <cmath>

#include "Elba/Core/Object.hpp"
#include "Elba/Core/Components/CS370/ResizeHandler.hpp"

#include "Elba/Core/Components/Model.hpp"
#include "Elba/Core/Components/Transform.hpp"

#include "Elba/Graphics/OpenGL/OpenGLMesh.hpp"
#include "Elba/Graphics/OpenGL/OpenGLTexture.hpp"

namespace Elba
{

ResizeHandler::ResizeHandler(Object* parent)
  : Component(parent)
  , mTransform(nullptr)
  , mModel(nullptr)
  , mInterpolationMode(InterpolationMode::None)
  , mMasterWidth(800)
  , mMasterHeight(600)
  , mScreenWidth(800)
  , mScreenHeight(600)
{
}

void ResizeHandler::Initialize()
{
  mTransform = GetParent()->GetComponent<Elba::Transform>();
  mModel = GetParent()->GetComponent<Elba::Model>();

  OpenGLMesh* mesh = static_cast<OpenGLMesh*>(mModel->GetMesh());
  auto sbm_it = mesh->GetSubmeshes().begin();

  if (sbm_it != mesh->GetSubmeshes().end())
  {
    // Register to be notified when the texture on the submesh changes
    sbm_it->RegisterForTextureChange(GlobalKey(), [this](const TextureChangeEvent& event)
    {
      this->OnTextureChange(event);
    });
  }
}

void ResizeHandler::Resize(int screenWidth, int screenHeight)
{
  // Store width and height for user changes interpolation
  mScreenWidth = screenWidth;
  mScreenHeight = screenHeight;

  // Resize image to match screen size
  mTransform->SetWorldScale(glm::vec3(static_cast<float>(screenWidth), 1.0f, static_cast<float>(screenHeight)));

  // Perform interpolation
  Interpolate(screenWidth, screenHeight);
}

void ResizeHandler::SetInterpolationMode(InterpolationMode mode)
{
  mInterpolationMode = mode;

  // Perform interpolation again with different mode
  Interpolate(mScreenWidth, mScreenHeight);
}

void ResizeHandler::OnTextureChange(const TextureChangeEvent& event)
{
  mMasterWidth = event.newTexture->GetWidth();
  mMasterHeight = event.newTexture->GetHeight();

  // delete old master image
  mMasterImage.clear();

  // allocate new master image

  for (int y = 0; y < mMasterHeight; ++y)
  {
    for (int x = 0; x < mMasterWidth; ++x)
    {
      int ind = y * mMasterWidth * 3 + x * 3;
      
      Pixel pixel;
      pixel.r = event.newTexture->GetImage()[ind];
      pixel.g = event.newTexture->GetImage()[ind + 1];
      pixel.b = event.newTexture->GetImage()[ind + 2];
      mMasterImage.emplace_back(pixel);
    }
  }
}

void ResizeHandler::Interpolate(int screenWidth, int screenHeight)
{
  OpenGLMesh* mesh = static_cast<OpenGLMesh*>(mModel->GetMesh());

  auto it = mesh->GetSubmeshes().begin();

  if (it != mesh->GetSubmeshes().end())
  {
    OpenGLTexture* texture = it->GetDiffuseTexture();
    unsigned char* image = texture->GetImage();

    // do some form of interpolation
    switch (mInterpolationMode)
    {
      case InterpolationMode::NearestNeighbor:
      {
        image = NearestNeighborInterpolation(texture, screenWidth, screenHeight);
        break;
      }

      case InterpolationMode::Bilinear:
      {
        image = BilinearInterpolation(texture, screenWidth, screenHeight);
        break;
      }

      case InterpolationMode::None:
      {
        // EVERYTHING IS AWFUL NO INTERPOLATION OH MY GOD
        return;
      }
    }

    // recreate the opengl texture
    //texture->DeleteTexture();
    texture->SetImage(image, screenWidth, screenHeight);
    texture->GenerateTexture();
  }
}

unsigned char* ResizeHandler::NearestNeighborInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight)
{
  int stride = screenWidth * 3;

  unsigned char* newImage = new unsigned char[stride * screenHeight];

  for (int y = 0; y < screenHeight; ++y)
  {
    for (int x = 0; x < stride; ++x)
    {
      // nearest neighbor interpolation
      
      // find the nearest point and make it that color
      
    }
  }

  return newImage;
}

unsigned char* ResizeHandler::BilinearInterpolation(OpenGLTexture* texture, int screenWidth, int screenHeight)
{
  int stride = screenWidth * 3;

  float widthRatio = static_cast<float>(mMasterWidth) / static_cast<float>(screenWidth);
  float heightRatio = static_cast<float>(mMasterHeight) / static_cast<float>(screenHeight);

  unsigned char* newImage = new unsigned char[stride * (screenHeight + 1)];

  for (int y = 0; y < screenHeight; ++y)
  {
    for (int x = 0; x < screenWidth; ++x)
    {
      // bilinear interpolation
      Pixel pixel = BilinearValue(x, y, widthRatio, heightRatio);

      unsigned int index = y * stride + x * 3;

      newImage[index] = pixel.r;
      newImage[index + 1] = pixel.g;
      newImage[index + 2] = pixel.b;
    }
  }

  return newImage;
}

Pixel ResizeHandler::BilinearValue(int x, int y, float widthRatio, float heightRatio)
{
  Pixel result;

  float tX = x * widthRatio;
  float tY = y * heightRatio;

  int x1 = floor(tX);
  int x2 = floor(tX + 1);
  
  if (x2 >= mMasterWidth)
  {
    x2 = 0;
  }

  int y1 = floor(tY);
  int y2 = floor(tY + 1);

  if (y2 >= mMasterHeight)
  {
    y2 = 0;
  }

  // alpha = (x - x1) / (x2 - x1)
  // beta = (y - y1) / (y2 - y1)
  // f(x, y1) = (1 - alpha) * f(x1, y1) + alpha * f(x2, y1)
  // f(x, y2) = (1 - alpha) * f(x1, y2) + alpha * f(x2, y2)
  // f(x,y) = (1 - beta) * f(x, y1) + beta * f(x, y2)

  float alpha = (tX - x1) / (x2 - x1);
  float beta = (tY - y1) / (y2 - y1);
  float fxy1 = (1.0f - alpha) * mMasterImage[y1 * mMasterWidth + x1].r + alpha * mMasterImage[y1 * mMasterWidth + x2].r;
  float fxy2 = (1.0f - alpha) * mMasterImage[y2 * mMasterWidth + x1].r + alpha * mMasterImage[y2 * mMasterWidth + x2].r;
  result.r = (1.0f - beta) * fxy1 + beta * fxy2;

  fxy1 = (1.0f - alpha) * mMasterImage[y1 * mMasterWidth + x1].g + alpha * mMasterImage[y1 * mMasterWidth + x2].g;
  fxy2 = (1.0f - alpha) * mMasterImage[y2 * mMasterWidth + x1].g + alpha * mMasterImage[y2 * mMasterWidth + x2].g;
  result.g = (1.0f - beta) * fxy1 + beta * fxy2;

  fxy1 = (1.0f - alpha) * mMasterImage[y1 * mMasterWidth + x1].b + alpha * mMasterImage[y1 * mMasterWidth + x2].b;
  fxy2 = (1.0f - alpha) * mMasterImage[y2 * mMasterWidth + x1].b + alpha * mMasterImage[y2 * mMasterWidth + x2].b;
  result.b = (1.0f - beta) * fxy1 + beta * fxy2;

  return result;
}

} // End of Elba namespace

