#include "Framework/JSEcs.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/AnimatedSpriteComponent.hpp"

enum ScottEntityState { standing, beginning ,running };

class ScottEntity : public JSEntity
{
private:
    uint32_t x, y, w, h;
    ScottEntityState state;
    uint32_t state_counter;
public:
    ScottEntity(uint32_t x, uint32_t y, uint32_t w, uint32_t h, SDL_Renderer* renderer);
    void handle_input(SDL_Event *event);
    void update(uint32_t delta);
    void render();
    ~ScottEntity();
};