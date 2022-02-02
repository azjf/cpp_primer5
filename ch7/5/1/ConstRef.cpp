#include "ConstRef.h"

// ConstRef::ConstRef(int ii)
// {
//     i = ii;
//     ci = ii;
//     ri = i;
// }

ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(i) { }
