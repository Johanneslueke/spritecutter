/* 
 * File:   SpriteCutter.h
 * Author: johannes
 *
 * Created on 25. April 2014, 12:00
 */

/***************************************************************************
 *   Copyright (c) 2014-2015 Johannes Schauerte genannt Lüke
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/

#ifndef SPRITECUTTER_H
#define	SPRITECUTTER_H

#include <SDL2/SDL.h>
#include <string>
#include <sstream>
#include <vector>

template<typename t> std::string ToString(t num)
{
    std::stringstream stream;
    stream << num;
    return stream.str();
}

namespace SpriteCutter
{
    typedef std::vector<SDL_Surface*> SpriteList;
    
    
    
    int InitSpriteCutter(const std::string& Sheet,const std::string& spriteName,int spriteW,int spriteH,bool flag = false);
    void QuitSpriteCutter();
    SpriteList CreateSpriteList(SDL_Surface*);
    void       SaveSpriteList(SpriteList);
    
    SDL_Surface* CutSprite(SDL_Surface* source, SDL_Surface* destination, const SDL_Rect*);
    SDL_Surface* CutSprite(SDL_Surface* source, SDL_Surface* destination, int w, int h, int x, int y);
    SDL_Surface* CopySurface(SDL_Surface*);

    unsigned calcRowsOfSheet(SDL_Surface*, unsigned SpriteWidth);
    unsigned calcColsOfSheet(SDL_Surface*, unsigned SpriteHeight);
    unsigned calcWidthOfSprite(SDL_Surface*, unsigned Cols);
    unsigned calcHeightOfSprite(SDL_Surface*, unsigned Rows);
    
    unsigned getRowsOfSheet();
    unsigned getColsOfSheet();
    unsigned getWidthOfSprite();
    unsigned getHeightOfSprite();
    unsigned getSizeOfSheet();
    SDL_Rect* getSpriteFrame();
    SDL_Surface* getSpriteSheet();
    std::string getSpriteName();
    
    void setRowsOfSheet(unsigned);
    void setColsOfSheet(unsigned);
    void setWidthOfSprite(unsigned);
    void setHeightOfSprite(unsigned);
    void setSpriteFrame(SDL_Rect*);
    void setSpriteFrame(unsigned,unsigned);
    void setSpriteSheet(SDL_Surface*);
    void setSpriteName(const std::string&);
    
    
}

#endif	/* SPRITECUTTER_H */

