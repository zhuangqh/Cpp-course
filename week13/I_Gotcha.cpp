#include <map>
#include <iostream>
#include <string>
using namespace std;
int main() {
  string mac, id;
  map<string, string> mymap1;
  map<string, string> mymap2;
  for (int i = 0; i < 5; ++i) {
    cin >> mac >> id;
    map<string, string>::iterator it;
    if (mymap1.find(mac) == mymap1.end() && mymap2.find(id) == mymap2.end()) {
      cout << id << " registered.\n";
      mymap1[mac] = id;
      mymap2[id] = mac;
    } else if (mymap2.find(id) != mymap2.end() && mymap2[id] != mac) {
      cout << "GOTCHA: " << id << " MAC address not consistent.\n";
    } else if (mymap1.find(mac) != mymap1.end() && mymap1[mac] == id) {
      cout << id << " signed in.\n";
    } else {
      cout << "GOTCHA: MAC address already occupied by " << mymap1[mac]
           << ".\n";
    }
  }
  return 0;
}
