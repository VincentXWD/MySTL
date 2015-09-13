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
#include "list"

using namespace std;

int main() {
	kirai::list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i);
	}
	for (int i = 0; i < lst.size(); i++) {
		cout << lst.data(i) << " ";
	}
	cout << endl;
	lst.insert(5, 2);
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
	lst.remove(2);
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
}