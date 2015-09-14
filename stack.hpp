#ifndef _KIRAI_STACK
#define _KIRAI_STACK

#include <cstdlib>

namespace kirai {
	template <class type>
	struct stacknode {
		typedef stacknode<type>* np;
		type data;
		np pre;
		stacknode<type>() { pre = NULL; }
	};

	template <class type>
	class stack {
		typedef stacknode<type>* np;
		typedef stacknode<type> nt;

	public:
		stack<type>() { _top = NULL; _size = 0; }
		~stack<type>() { clear(); }

	public:
		bool push(type);
		type pop();
		void clear();
		bool empty() const;
		int size() const;
		type top() const;

	protected:
		np _top;
		int _size;

	private:
		void _init(type);
		void _clear(np);
	};

	template <class type>
	type stack<type>::top() const {
		return _top->data;
	}
	template <class type>
	bool stack<type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class type>
	void stack<type>::_clear(np cur) {
		if (cur == NULL) {
			return;
		}
		_clear(cur->pre);
		delete cur;
	}

	template <class type>
	int stack<type>::size() const {
		return _size;
	}

	template <class type>
	void stack<type>::_init(type val) {
		if (_top != NULL) {
			clear();
		}
		_top = new nt;
		_top->data = val;
		_size++;
	}

	template <class type>
	bool stack<type>::push(type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		np tmp = new nt;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->pre = _top;
		_top = tmp;
		_size++;
		return true;
	}

	template <class type>
	type stack<type>::pop() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = _top;
		type tmp = cur->data;
		_top = _top->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class type>
	void stack<type>::clear() {
		_clear(_top);
		_top = NULL;
		_size = 0;
	}
}
#endif