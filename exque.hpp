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

using namespace std;

typedef class exque {
public:
	static int capacity;

	exque() {
		_front = 0;
		_tail = 0;
		_size = 0;
	}
	void push(int x) {
		_data[_tail] = x;
		_tail = (_tail + 1) % capacity;
		if(_size < capacity)
			_size++;
	}
	int pop() {
		if(_size == 0) {
			printf("Error!\n");
			exit(0);
		}
		int _tmp = _data[_front];
		_front = (_front + 1) % capacity;
		_size--;
		return _tmp;
	}
	void show() {
		for(int i = 0; i < _size; i++) {
			printf("%d ", _data[(_front+i)%capacity]);
		}
		printf("\n");
	}
	int front() {
		return _data[_front];
	}
private:
	int _front;
	int _tail;
	int _size;
	int _data[1024];
}exque;

int exque::capacity = 5;

int main() {
	exque x;
	int tmp;
	int cmd;
	while(1) {
		scanf("%d", &cmd);
		if(cmd == 1) {		
			scanf("%d", &tmp);
			x.push(tmp);
			printf("front: %d \n", x.front());
			x.show();
		}
		if(cmd == 2) {
			printf("%d\n", x.pop());
			printf("front: %d \n", x.front());
			x.show();
		}
	}
	return 0;
}
