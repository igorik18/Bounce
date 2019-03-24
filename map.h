#ifndef MAP_H
#define MAP_H
#include "includes.h"

class Map
{
    vector <string> _map;
public:
    Map();
    Map(string path);

    void setMap(const vector<string> &map);
    void setMap(string path);
    vector <string> getmap();
};

#endif // MAP_H
