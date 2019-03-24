#include "map.h"

Map::Map()
{
    _map =
    {
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                             BBBB     B",
        "B                             BBBB     B",
        "B                             BBBB     B",
        "B                             BBBB     B",
        "B      00000000               BBBB     B",
        "B                             BBBB     B",
        "B                             BBBB     B",
        "B               BB            BBBB     B",
        "B    B         BBBB                    B",
        "B   BBB       BBBBBB                   B",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    };
}

Map::Map(string path)
{
    _map.clear();
    ifstream fin;
    fin.open(path.c_str());
    string buffer;
    if (fin.is_open())
    {
        while (getline(fin,buffer))
        {
         _map.push_back(buffer);
        }
    }
    fin.close();
}

void Map::setMap(const vector<string> &map)
{
    _map = map;
}

void Map::setMap(string path)
{
    _map.clear();
    ifstream fin;
    fin.open(path.c_str());
    string buffer;
    if (fin.is_open())
    {
        while (getline(fin,buffer))
        {
         _map.push_back(buffer);
        }
    }
    fin.close();
}


vector<string> Map::getmap()
{
    return _map;
}
