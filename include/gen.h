#include <cstdlib>
#include <cstring>

char * gen_string(const int len, char * const chars) {
  char * ans = new char [len+1];
  ans[len+1] = 0;
  int l = strlen(chars);
  if (l == 0) {
    for (int i = 0; i < len; i ++) ans[i] = rand()%255 + 1;
    return ans;
  }
  for (int i = 0; i < len; i ++) {
    ans[i] = chars[rand()%l];
  }
  return ans;
}

int gen_int(const int l, const int r) {
  if (r < l) return l;
  return rand() % (r-l+1) + l;
}
