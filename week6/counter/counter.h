#ifndef COUNTER2_H
#define COUNTER2_H

class counter2 {
private:
        int _data;

public:
        explicit counter2(const int & data = 0) : _data(data) {}
        explicit counter2(const counter2 & other) : _data(other._data) {}

        int operator++() {
                return ++_data;
        }
        int operator++(int) {
                int temp = _data;
                ++_data;
                return temp;
        }
        int operator--() {
                return --_data;
        }
        int operator--(int) {
                int temp = _data;
                --_data;
                return temp;
        }

        void set(const int & data) {
                _data = data;
        }
        void reset() {
                _data = 0;
        }

        int show() const {
                return _data;
        }
};

#endif
