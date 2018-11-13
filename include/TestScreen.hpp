#ifndef TestScreen_hpp
#define TestScreen_hpp
#include "Framework/JSScreen.hpp"
#include "Entities/BackgroundEntity.hpp"
#include "Entities/ScottEntity.hpp"

class TestScreen : public JSScreen
{
private:
    BackgroundEntity* bg;
    ScottEntity* scott;
public:
    TestScreen(SDL_Renderer* renderer);
    virtual void update(uint32_t delta);
    virtual void render();
    ~TestScreen();
    
};

#endif // TestScreen_hpp