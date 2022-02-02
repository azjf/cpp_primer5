#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string ifile("ifile");
    std::ifstream in(ifile);
    std::ofstream out;

    out.open(ifile + ".copy");
    if (!out) {
        return -1;
    }

    in.close();
    in.open(ifile + "2");

    for (auto p = argv + 1; p != argv + argc; ++p) {
        std::ifstream input(*p);
        if (input) {
            //process(input);
        } else {
            std::cerr << "couldn't open: " + std::string(*p);
        }
    }

    std::ofstream out_("file1");
    std::ofstream out2("file1", std::ofstream::out);
    std::ofstream out3("file1", std::ofstream::out | std::ofstream::trunc);
    std::ofstream app("file2", std::ofstream::app);
    std::ofstream app2("file2", std::ofstream::out | std::ofstream::app);

    //std::ofstream out;
    out.close();
    out.open("scratchpad");
    out.close();
    out.open("precious", std::ofstream::app);
    out.close();
    return 0;
}
