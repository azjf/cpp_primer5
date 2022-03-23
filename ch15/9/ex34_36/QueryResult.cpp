#include "QueryResult.h"

std::string make_plural(std::string::size_type ctr,
        const std::string &word, const std::string &end)
{
    return (ctr > 1) ? word + end : word;
}

std::ostream &operator<<(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}
