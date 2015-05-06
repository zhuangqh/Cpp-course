#include <iostream>
#include <algorithm>
using namespace std;
int get(int a) {
  while (a > 10) a /= 10;
  return a;
}
bool cmp1(const int &a, const int &b) {
  cout << "cao" << get(a) << get(b) << endl;
  return get(a) > get(b);
}
bool cmp2(const int& a, const int& b) {
  int aa = a, bb = b;
  if (get(a) != get(b)) {
    cout << "fuck";
    return false;
  }
  while (aa < 100) aa = aa * 10 + get(a);
  while (bb < 100) bb = bb * 10 + get(a);
  return aa > bb;
}
int main() {
  int t;
  int num[1000];
  cin >> t;
  for (int i = 0; i < t; ++i)
    cin >> num[i];
  sort(num, num + t, cmp1);
  for (int i = 0; i < t; ++i)
    cout << num[i];
  cout << endl;
  sort(num, num + t, cmp2);
  for (int i = 0; i < t; ++i)
    cout << num[i];
  cout << endl;
  return 0;
}
