#pragma once

#include "gameplay.h"

namespace HsEngine
{
    class FwBatchSprite
    {
    public:
        static FwBatchSprite* create (gameplay::SpriteBatch* spriteBatch,
            const unsigned int width, const unsigned int height, const gameplay::Vector4& imageUv);
        ~FwBatchSprite ();
        gameplay::SpriteBatch* GetBatch () const;
        void SetSize (const float width, const float height);
        void SetSize (const gameplay::Vector2 targetSize);
        void SetPosition (const float x, const float y);
        void SetPosition (const gameplay::Vector2 targetPosition);
        void SetColor (const float r, const float g, const float b, const float a);
        void SetColor (const gameplay::Vector4 color);
        void Draw ();
    private:
        explicit FwBatchSprite (gameplay::SpriteBatch* spriteBatch, const unsigned int width,
            const unsigned int height, const float uv1, const float uv2, const float uv3, const float uv4);
        gameplay::SpriteBatch* batch;
        const gameplay::Vector4 uv;
        gameplay::Vector2 size;
        gameplay::Vector2 position;
        gameplay::Vector4 spriteColor;
    };
}
