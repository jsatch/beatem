#ifndef BackgroundEntity_hpp
#define BackgroundEntity_hpp

#include "../Framework/JSEcs.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/SpriteComponent.hpp"

class BackgroundEntity : public JSEntity
{
public:
    BackgroundEntity(SDL_Renderer* ren);
    virtual void handle_input(SDL_Event* event);
    virtual void update(uint32_t delta);
    virtual void render();
    ~BackgroundEntity();
};

#endif // BackgroundEntity_hpp