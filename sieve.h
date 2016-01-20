#ifndef SIEVE_H
#define SIEVE_H
#include <string.h>
#include <vector>
using namespace std;

int flag[1<<24];

#define isSet(x) ((flag[x>>5] >> (0x1F&x)) & 1)
#define set(x) flag[x>>5] |= (1 << (0x1F&x))

vector<int> sieve(int n) {
	memset(flag, 0, sizeof(flag));
	for (int i = 4; i < n; i += 2) {
		set(i);
	}
	for (int i = 3; i*i < n; i += 2) {
		if (!isSet(i)) {
			for (int j = i*i; j < n; j += 2*i) {
				set(j);
			}
		}
	}
	vector<int> prime(1, 2);
	for (int i = 3; i < n; i += 2) {
		if (!isSet(i)) {
			prime.push_back(i);
		}
	}
	return prime;
}
#endif
