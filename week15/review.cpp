#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
struct node {
  std::string _rate;
  std::string _book;
  node(std::string r, std::string b) : _rate(r), _book(b) {}
};
bool cmp1(const node& a, const node& b) {
  return a._book < b._book;
}
bool cmp2(const node& a, const node& b) {
  return a._rate < b._rate;
}
int main() {
  int count = 0;
  std::string str, rate;
  std::vector<node> store;
  while (1) {
    std::getline(std::cin, str, '\n');
    if (str == "quit") {
      if (count == 0) {
        std::cout << "No entries. Bye.\n";
        return 0;
      } else {
        std::cout << "Thank you. You entered the following " << count
                  << " ratings:\n";
      }
      break;
    }
    count++;
    std::getline(std::cin, rate);
    store.push_back(node(rate, str));
  }
  std::cout << "Rating\tBook\n";
  for (std::vector<node>::iterator it = store.begin();
       it != store.end(); ++it) {
    std::cout << it->_rate << '\t' << it->_book << std::endl;
  }
  std::cout << "Sorted by title:\n";
  std::cout << "Rating\tBook\n";
  std::sort(store.begin(), store.end(), cmp1);
  for (std::vector<node>::iterator it = store.begin();
       it != store.end(); ++it) {
    std::cout << it->_rate << '\t' << it->_book << std::endl;
  }
  std::cout << "Sorted by rating:\n";
  std::cout << "Rating\tBook\n";
  std::sort(store.begin(), store.end(), cmp2);
  for (std::vector<node>::iterator it = store.begin();
       it != store.end(); ++it) {
    std::cout << it->_rate << '\t' << it->_book << std::endl;
  }
  std::cout << "Bye.\n";
  return 0;
}
