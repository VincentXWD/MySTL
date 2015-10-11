#ifndef _KIRAI_BST
#define _KIRAI_BST

namespace kirai {
	template<class type>
	struct bstnode {
		typedef bstnode<type>* np;
		type val;
		np left;
		np right;
	};

	template<class type>
	class bst {
		typedef bstnode<type>* np;
	public:
		bst() { root = NULL; }

	protected:

	private:
		np root;
	};
}

#endif

