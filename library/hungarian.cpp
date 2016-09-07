typedef int type;

const int N = 505;
type inf = 1<<29;

type cost[N][N];
type lx[N], ly[N];
int xy[N], yx[N];
bool S[N], T[N];
int slack[N], slackx[N];
int Q[N], pre[N];
int n;

void init() {
  fill(xy, xy+n, -1);
  fill(yx, yx+n, -1);
  fill(ly, ly+n, 0);
  rep(x, n) {
    lx[x] = 0;
    rep(y, n) {
      lx[x] = max(lx[x], cost[x][y]);
    }
  }
}

void update_labels() {
  type delta = inf;
  rep(y, n) {
    if (!T[y]) {
      delta = min(delta, slack[y]);
    }
  }
  rep(x, n) {
    if (S[x]) {
      lx[x] -= delta;
    }
  }
  rep(y, n) {
    if (T[y]) {
      ly[y] += delta;
    }
  }
  rep(y, n) {
    if (!T[y]) {
      slack[y] -= delta;
    }
  }
}

void add_to_tree(int x, int prex) {
  S[x] = true;
  pre[x] = prex;
  rep(y, n) {
    if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
      slack[y] = lx[x] + ly[y] - cost[x][y];
      slackx[y] = x;
    }
  }
}

void augment(int m) {
  if (m == 0) {
    return;
  }
  int fr = 0, bk = 0, root;
  fill(S, S+n, false);
  fill(T, T+n, false);
  fill(pre, pre+n, -1);
  rep(x, n) {
    if (xy[x] == -1) {
      S[x] = true;
      Q[bk ++] = root = x;
      pre[x] = -2;
      break;
    }
  }
  rep(y, n) {
    slack[y] = lx[root] + ly[y] - cost[root][y];
    slackx[y] = root;
  }
  try {
    while (true) {
      while (fr < bk) {
        int x = Q[fr ++];
        rep(y, n) {
          if (lx[x]+ly[y] == cost[x][y] && !T[y]) {
            if (yx[y] == -1) {
              throw mp(x, y);
            }
            T[y] = true;
            Q[bk ++] = yx[y];
            add_to_tree(yx[y], x);
          }
        }
      }
      update_labels();
      fr = bk = 0;
      rep(y, n) {
        if (!T[y] && slack[y] == 0) {
          if (yx[y] == -1) {
            throw mp(slackx[y], y);
          } else {
            T[y] = true;
            if (!S[yx[y]]) {
              Q[fr ++] = yx[y];
              add_to_tree(yx[y], slackx[y]);
            }
          }
        }
      }
    }
  } catch (pair <int, int> e) {
    for (int cx = e.x, cy = e.y, ty; cx != -2; cx = pre[cx], cy = ty) {
      ty = xy[cx];
      yx[cy] = cx;
      xy[cx] = cy;
    }
    augment(m-1);
  }
}

type hungarian() {
  type ret = 0;
  init();
  augment(n);
  rep(x, n) {
    ret += cost[x][xy[x]];
  }
  return ret;
}
