#include "game.h"

/*MH_Player Game::player() const
{
    return _player;
}*/

Game::Game(): _player("ball.png", Vector2f(100, 100))
{
    _window = new RenderWindow(VideoMode(1280, 720), "Bounce DBIAS");
    _map.setMap("C:/Users/Igor/Documents/build-Bounce-Desktop_Qt_5_11_2_MinGW_32bit-Debug/maps/first.txt");
}

Game::Game(size_t width, size_t height, float x, float y, string map_path) : _player("ball.png", Vector2f(x, y))
{
    _window = new RenderWindow(VideoMode(width, height), "Bounce DBIAS");
    _map.setMap(map_path);
}

void Game::KeyHandler()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        _player.Move(Vector2f(-0.00015, 0));
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        _player.Move(Vector2f(0.00015, 0));
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space))
    {
        if (_player.IsOnGround()) {_player.Move(Vector2f(0, -1.2)); _player.setIsOnGround(false);}
    }
}

void Game::EventHandler()
{
    Event event;
    while (_window->pollEvent(event))
    {
        if (event.type == Event::Closed)
            _window->close();
    }
}

void Game::MapHandler()
{
    RectangleShape block(Vector2f(32, 32));
    for (int i = 0; i < _map.getmap().size(); ++i)
        for (int j = 0; j < _map.getmap()[0].size(); ++j)
        {
            if (_map.getmap()[i][j] == 'B') block.setFillColor(Color::Green);
            else if (_map.getmap()[i][j] == '0') block.setFillColor(Color::Blue);
            else continue;
            block.setPosition(j*32, i*32);
            _window->draw(block);
        }
}

void Game::UpdateCamera()
{
    cout << _player.coordinates().x << " " << _player.coordinates().y << endl;
    cout << _window->getSize().x << " " << _window->getSize().y << endl;
    if (_player.coordinates().x >= _window->getSize().x/2)
    {
        _camera_view.move(1, 0);
    }
    else if (_player.coordinates().x <= _window->getSize().x/2)
    {
        _camera_view.move(-1, 0);
    }
    _window->setView(_camera_view);
}

void Game::Play()
{
    while (_window->isOpen())
    {
        float _time = _clock.getElapsedTime().asMicroseconds();
        _clock.restart();

        EventHandler();
        KeyHandler();

        _player.update(_time, _map.getmap());


        _window->clear(Color::White);
         MapHandler();



        _window->draw(_player.sprite());
        _window->display();
        UpdateCamera();


    }
}
