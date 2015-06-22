#include <iostream>
#include <queue>
#include <cstring>
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool map[30][30];
bool visit[30][30];
int m, n;
struct node {
  int _x, _y, step;
  node(int x, int y, int s) : _x(x), _y(y), step(s) {}
  node() {}
  bool ok() {
    return _x >= 0 && _x < m && _y >= 0 && _y < n;
  }
};
node sta, ed;
void bfs();
int main() {
  std::cin >> m >> n;
  std::string tmp;
  memset(map, false, sizeof(map));
  memset(visit, false, sizeof(visit));
  for (int i = 0; i < m; ++i) {
      std::cin >> tmp;
      for (int j = 0; j < n; ++j) {

        if (tmp[j] == 'S') {
          sta._x = i;
          sta._y = j;
          sta.step = 0;
          map[i][j] = true;
        } else if (tmp[j] == 'E') {
          ed._x = i;
          ed._y = j;
          ed.step = 0;
          map[i][j] = true;
        } else if (tmp[j] == '.') {
          map[i][j] = true;
        }
      }
  }
  bfs();
  return 0;
}
void bfs() {
  std::queue<node> buf;
  node tmp, now;
  buf.push(sta);
  visit[sta._x][sta._y] = true;
  while (!buf.empty()) {
    tmp = buf.front();
    if (tmp._x == ed._x && tmp._y == ed._y) {
      std::cout << tmp.step << std::endl;
      return;
    }
    buf.pop();
    for (int i = 0; i < 4; ++i) {
      now._x = tmp._x + dir[i][0];
      now._y = tmp._y + dir[i][1];
      now.step = tmp.step + 1;
      if (now.ok() && !visit[now._x][now._y] && map[now._x][now._y]) {
        visit[now._x][now._y] = true;
        buf.push(now);
      }
    }
  }
  std::cout << "-1\n";
}
