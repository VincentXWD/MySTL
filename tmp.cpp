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
#include "stack"

using namespace std;

int main() {
	kirai::list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i*2+1);
	}
	cout << endl;
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
	int t = 3;
	while(t--)	cout << lst.remove(2) << " ";
	cout << endl;
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << " ";
	}
	cout << endl;
}