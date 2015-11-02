#ifndef _KIRAI_PRIORITY_QUEUE
#define _KIRAI_PRIORITY_QUEUE

namespace kirai {
	template<class type>
	class priority_queue {
	public:
		priority_queue();
		~priority_queue();
	
	public:
		int size() const;
		void set_heap_size(int x);
		void clear();
		bool push(type);
		type top() const;
		bool pop();
		bool empty();

	private:
		const int max_size = 100010;
		static int heap_size;
		int _size;
		type *_data;
	};

	template<class type>
	int priority_queue<type>::heap_size = 10000;

	template<class type>
	priority_queue<type>::priority_queue() {
		_size = 0;
		_data = new type[heap_size];
		memset(_data, 0, sizeof(_data));
		_data[0] = -0x7f7f7f7f;
	}
	
	template<class type>
	priority_queue<type>::~priority_queue() {
		delete _data;
		_data = NULL;
	}

	template<class type>
	int priority_queue<type>::size() const { return _size; }

	template<class type>
	void priority_queue<type>::clear() {
		_size = 0; 
		memset(_data, 0, sizeof(_data));
	}
	
	template<class type>
	bool priority_queue<type>::empty() { return _size == 0; }

	template<class type>
	bool priority_queue<type>::push(type x) {
		if (_size > heap_size) {
			return false;
		}
		int pos = ++_size;
		for (; _data[pos >> 1] > x; pos >>= 1) {
			_data[pos] = _data[pos >> 1];
		}
		_data[pos] = x;
		return true;

	}

	template<class type>
	type priority_queue<type>::top() const {
		return !_size ? _data[0] : _data[1];
	}

	template<class type>
	bool priority_queue<type>::pop() {
		if (_size == 0) {
			return false;
		}
		int pos, child = 1;
		type last = _data[_size--];
		for (pos = 1; (pos << 1) <= _size; pos=child) {
			child = pos << 1;
			if (child != _size && _data[child + 1] < _data[child]) {
				++child;
			}
			if (last > _data[child]) {
				_data[pos] = _data[child];
			}
			else {
				break;
			}
		}
		_data[pos] = last;
		return true;
	}

}


#endif
