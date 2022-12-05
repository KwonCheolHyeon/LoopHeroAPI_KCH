#include "chTile.h"
#include "chImage.h"

namespace ch
{
    Tile::Tile(Vector2 pos)
        : GameObject(pos)
        , mAtlas(nullptr)
        , mY(-1)
        , mX(-1)
    {
    }

    Tile::~Tile()
    {
    }

    void Tile::Initiailize(Image* atlas, int index)
    {
        mIndex = index;
        if (atlas == nullptr || index < 0)
            return;

        mAtlas = atlas;

        int maxColumn = mAtlas->GetWidth() / TILE_SIZE;
        int maxRow = mAtlas->GetHeight() / TILE_SIZE;

        mY = index / maxColumn;
        mX = index % maxColumn;
    }

    void Tile::Tick()
    {
    }

    void Tile::Render(HDC hdc)
    {
        if (mAtlas == nullptr)
            return;

        Vector2 renderPos = Camera::CalculatePos(GetPos());

        int tileImgY = mY * TILE_SIZE;
        int tileImgX = mX * TILE_SIZE;

        TransparentBlt(hdc, renderPos.x, renderPos.y
            , TILE_SIZE * TILE_SCALE, TILE_SIZE * TILE_SCALE
            , mAtlas->GetDC(), tileImgX, tileImgY
            , TILE_SIZE, TILE_SIZE
            , RGB(255, 0, 255));
    }

    void Tile::SetIndex(UINT index)
    {
        mIndex = index;

        int maxColumn = mAtlas->GetWidth() / TILE_SIZE;
        int maxRow = mAtlas->GetHeight() / TILE_SIZE;

        mY = index / maxColumn;
        mX = index % maxColumn;
    }

}