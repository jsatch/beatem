#include "Components/AnimatedSpriteComponent.hpp"

AnimatedSpriteComponent::AnimatedSpriteComponent()
{
    positionComponent = (PositionComponent*)(entity->get_component(0));
}
AnimatedSpriteComponent::AnimatedSpriteComponent(const char* filename, SDL_Renderer* renderer)
{
    positionComponent = (PositionComponent*)(entity->get_component(0));
    this->renderer = renderer;
    texture = JSTextureManager::load_texture(filename, this->renderer);

}
AnimatedSpriteComponent::AnimatedSpriteComponent(const char* filename, SDL_Renderer* renderer, AnimationProperties properties)
{
    this->renderer = renderer;
    try
    {
        texture = JSTextureManager::load_texture(filename, this->renderer);
    }catch(JSCreationException jsce)
    {
        std::cout << "Exception: " << jsce.what() << std::endl;
    }
    
    this->properties = properties;
    frame_animation_index = 0;
    current_animation_x = 0;
}
void AnimatedSpriteComponent::update(uint32_t delta)
{
    x = ((PositionComponent*)(entity->get_component(0)))->get_x();
    y = ((PositionComponent*)(entity->get_component(0)))->get_y();

    if (current_frame_loop >  (properties.number_of_loops / properties.number_of_animation_frames))
    {
        current_animation_x = current_animation_x + properties.widths[frame_animation_index] +  properties.offset;
        frame_animation_index++;
        current_frame_loop = 0;

        if (frame_animation_index == 8)
        {
            frame_animation_index = 0;
            current_animation_x = 0;
        }
    }else{
        current_frame_loop++;
    }
}
void AnimatedSpriteComponent::render()
{
    src_rect.x = current_animation_x;
    src_rect.y = 0;
    src_rect.w = properties.widths[frame_animation_index];
    src_rect.h = properties.height;
    //std::cout << x << " , " << y << std::endl;
    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.w = properties.widths[frame_animation_index];
    dest_rect.h = properties.height;
    SDL_RenderCopy(renderer, texture, &src_rect, &dest_rect);
}
void AnimatedSpriteComponent::set_animation_properties(AnimationProperties properties)
{
    this->properties = properties;
}
AnimatedSpriteComponent::~AnimatedSpriteComponent()
{}