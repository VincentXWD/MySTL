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
#include "avl"

using namespace std;

void show(int x) {
	printf("%d ", x);
}
void foo(int x) {

}

int main() {
	kirai::avl<int> a;
	a.insert(8);
	a.insert(1);
	a.insert(13);
	a.insert(13);
	a.insert(4);
	a.inorder(show);
	cout << endl;
	a.bfs(foo);
}