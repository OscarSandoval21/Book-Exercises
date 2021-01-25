#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

/*
    5-1. Let’s try implementing a class using the basic framework. Consider a class to
    store the data for an automobile. We’ll have three pieces of data: a manufacturer
    name and model name, both strings, and a model year, an integer. Create a
    class with get/set methods for each data member. Make sure you make good
    decisions concerning details like member names. It’s not important that you
    follow my particular naming convention. What’s important is that you think
    about the choices you make and are consistent in your decisions.
*/

class Automobile
{
private:
    string manufacturer;
    string model;
    int year;
public:
    Automobile(/* args */);
    ~Automobile();
};

Automobile::Automobile(/* args */)
{
}

Automobile::~Automobile()
{
}


#endif