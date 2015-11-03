#ifndef _KIRAI_BST
#define _KIRAI_BST
#include "queue"
#include "stack"
#include <iostream>
#include <cmath>

namespace kirai {
	template<class type>
	struct bstnode {
		typedef bstnode<type>* np;
		type _data;
		int height;
		int depth;
		np left;
		np right;
		bstnode<type>() { height = 0; depth = 0; left = NULL; right = NULL; }
		bstnode<type>(const int& x) : _data(x) { bstnode<type>(); }
	};

	template<class type>
	class bst {
		typedef bstnode<type>* np;
		typedef bstnode<type> nt;

	public:
		bst() { _root = NULL; }
		~bst() = default;

		//Interfaces
	public:
		bool empty() const { return _root == NULL; }
		void insert(const type&);
		bool search(const type& x) const { return _search(_root, x) ? true : false; }
		bool remove(const type&);
		type min() const { return _min(_root)->_data; }
		type max() const { return _max(_root)->_data; }
		void bfs(void(*)(type));
		void dfs(void(*)(type));

	public:
		int height() { return empty() ? -1 : _root->height; }

	public:
		void preorder(void(*visit)(type)) { _preorder(_root, visit); };
		void inorder(void(*visit)(type)) { _inorder(_root, visit); };
		void postorder(void(*visit)(type)) { _postorder(_root, visit); };
		void clear() { _clear(_root); _root = NULL; };
		friend std::ostream& operator<<(std::ostream& osu, const bst<type>& tree) {
			kirai::queue<bstnode<type>*> q;
			q.push_back(tree._root);
			int depth = tree._root->height;
			while (!q.empty()) {
				bstnode<type>* tmp = q.front();
				if (tmp->left)  q.push_back(tmp->left);
				if (tmp->right) q.push_back(tmp->right);
				q.pop_front();
				if (!q.empty() && q.front()->depth != tmp->depth) {
					std::cout << std::endl;
					depth--;
				}
				//std::cout << tmp->depth << " ";
			}
			return osu;
		}

	protected:
		int _height(np cur) { return _empty(cur) ? -1 : cur->height; }

	protected:
		bstnode<type>* _search(np, const type&);
		bstnode<type>* _min(np) const;
		bstnode<type>* _max(np) const;
		void _clear(np);
		void _setnull(np, np);
		int _setheight(np);
		void _insert(np, const type&, int);
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

	//template<class type>
	//std::ostream& operator<<(std::ostream& osu, bst<type>& tree) {
	//	if (tree->empty()) return;
	//	kirai::queue<bstnode<type>*> q;
	//	q.push_back(tree->_root);
	//	while (!q.empty()) {
	//		bstnode<type>* tmp = q.front();
	//		if (tmp->left)  q.push_back(tmp->left);
	//		if (tmp->right) q.push_back(tmp->right);
	//	}
	//	while (!q.empty()) {
	//		
	//		std::cout << q.top() << " ";
	//		q.pop();
	//	}
	//	return osu;
	//}

	template<class type>
	void bst<type>::_clear(np cur) {
		if (cur->left) _clear(cur->left);
		if (cur->right) _clear(cur->right);
		_remove(cur);
	}

	template<class type>
	int bst<type>::_setheight(np cur) {
		if (!cur)    return -1;
		if (_isleaf(cur)) return cur->height = 0;
		int a = _setheight(cur->left);
		int b = _setheight(cur->right);
		return cur->height = (a > b ? a : b) + 1;
	}
	
	template<class type>
	void bst<type>::bfs(void(*visit)(type data)) {
		if (empty()) return;
		kirai::queue<np> q;
		q.push_back(_root);
		while (!q.empty()) {
			np tmp = q.front();
			q.pop_front();
			visit(tmp->_data);
			if (tmp->left)  q.push_back(tmp->left);
			if (tmp->right) q.push_back(tmp->right);
		}
	}

	template<class type>
	void bst<type>::dfs(void(*visit)(type data)) {
		if (empty()) return;
		kirai::stack<np> s;
		s.push(_root);
		while (!s.empty()) {
			np tmp = s.top();
			s.pop();
			visit(tmp->_data);
			if (tmp->right) s.push(tmp->right);
			if (tmp->left)	s.push(tmp->left);
		}
	}
	template <class type>
	void bst<type>::_setnull(np cur, np aim) {
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
		else if (x > cur->_data) {
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
		_setheight(_root);
		return true;
	}

	template <class type>
	type bst<type>::_remove(np cur) {
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
	void bst<type>::insert(const type& x) {
		if (empty()) {
			np tmp = new nt();
			_root = tmp;
			_root->_data = x;
			_root->height = 0;
			_root->depth = 0;
			return;
		}
		_insert(_root, x, 1);
	}

	template <class type>
	void bst<type>::_insert(np cur, const type& x, int depth) {
		if (x > cur->_data) {
			if (cur->right == NULL) {
				np tmp = new nt();
				cur->right = tmp;
				tmp->_data = x;
				tmp->depth = depth;
			}
			else {
				_insert(cur->right, x, depth+1);
			}
		}
		if (x < cur->_data) {
			if (cur->left == NULL) {
				np tmp = new nt();
				cur->left = tmp;
				cur->height++;
				tmp->_data = x;
				tmp->depth = depth;
			}
			else {
				_insert(cur->left, x, depth+1);
			}
		}
		cur->height = (
			_height(cur->left) > _height(cur->right) ?
			_height(cur->left) : _height(cur->right)
			) + 1;
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
