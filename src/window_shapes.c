//to compile the app
//gcc -o window_image window_image.c -lSDL2

#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("My Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetWindowTitle(window, "Shapes");

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        

        // Set the drawing color to red
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

        // Draw a rectangle
        SDL_Rect rect = { 220, 100, 50, 50 };
        SDL_RenderFillRect(renderer, &rect);

        // Set the drawing color to green
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        // Draw a line
        SDL_RenderDrawLine(renderer, 6, 111, 640, 480);

        // Draw the three sides of the triangle
        SDL_RenderDrawLine(renderer, 100, 100, 200, 100);
        SDL_RenderDrawLine(renderer, 200, 100, 150, 200);
        SDL_RenderDrawLine(renderer, 150, 200, 100, 100);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
