#pragma once

template<typename T>
struct TreeNode
{
	T value;
	TreeNode* lChild;
	TreeNode* rChild;

	TreeNode(const T& value)
	{
		this->value = value;
		this->lChild = NULL;
		this->rChild = NULL;
	}
};

template <typename T>
class Tree
{
private:
	TreeNode<T>* head;
	unsigned int size;
	void _show(TreeNode<T>* head) const;
	void _add(TreeNode<T>** head, const T& value);
	void _funnyShow(TreeNode<T>* head, int count) const;
	void _remove(TreeNode<T>** head, const T& value);
	TreeNode<T>* _findMin(TreeNode<T>* head) const;

public:
	Tree();

	void add(const T& value);
	void show() const;
	void funnyShow() const;
	void remove(const T& value);

	TreeNode<T>* findMin() const;

	~Tree();
};

template<typename T>
inline void Tree<T>::_show(TreeNode<T>* head) const
{
	if (head != NULL)
	{
		this->_show(head->lChild);
		std::cout << head->value << "\t";
		this->_show(head->rChild);
	}
}

template<typename T>
inline void Tree<T>::_add(TreeNode<T>** head, const T& value)
{
	if (*head == NULL)
	{
		*head = new TreeNode<T>(value);
	}
	else
	{
		if ((*head)->value < value)
		{
			this->_add(&(*head)->rChild, value);
		}
		else
		{
			this->_add(&(*head)->lChild, value);
		}
	}
}

template<typename T>
inline void Tree<T>::_funnyShow(TreeNode<T>* head, int count) const
{
	if (head == NULL)
	{
		return;
	}

	this->_funnyShow(head->rChild, ++count);

	for (size_t i = 0; i < count; i++)
	{
		std::cout << "\t";
	}

	std::cout << head->value << "\n";
	count--;

	this->_funnyShow(head->lChild, ++count);

	std::cout << "\n";
}

template<typename T>
inline void Tree<T>::_remove(TreeNode<T>** head, const T& value)
{
	if (*head == NULL)
		return;

	if ((*head)->value > value)
	{
		this->_remove(&(*head)->lChild, value);
	}
	else if ((*head)->value < value)
	{
		this->_remove(&(*head)->rChild, value);
	}
	else
	{
		if ((*head)->lChild == NULL)
		{
			TreeNode<T>* tmp = *head;
			*head = (*head)->rChild;
			delete tmp;
		}
		else if ((*head)->rChild == NULL)
		{
			TreeNode<T>* tmp = *head;
			*head = (*head)->lChild;
			delete tmp;
		}
		else
		{
			TreeNode<T>* tmp = this->_findMin((*head)->rChild);
			(*head)->value = tmp->value;
			this->_remove(&(*head)->rChild, tmp->value);
		}
	}
}

template<typename T>
inline TreeNode<T>* Tree<T>::_findMin(TreeNode<T>* head) const
{
	if (head->lChild == NULL)
		return head;

	return this->_findMin(head->lChild);
}


template<typename T>
inline Tree<T>::Tree() :head{ NULL }, size{ 0 }
{
}

template<typename T>
inline void Tree<T>::add(const T& value)
{
	this->_add(&this->head, value);
	this->size++;
}

template<typename T>
inline void Tree<T>::show() const
{
	this->_show(this->head);
}

template<typename T>
inline void Tree<T>::funnyShow() const
{
	this->_funnyShow(this->head, 0);
}

template<typename T>
inline void Tree<T>::remove(const T& value)
{
	this->_remove(&this->head, value);
}

template<typename T>
inline TreeNode<T>* Tree<T>::findMin() const
{
	return this->_findMin(this->head);
}

template<typename T>
inline Tree<T>::~Tree()
{
	if (this->head)
	{
		delete head->lChild;
		delete head->rChild;
	}
}
