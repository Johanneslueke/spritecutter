/* 
 * File:   main.cc
 * Author: johannes
 *
 * Created on 26. April 2014, 23:49
 */

#include <cstdlib>

#include "SpriteCutter.h"

using namespace std;
using namespace SpriteCutter;


/*
 * 
 */
int main(int argc, char** argv)
{
    std::string Flags[argc];
    for(int i = 0; i < argc; i++)
    {
        Flags[i] = argv[i];
    }
    auto Test = [](const std::string& flag)
    {
        if(flag == "true")
            return true;
        if(flag == "false")
            return false;
        else
            throw "Last Parameter is some kind of wrong\n";
    };
    
    /***************************************************************************/
    if(InitSpriteCutter(Flags[1], Flags[2], atoi(Flags[3].c_str()), atoi(Flags[4].c_str()),Test(Flags[5])) == -1)
    {
        exit(-1);
    }
    /***************************************************************************/
    SaveSpriteList(CreateSpriteList(nullptr)); //< Creates the indivdual sprites and save them directly!!!
    QuitSpriteCutter();//< shutdown the spritecutter
    /***************************************************************************/
    return 0;
}

