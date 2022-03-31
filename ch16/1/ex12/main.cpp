#include <iostream>
#include <memory>
#include <vector>
#include <cstring>
#include "Blob.h"
#include "BlobPtr.h"

int main()
{
    Blob<std::string> sb{"hello", "world"};
    BlobPtr<std::string> sbp(sb, 0);
    return 0;
}
