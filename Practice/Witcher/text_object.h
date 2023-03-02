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

    void set_coordinates(int x, int y)
    {
        coordinates = std::make_pair(x, y);
    }

    virtual std::string daj_wizualna_reprezentacje() const
    {
        return "";
    }

    bool operator==(const Text_Object& inny) const
    {
        return coordinates == inny.get_coordinates() && daj_wizualna_reprezentacje() == inny.daj_wizualna_reprezentacje();
    }

    bool operator==(const Text_Object* inny) const
    {
        return coordinates == inny->get_coordinates() && daj_wizualna_reprezentacje() == inny->daj_wizualna_reprezentacje();
    }

};

inline bool operator==(const Text_Object *ja, const Text_Object& ktos)
{
    return ja->get_coordinates() == ktos.get_coordinates() && ja->daj_wizualna_reprezentacje() == ktos.daj_wizualna_reprezentacje();
}

#endif