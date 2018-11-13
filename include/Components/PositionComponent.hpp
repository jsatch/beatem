#ifndef PositionComponent_hpp
#define PositionComponent_hpp

#include "../Framework/JSEcs.hpp"

class PositionComponent : public JSComponent
{
private:
    uint32_t x, y, velocity;
public:
    
    PositionComponent(uint32_t x, uint32_t y);
    PositionComponent(uint32_t x, uint32_t y, JSEntity* entity);
    virtual void handle_input(SDL_Event* event);
    virtual void update(uint32_t delta);
    virtual void render();
    uint32_t get_x();
    uint32_t get_y();
    void set_velocity(uint32_t vel);
    ~PositionComponent();
};

#endif // PositionComponent_hpp