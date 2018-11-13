#include "Entities/BackgroundEntity.hpp"

BackgroundEntity::BackgroundEntity(SDL_Renderer* renderer) : JSEntity()
{
    PositionComponent* posComp = new PositionComponent(100, 100); 
    SpriteComponent* sprComp = new SpriteComponent("../assets/ArtTileset.png", renderer);
    sprComp->x = 100;
    sprComp->y = 100;
    sprComp->w = 250;
    sprComp->h = 250;
    add_component(0, posComp);
    add_component(1, sprComp);
}
void BackgroundEntity::handle_input(SDL_Event *event)
{}
void BackgroundEntity::update(uint32_t delta)
{
    PositionComponent* pc = (PositionComponent*)get_component(0);
    SpriteComponent* sc = (SpriteComponent*)get_component(1);
    //pc->update(delta);
    sc->x = pc->get_x();
    sc->y = pc->get_y();
    JSEntity::update(delta);
}
void BackgroundEntity::render()
{
    // get_component(1)->render();
    JSEntity::render();
}
BackgroundEntity::~BackgroundEntity()
{}