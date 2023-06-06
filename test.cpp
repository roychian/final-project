#include<stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_image.h>


int main(int argc,char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("GIF Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 764, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* imageSurface = IMG_Load("D:/Users/roy/Pictures/chest press/chest press1.png");
    if (imageSurface == NULL) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = imageSurface->w;
    dstRect.h = imageSurface->h;

    

    SDL_Event event;
    int running = 1;
    int currentFrame = 0;
    int totalFrames = 3; // Total number of frames in the animation

    int ctrl=0;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
                break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
        
        SDL_RenderPresent(renderer);
        SDL_Delay(500); // Adjust the delay to control the animation speeds

        // Update the image frame
        currentFrame = (currentFrame + 1) % totalFrames;
        char imagePath[256];
        sprintf(imagePath, "D:/Users/roy/Pictures/chest press/chest press%d.png", currentFrame+1); // Update the path based on the frame number
        imageSurface = IMG_Load(imagePath);
        SDL_DestroyTexture(texture);
        texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}