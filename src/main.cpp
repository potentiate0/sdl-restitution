#include <SDL2/SDL.h>
#include <iostream>

// Window constants
const int WIDTH = 640, HEIGHT = 480;
const char *title = "COR";

// SDL Window variables
SDL_Window *gWindow = NULL;
SDL_Surface *gSurface = NULL;

// Texture variables


// Initialize SDL and window
bool init() 
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "ERR: SDL_Init failed! " << SDL_GetError() << std::endl;
        success = false;
    }

    gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        std::cout << "ERR: Window couldn't be created! " << SDL_GetError() << std::endl;
        success = false;
    }
    gSurface = SDL_GetWindowSurface(gWindow);

    return success;
}

// Exit the program
bool close()
{
    SDL_Quit();
}

int main() {

    init();

    bool quit = false;

    // Main loop
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }
        
        SDL_FillRect(gSurface, NULL, SDL_MapRGB(gSurface->format, 255, 255, 255));
        SDL_UpdateWindowSurface(gWindow);

    }

    close();

}
