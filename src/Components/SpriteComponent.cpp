#include "Components/SpriteComponent.hpp"

SpriteComponent::SpriteComponent(const char *filename, SDL_Renderer* renderer) : JSComponent()
{
    this->renderer = renderer;
    this->texture = JSTextureManager::load_texture(filename, renderer);
}
void SpriteComponent::update(uint32_t delta)
{}
void SpriteComponent::render()
{
    SDL_Rect destRect;
    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;

    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}
SpriteComponent::~SpriteComponent()
{}
