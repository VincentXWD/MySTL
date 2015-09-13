#ifndef _KIRAI_LIST
#pragma once

#include <cstdlib>

namespace kirai {
	template <class Type>
	struct Node {
		typedef Node<Type>* NP;
		Type _data;
		NP pre;
		NP next;
		Node<Type>() { pre = NULL; next = NULL; }
	};

	template <class Type>
	class list {
		typedef Node<Type>* NP;
		typedef Node<Type> NT;

	public:
		list<Type>() { head = NULL; tail = NULL; _size = 0; }
		~list<Type>() { clear(); }

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
		// to do
		bool insert(Type, int);
		bool remove(int);
		Type data(int);

	public:
		Type &operator[] (const int&) const;

	protected:
		NP head;
		NP tail;

	private:
		int _size;
		void _init(Type);
	};

	//operator overload
	template <class Type>
	Type &list<Type>::operator[] (const int &num) const {
		NP cur = head;
		for (int i = 0; i < num; i++) {
			cur = cur->next;
		}
		return cur->_data;
	}

	//functions
	template <class Type>
	Type list<Type>::front() const {
		return head->_data;
	}

	template <class Type>
	Type list<Type>::back() const {
		return tail->_data;
	}

	template <class Type>
	bool list<Type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class Type>
	int list<Type>::size() const {
		return _size;
	}

	template <class Type>
	void list<Type>::_init(Type val) {
		if (head != NULL) {
			clear();
		}
		head = new NT;
		head->_data = val;
		tail = head;
		_size++;
	}

	template <class Type>
	bool list<Type>::push_back(Type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->_data = val;
		tmp->pre = tail;
		tail->next = tmp;
		tail = tmp;
		_size++;
		return true;
	}

	template <class Type>
	bool list<Type>::push_front(Type val) {
		if (empty()) {
			_init(val);
			return true;
		}
		NP tmp = new NT;
		if (tmp == NULL) {
			return false;
		}
		tmp->_data = val;
		tmp->next = head;
		head = tmp;
		_size++;
		return true;
	}

	template <class Type>
	Type list<Type>::pop_back() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		NP cur = tail;
		Type tmp = cur->_data;
		tail = tail->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class Type>
	Type list<Type>::pop_front() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		NP cur = head;
		Type tmp = cur->_data;
		head = head->next;
		delete cur;
		_size--;
		cur = head;
		return tmp;
	}

	template <class Type>
	void list<Type>::clear() {
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

	// to do
	template <class Type>
	bool list<Type>::insert(Type val, int pos) {
		if (pos >= _size || pos < 0) {
			return false;
		}
		NP cur = head;
		for (int i = 0; i != pos; i++) {
			cur = cur->next;
		}
		NP tmp = new NT;
		cur = cur->pre;
		tmp->next = cur->next;
		cur->next->pre = tmp;
		tmp->pre = cur;
		cur->next = tmp;
		tmp->_data = val;
		_size++;
		return true;
	}

	template <class Type>
	bool list<Type>::remove(int pos) {
		NP cur = head;
		if (cur->next == NULL || pos >= _size || pos < 0) {
			return false;
		}
		for (int i = 0; i != pos + 1; i++) {
			cur = cur->next;
		}
		NP tmp = cur;
		cur = cur->pre;
		NP del = cur;
		cur = cur->pre;
		cur->next = tmp;
		tmp->pre = cur;
		delete del;
		_size--;
		return true;
	}

	template <class Type>
	Type list<Type>::data(int pos) {
		NP cur = head;
		for (int i = 0; i < pos; i++){
			cur = cur->next;
		}
		return cur->_data;
	}

}
#endif
