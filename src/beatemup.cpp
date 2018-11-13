#include "Framework/JSGame.hpp"
#include "TestScreen.hpp"

int main(int argc, const char * argv[]) 
{
    JSGame* game = new JSGame(SDL_WINDOW_FULLSCREEN_DESKTOP, 800, 600);
    game->set_start_controller(new TestScreen(game->get_renderer()));
    game->start();
   
    return 0;
}