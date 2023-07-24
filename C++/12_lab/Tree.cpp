﻿#include "Tree.h"
namespace btree      // áèíàðíîå äåðåâî, íå äîïóñêàåòñÿ äóáëèðîâàíèå êëþ÷åé
{
	Object create(CMP(*f)(void*, void*))
	{
		return *(new Object(f));
	}
	//-------------------------------
	Node* Node::min()
	{
		Node* rc = this;
		if (rc->left != NULL)
			rc = rc->left->min();
		return rc;
	}
	//-------------------------------
	Node* Node::next()//ñëåäóþùèé ïî êëþ÷ó
	{
		Node* rc = this, * x = this;
		if (rc->right != NULL)
			rc = rc->right->min();
		else
		{
			rc = this->parent;
			while (rc != NULL && x == rc->right)
			{
				x = rc;
				rc = rc->parent;
			}
		}  return rc;
	}
	//-------------------------------
	void Node::scanDown(void(*f)(void* n))//íèñõîäÿùèé îáõîä (ÊËÏ)(ëó÷øå íå òðîãàòü)
	{
		f(this->data);//ïîëó÷åíèå äàííûõ òåêóùåãî ýëåìåíòà
		//std::cout << this->data <<std::endl;
		if (this->left != NULL)
			this->left->scanDown(f);
		if (this->right != NULL)
			this->right->scanDown(f);
	}

	void Node::scanDownKLP(void(*f)(void* n))//íèñõîäÿùèé îáõîä (ÊËÏ)
	{
		f(this->data);
		//std::cout << this->data <<std::endl;
		if (this->left != NULL)
			this->left->scanDownKLP(f);
		if (this->right != NULL)
			this->right->scanDownKLP(f);
	}


	/*void ObhodLeft(node** w)
		// Ëåâîñòîðîííèé îáõîä äåðåâà.
		// *w - óêàçàòåëü íà êîðåíü äåðåâà.
	{
		if (*w != NULL) //ïóñòîå äåðåâî?
		{
			cout << (**w).Key << " "; âûâîä èíôîðìàöèè î êîðíå
				ObhodLeft(&((**w).Left)); //îáõîä ëåâîãî ïîääåðåâà
			ObhodLeft(&((**w).Right));
		}//îáõîä ïðàâîãî ïîääåðåâà
	}*/

	void Node::scanDownLKP(void(*f)(void* n))// ñìåøàííûé îáõîä(ëêï)
	{
		if (this->left != NULL)
			this->left->scanDownLKP(f);
		f(this->data);//ôóíêöèÿ ïå÷àòè
		//std::cout << this->data << std::endl;
		if (this->right != NULL)
			this->right->scanDownLKP(f);
	}

	/*void ObhodBack (node **w)
// Îáðàòíûé (ñìåøàííûé) îáõîä áèíàðíîãî äåðåâà.
// *w - óêàçàòåëü íà êîðåíü äåðåâà.
{
  if (*w!=NULL) //ïóñòîå äåðåâî?
  { ObhodBack (&((**w).Left)); //îáõîä ëåâîãî ïîääåðåâà
	cout<<(**w).Key<<" "; //âûâîä èíôîðìàöèè î êîðíå
	ObhodBack (&((**w).Right)); }//îáõîä ïðàâîãî ïîääåðåâà
}
*/
//-------------------------------
	Node* Object::search(void* d, Node* n)
	{
		Node* rc = n;
		if (rc != NULL)
		{
			if (isLess(d, n->data))
				rc = search(d, n->left);
			else
				if (isGreat(d, n->data))
					rc = search(d, n->right);
		} return rc;
	}
	//-------------------------------
	bool Object::insert(void* d)
	{
		Node* x = this->Root, * n = NULL;
		bool rc = true;
		while (rc == true && x != NULL)
		{
			n = x;
			if (isLess(d, x->data))
				x = x->left;          //âûáîð êóäà èäòè - âëåâî èëè âïðàâî
			else
				if (isGreat(d, x->data))
					x = x->right;
				else
					rc = false;
		}
		if (rc == true && n == NULL)
			this->Root = new  Node(NULL, NULL, NULL, d);
		else
			if (rc == true && isLess(d, n->data))
				n->left = new  Node(n, NULL, NULL, d);
			else
				if (rc == true && isGreat(d, n->data))
					n->right = new  Node(n, NULL, NULL, d);
		return rc;
	};
	//-------------------------------
	bool  Object::deleteByNode(Node* n)
	{
		bool rc = true;
		if (rc = (n != NULL))
		{
			if (n->left == NULL && n->right == NULL)       //åñëè ïîòîìêîâ íåò
			{
				if (n->parent == NULL)
					this->Root = NULL;   //îáíóëåíèå êîðíÿ
				else
					if (n->parent->left == n)
						n->parent->left = NULL;
					else
						n->parent->right = NULL;
				delete n;
			}
			else
				if (n->left == NULL && n->right != NULL) //òîëüêî ïðàâûé ïîòîìîê
				{
					if (n->parent == NULL)
						this->Root = n->right;
					else
						if (n->parent->left == n)
							n->parent->left = n->right;
						else
							n->parent->right = n->right;
					n->right->parent = n->parent;
					delete n;
				}
				else
					if (n->left != NULL && n->right == NULL) //òîëüêî ëåâûé ïîòîìîê
					{
						if (n->parent == NULL)
							this->Root = n->left;
						else
							if (n->parent->right == n)
								n->parent->left = n->left;
							else
								n->parent->right = n->left;
						n->left->parent = n->parent;
						delete n;
					}
					else                                  //åñëè åñòü îáà ïîòîìêà
						if (n->left != NULL && n->right != NULL) {
							Node* x = n->next();
							n->data = x->data;
							rc = deleteByNode(x);
						}
		} return  rc;
	}
	//-------------------------------
	void Node::scanLevel(void(*f)(void* n), int i)  //Âûâåñòè âåðøèíû óðîâíÿ
	{
		if (this->left != NULL)
			this->left->scanLevel(f, i);
		if (this->getLevel() == i)
			f(this->data);
		if (this->right != NULL)
			this->right->scanLevel(f, i);
	}
	//-------------------------------
	int Node::getLevel()// ïîëó÷èòü óðîâåíü
	{
		Node* rc = this;
		int q = 0;
		while (rc->parent != NULL)
		{
			rc = rc->parent;
			q++;
		}
		return q;
	}
	//-------------------------------
	void Node::scanByLevel(void(*f)(void* n))
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << " " << '\t' << " ";
			this->scanLevel(f, i);
			std::cout << '\n';
		}
	}

	int j = 0;
	int Object::chet(Node* t)
	{
		j = 0;
		if (t)
		{
			chet(t->next());
			if ((int)(t->data) % 2 == 0)
				j++;
		}
		return j;
	}

	int Object::maxDepth(Node* root) {
		if (!root) {
			return 0;
		}
		if (maxDepth(root->left) > maxDepth(root->right)) return (int)root->left;
		else return (int)root->right;
	}

	int Object::minDepth(Node* root) {
		if (!root) {
			return 0;
		}
		if (minDepth(root->left) < minDepth(root->right)) return (int)root->left;
		else return (int)root->right;
	}

	int Object::isBalanced(Node* root)
	{
		if (maxDepth(root) - minDepth(root) <= 1)
			return 1;
		else
			return 0;
	}
}