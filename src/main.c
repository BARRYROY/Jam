#include "/opt/homebrew/Cellar/sdl2/2.30.8/include/SDL2/SDL.h"
#include <stdio.h>

#define RECT_WIDTH  10
#define RECT_HEIGHT 10
#define RECT_X  10
#define RECT_Y  10

int main(){

  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ){
    fprintf(stderr, "ERROR! Failed to initialize SDL: %s.\n", SDL_GetError());
    SDL_Quit();
  }


  SDL_Window* window = SDL_CreateWindow("Jam",
                        SDL_WINDOWPOS_UNDEFINED , SDL_WINDOWPOS_UNDEFINED, 
                        800, 600,SDL_WINDOW_RESIZABLE );

  if(!window){
    fprintf(stderr, "Error Creating window: %s.\n", SDL_GetError());
    SDL_Quit();
  }

  printf("Window Successfully initialized.\n");

  SDL_Event event;
  int quit = 0;

  while(!quit){
    printf("Game is running...\n");
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            quit++;
        }
    }
  }


  printf("shutting down...\n");
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
