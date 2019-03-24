#ifndef MH_PLAYER_H
#define MH_PLAYER_H
#include "includes.h"

class MH_Player
{
    Sprite _sprite;
    Texture _texture;
    float _dx, _dy;
    bool _IsOnGround;
    FloatRect _rectangle;
public:
    MH_Player();
    MH_Player(string path, Vector2f coordinates = Vector2f(0, 0));

    void Move(Vector2f delta);

    void CollisionX(vector<string> str_map);
    void CollisionY(vector<string> str_map);

    void update(float time, vector<string> str_map);

   // void create(string path, Vector2f coordinates = Vector2f(0, 0));
    Vector2f coordinates() const;
    void setCoordinates(const Vector2f &coordinates);
    Sprite sprite();
    bool IsOnGround() const;
    void setIsOnGround(bool IsOnGround);
};

#endif // MH_PLAYER_H
