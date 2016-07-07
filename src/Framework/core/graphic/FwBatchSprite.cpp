#include "FwBatchSprite.h"

namespace HsEngine
{
    FwBatchSprite* FwBatchSprite::create (gameplay::SpriteBatch* spriteBatch,
        const unsigned int width, const unsigned int height, const gameplay::Vector4& imageUv)
    {
        return new FwBatchSprite (spriteBatch, width, height, imageUv.x, imageUv.y, imageUv.z, imageUv.w);
    }

    FwBatchSprite::FwBatchSprite (gameplay::SpriteBatch* spriteBatch,
        const unsigned int width, const unsigned int height,
        const float uv1, const float uv2, const float uv3, const float uv4) :
        batch (spriteBatch),
        uv (gameplay::Vector4 (uv1, uv2, uv3, uv4)),
        size (gameplay::Vector2 (width, height)),
        position (gameplay::Vector2::zero ()),
        spriteColor (gameplay::Vector4::one ())
    {
    }

    FwBatchSprite::~FwBatchSprite ()
    {
        // ポインタの参照切るだけ
        batch = nullptr;
    }

    gameplay::SpriteBatch* FwBatchSprite::GetBatch () const
    {
        return batch;
    }

    void FwBatchSprite::SetSize (const float width, const float height)
    {
        size.x = width;
        size.y = height;
    }

    void FwBatchSprite::SetSize (const gameplay::Vector2 targetSize)
    {
        size.x = size.x;
        size.y = size.y;
    }

    void FwBatchSprite::SetPosition (const float x, const float y)
    {
        position.x = x;
        position.y = y;
    }

    void FwBatchSprite::SetPosition (const gameplay::Vector2 targetPosition)
    {
        position.x = targetPosition.x;
        position.y = targetPosition.y;
    }

    void FwBatchSprite::SetColor (const float r, const float g, const float b, const float a)
    {
        spriteColor.x = r;
        spriteColor.y = g;
        spriteColor.z = b;
        spriteColor.w = a;
    }

    void FwBatchSprite::SetColor (const gameplay::Vector4 color)
    {
        spriteColor.x = color.x;
        spriteColor.y = color.y;
        spriteColor.z = color.z;
        spriteColor.w = color.w;
    }

    void FwBatchSprite::Draw ()
    {
        batch->draw (position.x, position.y, 0.0f, size.x, size.y, uv.x, uv.y, uv.z, uv.w, spriteColor, true);
    }
}
