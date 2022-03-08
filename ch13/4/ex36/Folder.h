#ifndef FOLDER_H
#define FOLDER_H
#include <set>

class Message;

class Folder
{
    friend void swap(Folder &, Folder &);

public:
    Folder() = default;
    Folder(const Folder &f) : m_messages(f.m_messages) { add_to_messages(); }
    ~Folder() { remove_from_messages(); }
    Folder &operator=(const Folder &);

    void addMsg(Message *message) { m_messages.insert(message); }
    void remMsg(Message *message) { m_messages.erase(message); }

private:
    std::set<Message *> m_messages;

    void add_to_messages();
    void remove_from_messages();
};
#endif
