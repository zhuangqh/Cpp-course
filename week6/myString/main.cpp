#include <iostream>
#include <string>
#include "myString.h"

void print(const bool & f) {
        if (f)
                std::cout << "True" << std::endl;
        else
                std::cout << "False" << std::endl;
}

int main() {
        myString s1, s2;
        std::cin >> s1 >> s2;
        const myString s3(s1.c_str()), s4(s2);
        std::cout << s3 + s4 << std::endl
                << s3 + s4.c_str() << std::endl
                << s3.c_str() + s4 << std::endl;
        s1 = "";
        s1 += "";
        std::cout << s1.length() << std::endl;
        s1 += s4;
        std::cout << s1 << std::endl;
        s2 = s3.c_str();
        std::cout << s1[0] << s2[0] << std::endl;

        print(s3 == s4);
        print(s3 == s4.c_str());
        print(s3 != s4);
        print(s3 != s4.c_str());
        print(s3 < s4);
        print(s3 < s4.c_str());
        print(s3 <= s4);
        print(s3 <= s4.c_str());
        print(s3 > s4);
        print(s3 > s4.c_str());
        print(s3 >= s4);
        print(s3 >= s4.c_str());
        print(s3.c_str() == s4);
        print(s3.c_str() != s4);
        print("" < s4);
        print("" <= myString(""));
        print("" > myString(""));
        print("" >= s3);
        return 0;
}
