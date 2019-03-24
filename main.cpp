#include <QCoreApplication>
#include "game.h"

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    Game game(1280, 720, 50, 50);
    game.Play();



    return a.exec();
}
