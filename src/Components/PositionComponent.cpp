#include "Components/PositionComponent.hpp"

PositionComponent::PositionComponent(uint32_t x, uint32_t y) : JSComponent()
{
    this->x = x;
    this->y = y;
    velocity = 0;
}
void PositionComponent::handle_input(SDL_Event* event)
{
    if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_RIGHT)
    {
        velocity = 2;
    }else if(event->type == SDL_KEYDOWN  && event->key.keysym.sym == SDLK_LEFT)
    {
        velocity = -2;
    }
}
void PositionComponent::update(uint32_t delta)
{
    x = x + velocity;
    //velocity = 0;
}
void PositionComponent::render()
{}
uint32_t PositionComponent::get_x()
{
    return x;
}
uint32_t PositionComponent::get_y()
{
    return y;
}
void PositionComponent::set_velocity(uint32_t vel)
{
    velocity = vel;
}
PositionComponent::~PositionComponent()
{}