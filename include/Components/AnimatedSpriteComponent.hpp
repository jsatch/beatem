#ifndef AnimatedSpriteComponent_hpp
#define AnimatedSpriteComponent_hpp

#include "Framework/JSEcs.hpp"
#include "Framework/JSTextureManager.hpp"
#include "Components/PositionComponent.hpp"

struct AnimationProperties
{
    uint32_t* widths;
    uint32_t height;
    uint32_t number_of_loops;
    uint32_t number_of_animation_frames;
    uint32_t offset;

    AnimationProperties()
    {}
    AnimationProperties(uint32_t width, uint32_t number_of_animation_frames)
    {
        widths = new uint32_t[number_of_animation_frames]();
        this->number_of_animation_frames = number_of_animation_frames;
        for (uint32_t i=0; i < number_of_animation_frames; i++)
        {
            widths[i] = width;
        }
    }
};

class AnimatedSpriteComponent : public JSComponent
{
private:
    PositionComponent* positionComponent;
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    uint32_t x, y;
    uint32_t current_frame_loop;
    uint32_t frame_animation_index;
    uint32_t current_animation_x;
    AnimationProperties properties;
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
public:
    AnimatedSpriteComponent();
    AnimatedSpriteComponent(const char* filename, SDL_Renderer* renderer);
    AnimatedSpriteComponent(const char* filename, SDL_Renderer* renderer, AnimationProperties properties);

    virtual void update(uint32_t delta);
    virtual void render();
    void set_animation_properties(AnimationProperties properties);
    ~AnimatedSpriteComponent();
};

#endif // AnimatedSpriteComponent_hpp