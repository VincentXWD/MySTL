#ifndef _KIRAI_BST
#define _KIRAI_BST
#include "queue"

namespace kirai {
	template<class type>
	struct bstnode {
		typedef bstnode<type>* np;
		type _data;
		np pre;
		np left;
		np right;
		bstnode<type>() { pre = NULL; left = NULL; right = NULL; }
		bstnode<type>(const int& x) : _data(x) { bstnode<type>(); }
	};

	template<class type>
	class bst {
		typedef bstnode<type>* np;
		typedef bstnode<type> nt;

	public:
		bst() { _root = NULL; }
		~bst() = default;
		bool empty() const { return _root == NULL; }
		void insert(const type&);
		bool search(const type& x) const { return _search(_root, x) ? true : false; }
		bool remove(const type&);
		type min() const { return _min(_root)->_data; }
		type max() const { return _max(_root)->_data; }
		void bfs(void(*)(type));

	public:
		void preorder(void(*visit)(type)) { _preorder(_root, visit); };
		void inorder(void(*visit)(type)) { _inorder(_root, visit); };
		void postorder(void(*visit)(type)) { _postorder(_root, visit); };

	protected:
		bstnode<type>* _search(np, const type&);
		bstnode<type>* _min(np) const;
		bstnode<type>* _max(np) const;
		void _insert(np, const type&);
		void _inorder(np, void(*)(type));
		void _postorder(np, void(*)(type));
		void _preorder(np, void(*)(type));
		type _remove(np);
		type __remove(np);

	protected:
		static bool _isroot(np cur) { return (cur->pre == NULL); }
		static bool _isleaf(np cur) { return (cur->left == NULL && cur->right == NULL); }

	private:
		np _root;
	};

	template<class type>
	void bst<type>::bfs(void(*visit)(type data)) {
		kirai::queue<np> q;
		q.push_back(_root);
		while (!q.empty()) {
			np tmp = q.front();
			visit(q.front()->_data);
			if(q.front()->left)	q.push_back(tmp->left);
			if(q.front()->right)	q.push_back(tmp->right);
			q.pop_front();
		}
	}

	template <class type>
	bstnode<type>* bst<type>::_min(np cur) const {
		if (empty()) {
			return NULL;
		}
		while (cur->left) {
			cur = cur->left;
		}
		return cur;
	}

	template <class type>
	bstnode<type>* bst<type>::_max(np cur) const {
		if (empty()) {
			return NULL;
		}
		while (cur->right) {
			cur = cur->right;
		}
		return cur;
	}

	template <class type>
	bstnode<type>* bst<type>::_search(np cur, const type& x) {
		if (cur == NULL) {
			return NULL;
		}
		if (cur->_data == x) {
			return cur;
		}
		else if (x >= cur->_data) {
			return _search(cur->right, x);
		}
		else {
			return _search(cur->left, x);
		}
	}

	template <class type>
	bool bst<type>::remove(const type& x) {
		np cur = _search(_root, x);
		if (cur == NULL) {
			return false;
		}
		_remove(cur);
		return true;
	}

	template <class type>
	type bst<type>::_remove(np cur) {
		np tmp;
		type x;
		if(_isleaf(cur)) {
			return __remove(cur);
		}
		else {
			/*if (cur->left != NULL) {
				tmp = _max(cur->left);
			}
			else {
				tmp = _min(cur->right);
			}*/
			tmp = cur->left ? _max(cur->left) : _min(cur->right);
			x = cur->_data;
			cur->_data = _remove(tmp);
			return x;
		}
	}

	template <class type>
	type bst<type>::__remove(np cur) {
		type x = cur->_data;
		np pre = cur->pre;
		if (!_isroot(cur)) {
			if (pre->left == cur) {
				pre->left = NULL;
			}
			else {
				pre->right = NULL;
			}
		}
		delete cur;
		return x;
	}

	template <class type>
	void bst<type>::insert(const type& x) {
		if (empty()) {
			np tmp = new nt;
			_root = tmp;
			_root->_data = x;
			return;
		}
		_insert(_root, x);
		return;
	}

	template <class type>
	void bst<type>::_insert(np cur, const type& x) {
		if (x >= cur->_data) {
			if (cur->right == NULL) {
				np tmp = new nt;
				cur->right = tmp;
				cur->right->pre = cur;
				tmp->_data = x;
				return;
			}
			else {
				_insert(cur->right, x);
			}
		}
		else {
			if (cur->left == NULL) {
				np tmp = new nt;
				cur->left = tmp;
				cur->left->pre = cur;
				tmp->_data = x;
				return;
			}
			else {
				_insert(cur->left, x);
			}
		}
	}

	template <class type>
	void bst<type>::_preorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			(*visit)(cur->_data);
			_preorder(cur->left, visit);
			_preorder(cur->right, visit);
		}
	}

	template <class type>
	void bst<type>::_inorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			_inorder(cur->left, visit);
			(*visit)(cur->_data);
			_inorder(cur->right, visit);
		}
	}

	template <class type>
	void bst<type>::_postorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			_postorder(cur->left, visit);
			_postorder(cur->right, visit);
			(*visit)(cur->_data);
		}
	}
}

#endif
