#include <iostream>
#include <memory>
#include <vector>
#include <list>

template <typename elemType> class ListItem;

template <typename elemType>
class List
{
public:
    //List<elemType>();
    //List<elemType>(const List<elemType> &);
    //List<elemType> &operator=(const List<elemType> &);
    List();
    List(const List &);
    List &operator=(const List &);
    ~List();

    //void insert(ListItem *ptr, elemType value);
    void insert(ListItem<elemType> *ptr, elemType value);

private:
    //ListItem *front, *end;
    ListItem<elemType> *front, *end;
};

int main()
{
    return 0;
}
