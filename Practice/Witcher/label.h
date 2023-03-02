#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include "text_object.h"

class Label : public Text_Object
{
    private:
    std::string text;

    public:
    Label() : text("") {}

    Label(std::string t, int x = 0, int y = 0) : Text_Object(x, y), text(t) {}

    std::string daj_tekst() const
    {
        return text;
    }

    void ustaw_tekst(std::string t)
    {
        text = t;
    }

    virtual std::string daj_wizualna_reprezentacje() const
    {
        return text;
    }
};

#endif