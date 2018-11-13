#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "../Framework/JSEcs.hpp"
#include "../Framework/JSTextureManager.hpp"

class SpriteComponent : public JSComponent
{
private:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
public:
    int x,y,w, h;
    SpriteComponent(const char *filename, SDL_Renderer* renderer);
    virtual void update(uint32_t delta);
    virtual void render();
    ~SpriteComponent();
};

#endif // SpriteComponent_hpp