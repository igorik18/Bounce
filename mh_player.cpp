#include "mh_player.h"

Sprite MH_Player::sprite()
{
    return _sprite;
}

bool MH_Player::IsOnGround() const
{
    return _IsOnGround;
}

void MH_Player::setIsOnGround(bool IsOnGround)
{
    _IsOnGround = IsOnGround;
}

MH_Player::MH_Player()
{
    _texture.loadFromFile("ball.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(IntRect(0, 0, 200, 200));
    _sprite.setScale(0.16, 0.16);
    _sprite.setPosition(150, 200);
    _rectangle.left = _sprite.getPosition().x;
    _rectangle.top = _sprite.getPosition().y;
    _rectangle.width = _sprite.getTexture()->getSize().x*_sprite.getScale().x;
    _rectangle.height = _sprite.getTexture()->getSize().y*_sprite.getScale().y;
    _dx=_dy=0;
    if (_rectangle.top < 500) _IsOnGround = true;
    else _IsOnGround = false;
}

MH_Player::MH_Player(string path, Vector2f coordinates)
{
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(IntRect(0, 0, 200, 200));
    _sprite.setScale(0.16, 0.16);
    _sprite.setPosition(coordinates);
    _rectangle.left = _sprite.getPosition().x;
    _rectangle.top = _sprite.getPosition().y;
    _rectangle.width = _sprite.getTexture()->getSize().x*_sprite.getScale().x;
    _rectangle.height = _sprite.getTexture()->getSize().y*_sprite.getScale().y;
    _dx=_dy=0;
    if (_rectangle.top < 500) _IsOnGround = true;
    else _IsOnGround = false;
}

void MH_Player::Move(Vector2f delta)
{
   // _sprite.move(delta);
    //if (delta.y > 0) _sprite.move(delta);
    _dx+=delta.x;
    _dy+=delta.y;
}

void MH_Player::CollisionX(vector<string> str_map)
{
    for (size_t i = _rectangle.top/32; i < (_rectangle.top + _rectangle.height)/32; i++)
        for (size_t j = _rectangle.left/32; j < (_rectangle.left + _rectangle.width)/32; j++)
        {
            if (str_map[i][j] == 'B' || str_map[i][j] == '0')
            {
                if (_dx>0) _rectangle.left = j*32 - _rectangle.width;
                if (_dx<0) _rectangle.left = j*32 + 32;
            }
        }
}

void MH_Player::CollisionY(vector<string> str_map)
{
    for (size_t i = _rectangle.top/32; i < (_rectangle.top + _rectangle.height)/32; i++)
        for (size_t j = _rectangle.left/32; j < (_rectangle.left + _rectangle.width)/32; j++)
        {
            if (str_map[i][j] == 'B' || str_map[i][j] == '0')
            {
                if (_dy>0) {_rectangle.top = i*32 - _rectangle.height; _dy = 0; _IsOnGround = true;}
                if (_dy<0) {_rectangle.top = i*32 + 32; _dy = 0;}
            }
        }

}

void MH_Player::update(float time, vector<string> str_map)
{
    _rectangle.left += _dx*time;
    CollisionX(str_map);
    if (!_IsOnGround) _dy += 0.000003*time;
    _rectangle.top += _dy/**time*/;
    _IsOnGround = false;
    CollisionY(str_map);
    if (_rectangle.top >= 500) { _rectangle.top = 500; _dy = 0; _IsOnGround = true;}
    _dx = 0;
    _sprite.setPosition(_rectangle.left, _rectangle.top);
}

Vector2f MH_Player::coordinates() const
{
    return _sprite.getPosition();
}

void MH_Player::setCoordinates(const Vector2f &coordinates)
{
    _sprite.setPosition(coordinates);
}
