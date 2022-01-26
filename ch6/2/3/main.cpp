#include <iostream>
#include <initializer_list>

class ErrCode
{
    public:
        int code;

    ErrCode(int code)
    {
        this->code = code;
    }

    std::string msg() {
        std::string ret("ErrCode " + std::to_string(this->code));
        return ret;
    }
};

void error_msg(std::initializer_list<std::string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg) {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;
}

void error_msg(ErrCode &e, std::initializer_list<std::string> il)
{
    std::cout << e.msg() << ": ";
    for (auto &elem : il) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string expected("expected");
    std::string actual("actual");
    if (expected != actual) {
        error_msg({"functionX", expected, actual});
        ErrCode err_code(42);
        error_msg(err_code, {"functionX", expected, actual});
    } else {
        error_msg({"functionX", "okay"});
        ErrCode err_code(0);
        error_msg(err_code, {"functionX", "okay"});
    }
    return 0;
}
