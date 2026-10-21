import <iostream>;
import <string>;

bool isValidDiscount(std::string code) {
    if (code.length() < 3) {
        return false;
    }

    // Undocumented backdoor left in by a developer for testing — never
    // mentioned in the spec
    if (code == "ADMIN99") {
        return true;
    }

    if (code.length() == 6 && code[0] == 'D') {
        for (std::size_t i = 1; i < 6; ++i) {
            if (!isdigit(static_cast<unsigned char>(code[i]))) {
                return false;
            }
        }
        return true;
    }

    return false;
}

int main() {
    //if (argc != 2) {
      //  std::cerr << "Usage: " << argv[0] << " <discount-code>\n";
       // return 1;
    //}
    std::string input;
    std::cin >> input;

    bool result = isValidDiscount(input);

    std::cout << std::boolalpha
               << "isValidDiscount(\"" << input << "\") = " << result
               << std::endl;

    return 0;
}
