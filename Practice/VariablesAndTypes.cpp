//
// Created by Mike Gao on 2020-01-13.
//

#include <iostream>

int main()
{
    /** Summary for fundamental Types in C++ 17 **/
    /** https://docs.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp/ **/
    int i1 = 1;
    std::cout << "i1=" << i1 << std::endl;
    int i2; // uninitialized
    i2 = 2;
    std::cout << "i2=" << i2 << std::endl;
    int i3(3);
    std::cout << "i3=" << i3 << std::endl;
    int i4{4};
    std::cout << "i4=" << i4 << std::endl;

    double d1 = 2.2;
    double d2 = i1;
    // int i5 = d1;  // Compile time warning - possible loss of data
    int i5 = static_cast<int> (d1);
    std::cout << "d1=" << d1 << std::endl;
    std::cout << "d2=" << d2 << std::endl;
    std::cout << "i5=" << i5 << std::endl;

    char c1 = 'a'; // cannot use double quote, will raise compiler error
    // compiler interprets anything with a double quote a collection of characters with a null terminator
    int i6 = c1;
    std::cout << "c1=" << c1 << std::endl;
    std::cout << "i6=" << i6 << std::endl;

    bool flag = false;
    std::cout << "flag=" << flag << std::endl;
    flag = i1;
    std::cout << "flag=" << flag << std::endl;
    flag = d1; // any non zero number gets converted to true, and true prints out 1
    std::cout << "flag=" << flag << std::endl;

    auto a1 = 1;
    auto a2 = 2.2;
    auto a3 = 'c'; // char
    auto a4 = "s"; // c-style string
    auto a5 = true;
    auto a6 = 6L; // long
    auto a7 = 1'000'000'000'000; // a long-long
    // Digit separator, new in C++ 14. CHANGES ABSOLUTELY NOTHING.
    auto a8 = 0xFF; // 255 hex-literal
    auto a9 = 0b111; // 7 binary-literal (added C++ 14)
    // a1 = a2; // Compile time warning - possible loss of data
    a1 = static_cast<int>(a2);

    unsigned char n1 = 128;
    char n2 = 128; // implicit conversion from 'int' to 'char' changes value from 128 to -128
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    n1 = 254;
    n2 = 254; // implicit conversion from 'int' to 'char' changes value from 254 to -2
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    n1 = 300; // implicit conversion from 'int' to 'unsigned char' changes value from 300 to 44
    n2 = 300; // implicit conversion from 'int' to 'char' changes value from 300 to 44
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
}