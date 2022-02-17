#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    if (!qr.found()) {
        os << qr.word << " not found";
        return os;
    }

    const auto line_nums = qr.get_line_nums();
    os << qr.word << " occurs " << line_nums.size() << " time(s)\n";
    for (const auto &n : line_nums) {
        os << "\t(line " << n << ") " << qr.get_line(n) << "\n";
    }
    return os;
}
