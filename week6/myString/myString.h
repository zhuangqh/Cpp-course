#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>
#include <iostream>

#define nullptr NULL

class myString {
private:
        char * _data;
        unsigned _length;

public:
        myString(); // Create an empty string.
        explicit myString(const char *); // Copy data from a c-style string.
        myString(const myString &); // Copy constructor.

        ~myString();

        void clear();
        // Clear the string. (Then it will be back to an empty string.)
        unsigned length() const;
        const char * c_str() const;
        // Return the c-style string.

        void operator=(const char *);
        void operator=(const myString &);

        char operator[](const unsigned &) const;
        char & operator[](const unsigned &);
        // You must be familiar with these two guys :)

        myString operator+(const myString &) const;
        myString operator+(const char *) const;
        // Appending. "ab" + "cd" = "abcd"

        void operator+=(const myString &);
        void operator+=(const char *);

        bool operator==(const myString &) const;
        bool operator==(const char *) const;
        // "" == "" <-- That must be true.
        bool operator!=(const myString &) const;
        bool operator!=(const char *) const;
        bool operator<(const myString &) const;
        bool operator<(const char *) const;
        // In alphabet order.
        bool operator<=(const myString &) const;
        bool operator<=(const char *) const;
        bool operator>(const myString &) const;
        bool operator>(const char *) const;
        bool operator>=(const myString &) const;
        bool operator>=(const char *) const;

        friend myString operator+(const char *, const myString &);
        friend bool operator==(const char *, const myString &);
        friend bool operator!=(const char *, const myString &);
        friend bool operator<(const char *, const myString &);
        friend bool operator<=(const char *, const myString &);
        friend bool operator>(const char *, const myString &);
        friend bool operator>=(const char *, const myString &);

        friend std::istream & operator>>(std::istream &, myString &);
        // Stop if you meet spaces, LF, \t, or some other strange chars.
        // There may be extra spaces or other traps in the test data.
        // So make it as strong as possible.
        friend std::ostream & operator<<(std::ostream &, const myString &);
        // Normal output, boring...
};

#endif
