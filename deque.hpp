#ifndef _KIRAI_DEQUE
#pragma once

#include <cstdlib>

namespace kirai {
	template <class Type>
	struct Node {
		typedef Node<Type>* NP;
		Type data;
		NP pre;
		NP next;
		int pos;
		Node<Type>() { pre = NULL; next = NULL; }
	};

	template <class Type>
	class deque {
		typedef Node<Type>* NP;
		typedef Node<Type> NT;

	public:
		deque<Type>() { head = NULL; tail = NULL; _size = 0; }
		~deque<Type>() { clear(); }

	public:
		bool push_back(Type);
		bool push_front(Type);
		Type pop_back();
		Type pop_front();
		void clear();
		bool empty() const;
		int size() const;
		Type front() const;
		Type back() const;
	protected:
		NP head;
		NP tail;

	private:
		int _size;
		void _init(Type);
	};

	template <class Type>
	Type deque<Type>::front() const {
		return head->data;
	}

	template <class Type>
	Type deque<Type>::back() const {
		return tail->data;
	}

	template <class Type>
	bool deque<Type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class Type>
	int deque<Type>::size() const {
		return _size;
	}

	template <class Type>
	void deque<Type>::_init(Type val) {
		if (head != NULL) {
			clear();
		}
		head = new NT;
		head->data = val;
		tail = head;
		_size++;
	}

	template <class Type>
	bool deque<Type>::push_back(Type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->pre = tail;
		tail = tmp;
		_size++;
		return true;
	}

	template <class Type>
	bool deque<Type>::push_front(Type val) {
		if (empty()) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->next = head;
		head = tmp;
		_size++;
		return true;
	}

	template <class Type>
	Type deque<Type>::pop_back() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		NP cur = tail;
		Type tmp = cur->data;
		tail = tail->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class Type>
	Type deque<Type>::pop_front() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		NP cur = head;
		Type tmp = cur->data;
		head = head->next;
		delete cur;
		_size--;
		return tmp;
	}

	template <class Type>
	void deque<Type>::clear() {
		if (_size == 0) {
			return;
		}
		NP cur = tail;
		NP tmp = tail;
		while (cur->next != NULL) {
			cur = cur->pre;
			delete tmp;
			tmp = cur;
		}
		delete cur->pre;
		_size = 0;
	}
}
#endif
