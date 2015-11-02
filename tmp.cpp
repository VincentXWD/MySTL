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
#include <bitset>
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
	freopen("in", "r", stdin);
	int n, tmp;
	kirai::bst<int> root;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			root.insert(tmp);
		}
		printf("Preorder traversal:\n");
		root.preorder(show);
		printf("\nInorder traversal:\n");
		root.inorder(show);
		printf("\nPostorder traversal:\n");
		root.postorder(show);
		printf("\nBreadth first search:\n");
		root.bfs(show);
		printf("\nDepth first search:\n");
		root.dfs(show);
		printf("\n\n");
		root.clear();
	}
	return 0;
}
