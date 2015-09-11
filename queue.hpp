#ifndef _KIRAI_QUEUE
#pragma once

#include <cstdlib>

namespace kirai {
	template <class Type>
	struct Node {
		typedef Node<Type>* NP;
		Type data;
		NP next;
		int pos;
		Node<Type>() { next = NULL; }
	};

	template <class Type>
	class queue {
		typedef Node<Type>* NP;
		typedef Node<Type> NT;

	public:
		queue<Type>() { head = NULL; tail = NULL; _size = 0; }
		~queue<Type>() { clear(); }

	public:
		bool push_back(Type);
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
		void _clear(NP);
	};

	template <class Type>
	void queue<Type>::_clear(NP cur) {
		if (cur == NULL) {
			return;
		}
		_clear(cur->next);
		delete cur;
	}

	template <class Type>
	Type queue<Type>::front() const {
		return head->data;
	}

	template <class Type>
	Type queue<Type>::back() const {
		return tail->data;
	}

	template <class Type>
	bool queue<Type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class Type>
	int queue<Type>::size() const {
		return _size;
	}

	template <class Type>
	void queue<Type>::_init(Type val) {
		if (head != NULL) {
			clear();
		}
		head = new NT;
		head->data = val;
		tail = head;
		_size++;
	}

	template <class Type>
	bool queue<Type>::push_back(Type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = tmp;
		tail = tail->next;
		_size++;
		return true;
	}

	template<class Type>
	Type queue<Type>::pop_front() {
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

	template<class Type>
	void queue<Type>::clear() {
		_clear(head);
		head = NULL;
		_size = 0;
	}
}
#endif
