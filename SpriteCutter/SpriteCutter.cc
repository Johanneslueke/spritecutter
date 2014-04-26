#include "SpriteCutter.h"

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace SpriteCutter
{

    static SDL_Surface* SpriteSheet = nullptr;
    static SDL_Rect*    SpriteFrame = nullptr;
    static std::string  SpriteName;
    static unsigned     SpriteRows = 0,SpriteCols = 0;
    
    int InitSpriteCutter(const std::string& Sheet,const std::string& spriteName, int spriteW, int spriteH, bool flag)
    {
        if(SDL_Init(SDL_INIT_VIDEO) == -1)
        {
            std::cerr<<SDL_GetError();
            return -1;
        }
        
        SpriteSheet = SDL_LoadBMP(Sheet.c_str());
        if (SpriteSheet == nullptr)
        {
            std::cerr << IMG_GetError();
            return -1;
        }
        
        SpriteFrame = new SDL_Rect;
        if (SpriteFrame != nullptr)
        {
            if (flag)
            {
                SpriteFrame->w = calcWidthOfSprite(getSpriteSheet(), spriteW);
                SpriteFrame->h = calcHeightOfSprite(getSpriteSheet(),spriteH);
                SpriteFrame->x = 0;
                SpriteFrame->y = 0;
            }
            else
            {
                SpriteFrame->w = spriteW;
                SpriteFrame->h = spriteH;
                SpriteFrame->x = 0;
                SpriteFrame->y = 0;
            }
        } else
        {
            std::cerr << "Not enough memory!!!";
            return -1;
        }

        setRowsOfSheet(
                calcRowsOfSheet(getSpriteSheet(), spriteW));

        setColsOfSheet(
                calcColsOfSheet(getSpriteSheet(), spriteH));
        
        setSpriteName(spriteName);
    }
    
    void QuitSpriteCutter()
    {
        if(getSpriteSheet() != nullptr)
            SDL_FreeSurface(getSpriteSheet());
        delete SpriteFrame;
        
        atexit(SDL_Quit);
    }

    SDL_Surface* CutSprite(SDL_Surface* source, SDL_Surface* destination, const SDL_Rect* frame)
    {
        SDL_BlitSurface(source, frame, destination, nullptr);
        return destination;
    }

    SDL_Surface* CutSprite(SDL_Surface* source, SDL_Surface* destination, int w, int h, int x, int y)
    {
        SDL_Rect* frame;
        frame->h = h;
        frame->w = w;
        frame->x = x;
        frame->y = y;
        return CutSprite(source, destination, frame);
    }

    SDL_Surface* CopySurface(SDL_Surface* source)
    {
        return SDL_CreateRGBSurfaceFrom(source->pixels, source->w, source->h, 32, source->pitch,
                0, 0, 0, SDL_ALPHA_OPAQUE);
    }

    void SaveSpriteList(SpriteList Sprites)
    {
        for (int i = 0; i < getSizeOfSheet()-1; ++i)
        {
            std::string name = getSpriteName()+"_" + ToString(i) + ".bmp";
            SDL_SaveBMP(Sprites[i], name.c_str());
        }
    }

    SpriteList CreateSpriteList(SDL_Surface*)
    {
        SpriteList Sprites;
//        Sprites.reserve(24);

        SDL_Rect SpriteFrame;
        SpriteFrame.w = getWidthOfSprite();
        SpriteFrame.h = getHeightOfSprite();

        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 6; x++)
            {
                SDL_Surface* Destination = SDL_CreateRGBSurface(0, getWidthOfSprite(), getHeightOfSprite(), 32, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SpriteFrame.x = x * getWidthOfSprite();
                SpriteFrame.y = y * getHeightOfSprite();
                Sprites.push_back(CutSprite(getSpriteSheet(), Destination, &SpriteFrame));
            }
        }

//        Sprites.shrink_to_fit();
        return Sprites;
    }

    unsigned calcColsOfSheet(SDL_Surface* Sheet, unsigned SpriteWidth)
    {
        return Sheet->w / SpriteWidth;
    }

    unsigned calcRowsOfSheet(SDL_Surface* Sheet, unsigned SpriteHeight)
    {
        return Sheet->h / SpriteHeight;
    }

    unsigned calcHeightOfSprite(SDL_Surface* Sheet, unsigned Rows)
    {
        return Sheet->h / Rows;
    }

    unsigned calcWidthOfSprite(SDL_Surface* Sheet, unsigned Cols)
    {
        return Sheet->w / Cols;
    }

    unsigned getRowsOfSheet()
    {
        return SpriteRows;
    }

    unsigned getColsOfSheet()
    {
        return SpriteCols;
    }

    unsigned getWidthOfSprite()
    {
        return SpriteFrame->w;
    }

    unsigned getHeightOfSprite()
    {
        return SpriteFrame->h;
    }

    unsigned getSizeOfSheet()
    {
        return getRowsOfSheet() * getColsOfSheet();
    }

    SDL_Rect* getSpriteFrame()
    {
        return SpriteFrame;
    }

    SDL_Surface* getSpriteSheet()
    {
        return SpriteSheet;
    }
    
    std::string getSpriteName()
    {
        return SpriteName;
    }

    void setRowsOfSheet(unsigned rows)
    {
        SpriteRows = rows;
    }

    void setColsOfSheet(unsigned cols)
    {
        SpriteCols = cols;
    }

    void setWidthOfSprite(unsigned width)
    {
        SpriteFrame->w = width;
    }

    void setHeightOfSprite(unsigned height)
    {
        SpriteFrame->h = height;
    }

    void setSpriteFrame(SDL_Rect* frame)
    {
        SpriteFrame = frame;
    }

    void setSpriteFrame(unsigned w, unsigned h)
    {
        SpriteFrame->w = w;
        SpriteFrame->h = h;
    }
    
    void setSpriteName(const std::string& name)
    {
        SpriteName = name;
    }
}
