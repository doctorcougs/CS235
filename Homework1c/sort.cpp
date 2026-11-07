#include <iostream>
#include <string>

void sort(std::string& a, std::string& b, std::string& c) {
    // implement sort here
    if (a.compare(b) > 0) { //  b a c to a b c
      std::swap(a, b);
    } if (a.compare(c) > 0) { // c a b to a b c
      std::swap(a, c);
    } if (b.compare(c) > 0) { // a c b to a b c
      std::swap(b, c);
    }
}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    std::cout << a << ' ' << b << ' ' << c << std::endl;

    return 0;
}
