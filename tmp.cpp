#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include "bst"

using namespace std;

void show(int x) {
	printf("%d ", x);
}
int main() {
	kirai::bst<int> a;
	int tmp;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &tmp);
		a.insert(tmp);
	}
	a.postorder(show);
}