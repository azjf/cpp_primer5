#include "Blob.h"
#include "compare.h"

extern template class Blob<std::string>;
extern template int compare(const int &, const int &);
Blob<std::string> sa1, sa2;
Blob<int> a1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Blob<int> a2(a1);
int i = compare(a1[0], a2[0]);
