#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

class Shape
{
public:
    virtual ~Shape() = default;
};

class Shape2D : public Shape
{
public:
    virtual double area() const = 0;
};

class Shape3D : public Shape
{
public:
    virtual double volume() const = 0;
};

class Rect : public Shape2D
{
public:
    Rect() = default;
    Rect(double aa, double bb) : a(aa), b(bb) {}

    double area() const override { return a * b; }

private:
    double a = 0;
    double b = 0;
};

class Circle : public Shape2D
{
public:
    Circle() = default;
    Circle(double rr) : r(rr) {};

    double area() const override { return M_PI * r * r; }

private:
    double r = 0;
};

class Ball : public Shape3D
{
public:
    Ball() = default;
    Ball(double rr) : r(rr) {}

    double volume() const override { return M_PI * r * r * r; }

private:
    double r = 0;
};

class Cone : public Shape3D
{
public:
    Cone() = default;
    Cone(double rr, double hh) : r(rr), h(hh) {}

    double volume() const override { return M_PI * r * r * h / 3; }

private:
    double r = 0;
    double h = 0;
};

int main()
{
    //Shape s;
    //Shape2D s2d;
    //Shape3D s3d;

    Rect rect(2, 3);
    std::cout << rect.area() << std::endl;

    Circle circle(2);
    std::cout << circle.area() << std::endl;

    Ball ball(2);
    std::cout << ball.volume() << std::endl;

    Cone cone(2, 3);
    std::cout << cone.volume() << std::endl;
    return 0;
}
