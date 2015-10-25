#ifndef _KIRAI_BST
#define _KIRAI_BST
#include "queue"

namespace kirai {
	template<class type>
	struct avlnode {
		typedef avlnode<type>* np;
		type _data;
		int height;
		np left;
		np right;
		avlnode<type>() { height = 0; left = NULL; right = NULL; }
		avlnode<type>(const int& x) : _data(x) { avlnode<type>(); }
	};

	template<class type>
	class avl {
		typedef avlnode<type>* np;
		typedef avlnode<type> nt;

	public:
		avl() { _root = NULL; }
		~avl() = default;

	public:
		//Interfaces
		bool empty() const { return _root == NULL; }
		void insert(const type&);
		bool search(const type& x) const { return _search(_root, x) ? true : false; }
		bool remove(const type&);
		type min() const { return _min(_root)->_data; }
		type max() const { return _max(_root)->_data; }
		void bfs(void(*)(type));

	public:
		int height() { return empty() ? -1 : _root->height; }

	public:
		void preorder(void(*visit)(type)) { _preorder(_root, visit); };
		void inorder(void(*visit)(type)) { _inorder(_root, visit); };
		void postorder(void(*visit)(type)) { _postorder(_root, visit); };

	protected:
		int _height(np cur) { return _empty(cur) ? -1 : cur->height; }

	protected:
		avlnode<type>* _search(np, const type&);
		avlnode<type>* _min(np) const;
		avlnode<type>* _max(np) const;
		void _setnull(np, np);
		void _insert(np, const type&);
		void _inorder(np, void(*)(type));
		void _postorder(np, void(*)(type));
		void _preorder(np, void(*)(type));
		type _remove(np);
		type __remove(np);
		bool _empty(np cur) const { return cur == NULL; }

	protected:
		bool _isroot(np cur) { return (cur == _root); }
		static bool _isleaf(np cur) { return (cur->left == NULL && cur->right == NULL); }

	private:
		np _root;
	};

	template<class type>
	void avl<type>::bfs(void(*visit)(type data)) {
		kirai::queue<np> q;
		q.push_back(_root);
		while (!q.empty()) {
			np tmp = q.front();
			visit(q.front()->_data);
			printf("%d ", tmp->height);
			if (q.front()->left)		q.push_back(tmp->left);
			if (q.front()->right)	q.push_back(tmp->right);
			q.pop_front();
		}
	}

	template <class type>
	void avl<type>::_setnull(np cur, np aim) {
		if (cur->left == aim) {
			cur->left = NULL;
			return;
		}
		if (cur->right == aim) {
			cur->right = NULL;
			return;
		}
		if (aim->_data > cur->_data) _setnull(cur->right, aim);
		if (aim->_data < cur->_data) _setnull(cur->left, aim);
	}

	template <class type>
	avlnode<type>* avl<type>::_min(np cur) const {
		if (empty()) {
			return NULL;
		}
		while (cur->left) {
			cur = cur->left;
		}
		return cur;
	}

	template <class type>
	avlnode<type>* avl<type>::_max(np cur) const {
		if (empty()) {
			return NULL;
		}
		while (cur->right) {
			cur = cur->right;
		}
		return cur;
	}

	template <class type>
	avlnode<type>* avl<type>::_search(np cur, const type& x) {
		if (cur == NULL) {
			return NULL;
		}
		if (cur->_data == x) {
			return cur;
		}
		else if (x > cur->_data) {
			return _search(cur->right, x);
		}
		else {
			return _search(cur->left, x);
		}
	}

	template <class type>
	bool avl<type>::remove(const type& x) {
		np cur = _search(_root, x);
		if (cur == NULL) {
			return false;
		}
		_remove(cur);
		return true;
	}

	template <class type>
	type avl<type>::_remove(np cur) {
		np tmp;
		type x;
		if (_isleaf(cur)) {
			x = cur->_data;
			if (!_isroot(cur)) {
				_setnull(_root, cur);
				delete(cur);
				cur = NULL;
			}
			return x;
		}
		else {
			tmp = cur->left ? _max(cur->left) : _min(cur->right);
			x = cur->_data;
			cur->_data = _remove(tmp);
			return x;
		}
	}

	template <class type>
	void avl<type>::insert(const type& x) {
		if (empty()) {
			np tmp = new nt();
			_root = tmp;
			_root->_data = x;
			_root->height = 0;
			return;
		}
		_insert(_root, x);
		return;
	}

	template <class type>
	void avl<type>::_insert(np cur, const type& x) {
		if (x > cur->_data) {
			if (cur->right == NULL) {
				np tmp = new nt();
				cur->right = tmp;
				cur->height++;
				tmp->_data = x;
				return;
			}
			else {
				_insert(cur->right, x);
			}
			cur->height = (
				_height(cur->left) > _height(cur->right) ?
				_height(cur->left) : _height(cur->right)
			) + 1;
		}
		if (x < cur->_data) {
			if (cur->left == NULL) {
				np tmp = new nt();
				cur->left = tmp;
				cur->height++;
				tmp->_data = x;
				return;
			}
			else {
				_insert(cur->left, x);
			}
			cur->height = (
				_height(cur->left) > _height(cur->right) ?
				_height(cur->left) : _height(cur->right)
			) + 1;
		}
	}

	template <class type>
	void avl<type>::_preorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			(*visit)(cur->_data);
			_preorder(cur->left, visit);
			_preorder(cur->right, visit);
		}
	}

	template <class type>
	void avl<type>::_inorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			_inorder(cur->left, visit);
			(*visit)(cur->_data);
			_inorder(cur->right, visit);
		}
	}

	template <class type>
	void avl<type>::_postorder(np cur, void(*visit)(type data)) {
		if (cur != NULL) {
			_postorder(cur->left, visit);
			_postorder(cur->right, visit);
			(*visit)(cur->_data);
		}
	}
}

#endif
