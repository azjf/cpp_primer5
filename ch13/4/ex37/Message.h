#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>

#include "Folder.h"

class Message
{
    friend class Folder;
    friend void swap(Message &, Message &);

public:
    explicit Message(const std::string &str = "") : contents(str) {}
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    void addFolder(Folder *folder) { folders.insert(folder); }
    void remFolder(Folder *folder) { folders.erase(folder); }

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};
#endif
