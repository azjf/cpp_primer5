#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "StrBlob.h"

int main()
{
    std::shared_ptr<std::string> p1;
    std::shared_ptr<std::list<int>> p2;
    if (p1 && p1->empty()) {
        *p1 = "hi";
    }

    std::shared_ptr<int> p3 = std::make_shared<int>(42);
    std::shared_ptr<std::string> p4 = std::make_shared<std::string>(10, '9');
    std::shared_ptr<int> p5 = std::make_shared<int>();
    auto p6 = std::make_shared<std::vector<std::string>>();

    auto p = std::make_shared<int>(42);
    auto q(p);
    auto r = std::make_shared<int>(42);
    r = q;

    std::vector<std::string> v1;
    {
        std::vector<std::string> v2 = {"a", "an", "the"};
        v1 = v2;
    }

    StrBlob sb;

    int *pi = new int;
    std::string *ps = new std::string;
    int *pi2 = new int;

    pi = new int(1024);
    ps = new std::string(10, '9');
    std::vector<int> *pv = new std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::string *ps1 = new std::string;
    ps = new std::string();
    int *pi1 = new int;
    pi2 = new int();

    const int *pci = new const int(1024);
    const int *pci2 = new int(1024);
    const std::string *pcs = new const std::string;

    int *p11 = new int;
    int *p21 = new (std::nothrow) int;

    int *pp = new int(2);
    delete pp;

    int i; pi1 = &i, pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    //delete i;
    //delete pi1;
    delete pd;
    //delete pd2;
    delete pi2;

    const int *pci3 = new const int(1024);
    delete pci;

    int *p7(new int(42));
    auto q2 = p7;
    delete p7;
    p7 = nullptr;
    return 0;
}
