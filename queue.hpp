#ifndef _KIRAI_QUEUE
#define _KIRAI_QUEUE

#pragma once

#include <cstdlib>

namespace kirai {
	template <class type>
	struct queuenode {
		typedef queuenode<type>* np;
		type data;
		np next;
		queuenode<type>() { next = NULL; }
	};

	template <class type>
	class queue {
		typedef queuenode<type>* np;
		typedef queuenode<type> nt;

	public:
		queue<type>() { head = NULL; tail = NULL; _size = 0; }
		~queue<type>() { clear(); }

	public:
		bool push_back(type);
		type pop_front();
		void clear();
		bool empty() const;
		int size() const;
		type front() const;
		type back() const;

	protected:
		np head;
		np tail;

	private:
		int _size;
		void _init(type);
		void _clear(np);
	};

	template <class type>
	void queue<type>::_clear(np cur) {
		if (cur == NULL) {
			return;
		}
		_clear(cur->next);
		delete cur;
	}

	template <class type>
	type queue<type>::front() const {
		return head->data;
	}

	template <class type>
	type queue<type>::back() const {
		return tail->data;
	}

	template <class type>
	bool queue<type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class type>
	int queue<type>::size() const {
		return _size;
	}

	template <class type>
	void queue<type>::_init(type val) {
		if (head != NULL) {
			clear();
		}
		head = new nt;
		head->data = val;
		tail = head;
		_size++;
	}

	template <class type>
	bool queue<type>::push_back(type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		np tmp = new nt;
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

	template<class type>
	type queue<type>::pop_front() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = head;
		type tmp = cur->data;
		head = head->next;
		delete cur;
		_size--;
		return tmp;
	}

	template<class type>
	void queue<type>::clear() {
		_clear(head);
		head = NULL;
		_size = 0;
	}
}
#endif
