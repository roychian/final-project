#include<iostream>
#include<SDL2/SDL.h>
using namespace std;

#define WIDTH 800
#define HEIGHT 600
int main(int argc,char *arcv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window=SDL_CreateWindow("hello SDL",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL== window)
    {
        cout<<"can't window!"<<SDL_GetError()<<endl;
        return 1;
    }

    SDL_Event WindowEvent;

    while(1)
    {
        if(SDL_PollEvent(&WindowEvent))
        {
            if(SDL_QUIT==WindowEvent.type)
            {
                break;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}