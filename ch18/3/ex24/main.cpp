#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <numeric>

class ZooAnimal
{
public:
    virtual void print() { std::cout << "ZooAnimal::print" << std::endl; }
    virtual ~ZooAnimal() { std::cout << "~ZooAnimal" << std::endl; }
};


class Bear : public ZooAnimal
{
public:
    Bear() = default;
    Bear(const std::string &, bool, const std::string &) {}

    void print() { std::cout << "Bear::print" << std::endl; }
    virtual void toes() { std::cout << "Bear::toes" << std::endl; }
};

class Endangered
{
public:
    typedef unsigned type;
    static type critical;

    Endangered() = default;
    Endangered(type) {}

    virtual void print() { std::cout << "Endangered::print" << std::endl; }
    virtual void highlight()
    { std::cout << "Endangered::highlight" << std::endl; }
    virtual ~Endangered() { std::cout << "~Endangered" << std::endl; }
};

Endangered::type Endangered::critical = 0;

class Panda : public Bear, public Endangered
{
public:
    Panda();
    Panda(std::string name, bool onExhibit);
    Panda(const std::string &name) {}

    void print() { std::cout << "Panda::print" << std::endl; }
    void highlight() { std::cout << "Panda::highlight" << std::endl; }
    void toes() { std::cout << "Panda::toes" << std::endl; }
    virtual void cuddle() { std::cout << "Panda::cuddle" << std::endl; }
};

Panda::Panda() : Endangered(Endangered::critical) {}

Panda::Panda(std::string name, bool onExhibit)
    : Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) {}

int main()
{
    ZooAnimal *pz = new Panda("ying_yang");
    pz->print();
    //pz->cuddle();
    //pz->highlight();
    delete pz;
    return 0;
}
