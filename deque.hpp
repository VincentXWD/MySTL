#ifndef _KIRAI_DEQUE
#define _KIRAI_DEQUE

#include <cstdlib>

namespace kirai {
	template <class type>
	struct node {
		typedef node<type>* np;
		type data;
		np pre;
		np next;
		int pos;
		node<type>() { pre = NULL; next = NULL; }
	};

	template <class type>
	class deque {
		typedef node<type>* np;
		typedef node<type> NT;

	public:
		deque<type>() { head = NULL; tail = NULL; _size = 0; }
		~deque<type>() { clear(); }

	public:
		bool push_back(type);
		bool push_front(type);
		type pop_back();
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
	};

	template <class type>
	type deque<type>::front() const {
		return head->data;
	}

	template <class type>
	type deque<type>::back() const {
		return tail->data;
	}

	template <class type>
	bool deque<type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class type>
	int deque<type>::size() const {
		return _size;
	}

	template <class type>
	void deque<type>::_init(type val) {
		if (head != NULL) {
			clear();
		}
		head = new NT;
		head->data = val;
		tail = head;
		_size++;
	}

	template <class type>
	bool deque<type>::push_back(type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		np tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->pre = tail;
		tail->next = tmp;
		tail = tmp;
		_size++;
		return true;
	}

	template <class type>
	bool deque<type>::push_front(type val) {
		if (empty()) {
			_init(val);
			return true;
		}
		np tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->data = val;
		tmp->next = head;
		head = tmp;
		_size++;
		return true;
	}

	template <class type>
	type deque<type>::pop_back() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = tail;
		type tmp = cur->data;
		tail = tail->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class type>
	type deque<type>::pop_front() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = &head;
		type tmp = cur->data;
		head = head->next;
		delete cur;
		_size--;
		return tmp;
	}

	template <class type>
	void deque<type>::clear() {
		if (_size == 0) {
			return;
		}
		np cur = tail;
		np tmp = tail;
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
