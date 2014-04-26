/* 
 * File:   main.cc
 * Author: johannes
 *
 * Created on 26. April 2014, 23:49
 */

#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "SpriteCutter.h"

using namespace std;
using namespace SpriteCutter;

void Initialize(int argc, char** argv);
void CleanUp();

/*
 * 
 */
int main(int argc, char** argv)
{
    Initialize(argc, argv);
    SaveSpriteList(CreateSpriteList(getSpriteSheet()));
    CleanUp();
    return 0;
}

void Initialize(int argc, char** argv)
{
    if(InitSpriteCutter("res/images/mario.bmp", "Mario", 6, 4,true) == -1)
    {
        exit(-1);
    }
}

void CleanUp()
{
    QuitSpriteCutter();
}

