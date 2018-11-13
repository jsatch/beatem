#include "TestScreen.hpp"

TestScreen::TestScreen(SDL_Renderer* renderer) : JSScreen(renderer)
{
    /*fondo = new JSSimpleGameObject("../assets/ArtTileset.png", renderer);
    
    //bg = new BackgroundEntity(renderer);
    add_game_entity(bg); */

    // 36 x 60
    // 3 pixels betweens sprites frame
    scott = new ScottEntity(100, 100, 36, 60, renderer);
    add_game_entity(scott);
    
    /*scott = new JSAnimatedGameObject("../assets/scott_standing.png", renderer);
    scott->set_x(100);
    scott->set_y(100);
    scott->set_width(36);
    scott->set_height(60);
    scott->set_offset(3);
    scott->set_animation_speed(32);

    add_game_object(scott);*/
}
void TestScreen::update(uint32_t delta)
{
    //fondo->get_rect()->x++;
    //std::cout << fondo->get_rect()->x << std::endl;
    JSScreen::update(delta);
}
void TestScreen::render()
{
    //std::cout << "Entra aca" << std::endl;
    JSScreen::render();
}
TestScreen::~TestScreen()
{}