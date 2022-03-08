#include "Folder.h"
#include "Message.h"

Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_messages();
    m_messages = rhs.m_messages;
    add_to_messages();
    return *this;
}

void Folder::add_to_messages()
{
    for (auto m : m_messages) {
        m->folders.insert(this);
    }
}

void Folder::remove_from_messages()
{
    for (auto m : m_messages) {
        m->folders.erase(this);
    }
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto m : lhs.m_messages) {
        m->folders.erase(&lhs);
    }
    for (auto m : rhs.m_messages) {
        m->folders.erase(&rhs);
    }
    swap(lhs.m_messages, rhs.m_messages);
    for (auto m : lhs.m_messages) {
        m->folders.insert(&lhs);
    }
    for (auto m : rhs.m_messages) {
        m->folders.insert(&rhs);
    }
}
