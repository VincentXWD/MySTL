#ifndef _KIRAI_BST
#define _KIRAI_BST

namespace kirai {
	template<class type>
	struct bstnode {
		typedef bstnode<type>* np;
		type _data;
		bool avail;
		np left;
		np right;
		bstnode<type>() { left = NULL; right = NULL; avail = true; }
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
		bool remove(const type&);
		bool query(const type&) const;
		bool change(const type&);

	public:
		void preorder(void(*visit)(type)) { _preorder(_root, visit); };
		void inorder(void(*visit)(type)) { _inorder(_root, visit); };
		void postorder(void(*visit)(type)) { _postorder(_root, visit); };

	protected:
		void _insert(np, const type&);
		void _inorder(np, void(*)(type));
		void _postorder(np, void(*)(type));
		void _preorder(np, void(*)(type));
		bool _remove(np, const type&);
	private:
		np _root;
	};

	//unfinished.
	template <class type>
	bool bst<type>::remove(const type& x) {
		_remove(_root, x);
	}

	template <class type>
	bool bst<type>::_remove(np cur, const type& x) {
		if (cur->_data < )
	}

	template <class type>
	void bst<type>::insert(const type& x) {
		if (empty()) {
			np tmp = new nt;
			_root = tmp;
			_root->_data = x;
			_root->avail = false;
			return;
		}
		_insert(_root, x);
		return;
	}
	//above.

	// x () than _data, then put x into (). : larger:right, smaller:left
	template <class type>
	void bst<type>::_insert(np cur, const type& x) {
		if (x >= cur->_data) {
			if (cur->right == NULL) {
				np tmp = new nt;
				cur->right = tmp;
				tmp->_data = x;
				tmp->avail = false;
				return;
			}
			else if (cur->right->avail = true) {
				cur->right->_data = x;
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
				tmp->_data = x;
				tmp->avail = false;
				return;
			}
			else if (cur->left->avail = true) {
				cur->left->_data = x;
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
