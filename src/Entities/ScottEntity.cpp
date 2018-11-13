#include "Entities/ScottEntity.hpp"

ScottEntity::ScottEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, SDL_Renderer *renderer) : JSEntity()
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->state = standing;
    this->state_counter = 0;

    add_component(0, new PositionComponent(x, y));

    AnimationProperties propsStanding = AnimationProperties(36, 8);
    propsStanding.offset = 3;
    propsStanding.number_of_animation_frames = 8;
    propsStanding.number_of_loops = 32;
    propsStanding.height = 60;

    AnimatedSpriteComponent *asc_standing = new AnimatedSpriteComponent("assets/scott_standing.png", renderer, propsStanding);
    add_component(1, asc_standing);

    AnimationProperties propsRunning = AnimationProperties();
    propsRunning.offset = 3;
    propsRunning.number_of_animation_frames = 8;
    propsRunning.number_of_loops = 32;
    propsRunning.height = 60;
    propsRunning.widths = new uint32_t[8]();
    propsRunning.widths[0] = 37;
    propsRunning.widths[1] = 43;
    propsRunning.widths[2] = 53;
    propsRunning.widths[3] = 46;
    propsRunning.widths[4] = 39;
    propsRunning.widths[5] = 41;
    propsRunning.widths[6] = 50;
    propsRunning.widths[7] = 46;

    AnimatedSpriteComponent *asc_running = new AnimatedSpriteComponent("assets/scott_running.png", renderer, propsRunning);
    add_component(2, asc_running);
}
void ScottEntity::handle_input(SDL_Event *event)
{ 
    if (event->type == SDL_KEYDOWN 
        && (event->key.keysym.sym == SDLK_RIGHT || event->key.keysym.sym == SDLK_LEFT))
    {
        state_counter = 0;
        if (state == standing) state = beginning;
        else if (state == beginning) state = running;
    }
    else if (event->key.keysym.sym == SDLK_UP)
    {
        state = standing;
    }
    JSEntity::handle_input(event);
}
void ScottEntity::update(uint32_t delta)
{
    if (state_counter > 5 && state == running)
    {
        state = standing;
        state_counter = 0;
    }
    
    if (state == running || state == beginning)
    {
        get_component(2)->set_active(true);
        get_component(1)->set_active(false);
    }
    else if (state == standing)
    {
        ((PositionComponent *)get_component(0))->set_velocity(0); // Stopping Scott
        get_component(2)->set_active(false);
        get_component(1)->set_active(true);
    }
    state_counter++;
    JSEntity::update(delta);
}
void ScottEntity::render()
{
    JSEntity::render();
}
ScottEntity::~ScottEntity()
{
}