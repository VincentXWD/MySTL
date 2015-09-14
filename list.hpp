#ifndef _KIRAI_LIST
#define _KIRAI_LIST

#include <cstdlib>

namespace kirai {
	template <class type>
	struct listnode {
		typedef listnode<type>* np;
		type _data;
		np pre;
		np next;
		listnode<type>() { pre = NULL; next = NULL; }
	};

	template <class type>
	class list {
		typedef listnode<type>* np;
		typedef listnode<type> nt;

	public:
		list<type>() { head = NULL; tail = NULL; _size = 0; }
		~list<type>() { clear(); }

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
		// to do
		bool insert(type, int);
		bool remove(int);
		type data(int);

	public:
		type &operator[] (const int&) const;

	protected:
		np head;
		np tail;

	private:
		int _size;
		void _init(type);
	};

	//operator overload
	template <class type>
	type &list<type>::operator[] (const int &num) const {
		np cur = head;
		for (int i = 0; i < num; i++) {
			cur = cur->next;
		}
		return cur->_data;
	}

	//functions
	template <class type>
	type list<type>::front() const {
		return head->_data;
	}

	template <class type>
	type list<type>::back() const {
		return tail->_data;
	}

	template <class type>
	bool list<type>::empty() const {
		return _size == 0 ? true : false;
	}

	template <class type>
	int list<type>::size() const {
		return _size;
	}

	template <class type>
	void list<type>::_init(type val) {
		if (head != NULL) {
			clear();
		}
		head = new nt;
		head->_data = val;
		tail = head;
		_size++;
	}

	template <class type>
	bool list<type>::push_back(type val) {
		if (_size == 0) {
			_init(val);
			return true;
		}
		np tmp = new nt;
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

	template <class type>
	bool list<type>::push_front(type val) {
		if (empty()) {
			_init(val);
			return true;
		}
		np tmp = new nt;
		if (tmp == NULL) {
			return false;
		}
		tmp->_data = val;
		tmp->next = head;
		head = tmp;
		_size++;
		return true;
	}

	template <class type>
	type list<type>::pop_back() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = tail;
		type tmp = cur->_data;
		tail = tail->pre;
		delete cur;
		_size--;
		return tmp;
	}

	template<class type>
	type list<type>::pop_front() {
		if (empty()) {
			exit(EXIT_FAILURE);
		}
		np cur = head;
		type tmp = cur->_data;
		head = head->next;
		delete cur;
		_size--;
		cur = head;
		return tmp;
	}

	template <class type>
	void list<type>::clear() {
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

	// to do
	template <class type>
	bool list<type>::insert(type val, int pos) {
		if (pos >= _size || pos < 0) {
			return false;
		}
		np cur = head;
		for (int i = 0; i != pos; i++) {
			cur = cur->next;
		}
		np tmp = new nt;
		cur = cur->pre;
		tmp->next = cur->next;
		cur->next->pre = tmp;
		tmp->pre = cur;
		cur->next = tmp;
		tmp->_data = val;
		_size++;
		return true;
	}

	template <class type>
	bool list<type>::remove(int pos) {
		np cur = head;
		if (cur->next == NULL || pos >= _size || pos < 0) {
			return false;
		}
		for (int i = 0; i != pos + 1; i++) {
			cur = cur->next;
		}
		np tmp = cur;
		cur = cur->pre;
		np del = cur;
		cur = cur->pre;
		cur->next = tmp;
		tmp->pre = cur;
		delete del;
		_size--;
		return true;
	}

	template <class type>
	type list<type>::data(int pos) {
		np cur = &head;
		for (int i = 0; i < pos; i++){
			cur = cur->next;
		}
		return cur->_data;
	}
}
#endif
