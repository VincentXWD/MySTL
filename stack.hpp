#ifndef _KIRAI_STACK
#pragma once

#include <cstdlib>

namespace kirai {
	template <class Type>
	struct Node {
		typedef Node<Type>* NP;
		Type data;
		NP pre;
		Node<Type>() { pre = NULL; }
	};

	template <class Type>
	class stack {
		typedef Node<Type>* NP;
		typedef Node<Type> NT;

	public:
		stack<Type>() { _top = NULL; _size = 0; }
		~stack<Type>() { clear(); }

	public:
		bool push(Type);
		Type pop();
		void clear();
		bool empty() const;
		int size() const;
		Type top() const;

	protected:
		NP _top;
		int _size;

	private:
		void _init(Type);
		void _clear(NP);
	};

	template <class Type>
	Type stack<Type>::top() const {
		return _top->data;
	}
	template <class Type>
	bool stack<Type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class Type>
	void stack<Type>::_clear(NP cur) {
		if (cur == NULL) {
			return;
		}
		_clear(cur->pre);
		delete cur;
	}

	template <class Type>
	int stack<Type>::size() const {
		return _size;
	}

	template <class Type>
	void stack<Type>::_init(Type val) {
		if (_top != NULL) {
			clear();
		}
		_top = new NT;
		_top->data = val;
		_size++;
	}

	template <class Type>
	bool stack<Type>::push(Type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->pre = _top;
		_top = tmp;
		_size++;
		return true;
	}

	template <class Type>
	Type stack<Type>::pop() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		NP cur = _top;
		Type tmp = cur->data;
		_top = _top->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class Type>
	void stack<Type>::clear() {
		_clear(_top);
		_top = NULL;
		_size = 0;
	}
}
#endif