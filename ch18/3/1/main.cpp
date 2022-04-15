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
    ZooAnimal() = default;
    ZooAnimal(const std::string &name, bool onExhibit, const std::string &) {}

    virtual void print() { std::cout << "ZooAnimal::print" << std::endl; }
    virtual ~ZooAnimal() { std::cout << "~ZooAnimal" << std::endl; }

    double max_weight() const { return 0; }
};


class Bear : virtual public ZooAnimal
{
public:
    Bear() = default;
    Bear(const std::string &name, bool onExhibit, const std::string &)
        : ZooAnimal(name, onExhibit, "Bear") {}
    Bear(const std::string &name, bool onExhibit) {}

    void print() { std::cout << "Bear::print" << std::endl; }
    virtual void toes() { std::cout << "Bear::toes" << std::endl; }
};

class Raccoon : public virtual ZooAnimal
{ 
public:
    Raccoon() = default;
    Raccoon(const std::string &name, bool onExhibit, const std::string &)
        : ZooAnimal(name, onExhibit, "Raccoon") {}
    Raccoon(const std::string &name, bool onExhibit) {}
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

    double max_weight() const { return 0; }
};

Endangered::type Endangered::critical = 0;

class Panda : public Bear, public Raccoon, public Endangered
{
public:
    Panda();
    Panda(std::string name, bool onExhibit);
    Panda(const std::string &name) {}

    void print() { std::cout << "Panda::print" << std::endl; }
    void highlight() { std::cout << "Panda::highlight" << std::endl; }
    void toes() { std::cout << "Panda::toes" << std::endl; }
    virtual void cuddle() { std::cout << "Panda::cuddle" << std::endl; }

    double max_weight() const;

private:
    bool sleeping_flag;
};

Panda::Panda() : Endangered(Endangered::critical) {}

//Panda::Panda(std::string name, bool onExhibit)
//    : Bear(name, onExhibit, "Panda"), Endangered(Endangered::critical) {}
Panda::Panda(std::string name, bool onExhibit)
    : ZooAnimal(name, onExhibit, "Panda"),
    Bear(name, onExhibit), Raccoon(name, onExhibit),
    Endangered(Endangered::critical), sleeping_flag(false) {}

double Panda::max_weight() const
{
    return std::max(ZooAnimal::max_weight(), Endangered::max_weight());
}

struct Base1
{
    Base1() = default;
    Base1(const std::string);
    Base1(std::shared_ptr<int>) {}
};

struct Base2
{
    Base2() = default;
    Base2(const std::string);
    Base2(std::shared_ptr<int>) {}
};

struct D1 : public Base1, public Base2
{
    using Base1::Base1;
    using Base2::Base2;
};

struct D2 : public Base1, public Base2
{
    using Base1::Base1;
    using Base2::Base2;
    D2(const std::string &s) : Base1(s), Base2(s) {}
    D2() = default;
};

void print(const Bear &) {}
void highlight(const Endangered &) {}
std::ostream &operator<<(std::ostream &os, const ZooAnimal &) { return os; }

void print(const Endangered &) {}

void dance(const Bear &) {}
void rummage(const Raccoon &) {}

class Character {};
class BookCharacter : public Character {};
class ToyAnimal {};
class TeddyBear : public BookCharacter, public Bear, public virtual ToyAnimal {};

int main()
{
    Panda ying_yang("ying_yang");
    Panda ling_ling = ying_yang;

    //print(ying_yang);
    highlight(ying_yang);
    std::cout << ying_yang << std::endl;

    Bear *pb = new Panda("ying_yang");
    pb->print();
    //pb->cuddle();
    //pb->highlight();
    delete pb;
    std::cout << std::endl;

    Endangered *pe = new Panda("ying_yang");
    pe->print();
    //pe->toes();
    //pe->cuddle();
    pe->highlight();
    delete pe;
    std::cout << std::endl;

    //double d = ying_yang.max_weight();
    double d1 = ying_yang.ZooAnimal::max_weight();
    double d2 = ying_yang.Endangered::max_weight();

    dance(ying_yang);
    rummage(ying_yang);
    std::cout << ying_yang;
    return 0;
}
