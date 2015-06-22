#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H
#include <string>
#include <set>
class WordsCounter {
private:
  int bound;
public:
  WordsCounter(int x) : bound(x) {}
  void setBound(int num) {bound = num;}
  int operator()(std::string text);
};
int WordsCounter::operator()(std::string text) {
  int size = text.size(), j;
  std::set<std::string> store;
  for (int i = 0; i < size; ++i) {
    if (text[i] != ' ') {
      for (j = i; j != size; ++j)
        if (text[j] == ' ')
          break;
      if (j - i >= bound)
        store.insert(text.substr(i, j - i));
      i = j;
    }
  }
  return store.size();
}
#endif
