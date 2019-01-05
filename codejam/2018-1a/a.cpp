#include <iostream>
#include <cstring>

using namespace std;

class WaffleChopper {
public:
  WaffleChopper(
      const short R, const short C,
      const short H, const short V,
      char ** const &board
  ) : R(R), C(C), H(H), V(V) {
    buf = new short * [R+1];
    for (short i = 0; i <= R; i ++) buf[i] = new short [C+1];
    cols = new short [V+2];
    cols[0] = 0;
    cols[V+1] = C;

    memset(buf[0], 0, sizeof(short) * (C+1));
    for (short i = 0; i < R; i ++) {
      buf[i+1][0] = 0;
      for (short j = 0; j < C; j ++) {
        short now = board[i][j] == '@' ? 1 : 0;
        buf[i+1][j+1] = buf[i][j+1] + buf[i+1][j] - buf[i][j] + now;
      }
    }
  }

  ~WaffleChopper() {
    for (short i = 0; i <= R; i ++) delete [] buf[i];
    delete [] buf;
    delete [] cols;
  }

  bool is_possible() {
    if (buf[R][C] % ((H+1) * (V+1)) != 0) return false;
    if (buf[R][C] == 0) return true;
    if (!put_vertical()) return false;
    return put_horizontal();
  }

private:
  short R, C, H, V;
  short ** buf;
  short * cols;

  bool put_vertical() {
    short col_chips = buf[R][C] / (V+1);
    for (short j = 1, l = 0, c = 1; j < C && c <= V; j ++) {
      int s = sub_sum(1, l+1, R, j);
      if (s > col_chips) return false;
      if (s == col_chips) {
        cols[c ++] = j;
        l = j;
      }
    }
    return true;
  }

  bool put_horizontal() {
    short c = 0;
    for (short i = 1, l = 0; i <= R; i ++) {
      if (check_if_row_range_satisfies(l+1, i)) {
        c ++;
        l = i;
      }
    }
    return c == H+1;
  }

  bool check_if_row_range_satisfies(const short l, const short r) {
    short unit_chips = buf[R][C] / (H+1) / (V+1);
    for (short c = 1; c <= V+1; c ++) {
      if (sub_sum(l, cols[c-1]+1, r, cols[c]) != unit_chips) return false;
    }
    return true;
  }

  short sub_sum(const short a, const short b, const short c, const short d) {
    return buf[c][d] - buf[a-1][d] - buf[c][b-1] + buf[a-1][b-1];
  }
};

int main() {
  short T;
  cin >> T;
  for (short t = 1; t <= T; t ++) {
    short R, C, H, V;
    cin >> R >> C >> H >> V;
    char ** board = new char * [R];
    for (int i = 0; i < R; i ++) {
      board[i] = new char [C+1];
      cin >> board[i];
    }
    WaffleChopper chopper(R, C, H, V, board);
    cout << "Case #" << t << ": " << (chopper.is_possible() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    for (int i = 0; i < R; i ++) {
      delete [] board[i];
    }
    delete [] board;
  }
  return 0;
}
