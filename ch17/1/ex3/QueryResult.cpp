#include "QueryResult.h"

std::string make_plural(std::string::size_type ctr,
        const std::string &word, const std::string &end)
{
    return (ctr > 1) ? word + end : word;
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " "
        << make_plural(std::get<1>(qr)->size(), "time", "s") << std::endl;
    for (auto num : *std::get<1>(qr)) {
        os << "\t(line " << num + 1 << ") "
            << *(std::get<2>(qr)->begin() + num) << std::endl;
    }
    return os;
}
