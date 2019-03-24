#ifndef GAME_H
#define GAME_H
#include "mh_player.h"
#include "map.h"
class Game
{
    RenderWindow *_window;
    MH_Player _player;
    Map _map;
    Clock _clock;
    View _camera_view;
public:
    Game();
    Game(size_t width, size_t height, float x = 0, float y = 0, string map_path = "C:/Users/Igor/Documents/build-Bounce-Desktop_Qt_5_11_2_MinGW_32bit-Debug/maps/first.txt" );

    void KeyHandler();
    void EventHandler();
    void MapHandler();

    void UpdateCamera();

    void Play();
private:
    MH_Player player() const;
};

#endif // GAME_H
