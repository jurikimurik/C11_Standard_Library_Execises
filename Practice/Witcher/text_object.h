#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include <iostream>
#include <utility>
class Text_Object {
    private:
    std::pair<int, int> coordinates;

    public:
    Text_Object() : coordinates(std::make_pair(0,0)) {}

    Text_Object(int x, int y) : coordinates(std::make_pair(x, y)) {}

    Text_Object(std::pair<int, int> c) : coordinates(c) {}

    std::pair<int, int> get_coordinates() const
    {
        return coordinates;
    }

    void set_coordinates(std::pair<int, int> c)
    {
        coordinates = c;
    }

};

#endif