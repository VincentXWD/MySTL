#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include "avl.hpp"

using namespace std;

void show(int x) {
	printf("%d ", x);
}
void foo(int x) {
	
}
int main() {
	freopen("in", "r", stdin);
	kirai::avl<int> a;
	int tmp;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		a.insert(tmp);
		a.bfs(foo);
		printf("\n");
	}
	a.remove(6);
	printf("\n");
	a.preorder(show);
	printf("\n");
	a.bfs(foo);
	printf("\n");

	//a.insert(26);
	//a.inorder(show);
	//printf("\n");
	//a.preorder(show);
	//printf("\n");
	//a.postorder(show);
	//printf("\n");
	//a.bfs(foo);
	//printf("\n");
	//a.remove(6);
	//a.bfs(foo);
	//printf("\n");
}