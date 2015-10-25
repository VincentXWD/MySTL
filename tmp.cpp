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

}

int main() {
	kirai::avl<int> a;
	a.insert(8);
	a.insert(1);
	a.insert(13);
	a.insert(4);
	a.insert(2);
	cout << a.height();
	a.bfs(show);
}