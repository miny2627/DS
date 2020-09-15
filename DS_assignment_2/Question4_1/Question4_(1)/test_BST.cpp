#include <iostream>
#include <string>
#include "BST.cpp"
using namespace std;

int main()
{
	Nptr T = NULL;
	Nptr n = new node;
	T = Insert(T, "Park");
	T = Insert(T, "Kim"); T = Insert(T, "Cho");
	T = Insert(T, "Lee"); T = Insert(T, "Seo");
	T = Insert(T, "Yoo");
	/*
			Park
		   /   ¡¬
		 Kim    Seo
		/  ¡¬      ¡¬
	  Cho   Lee     Yoo

	*/

	cout << "# Tree" << endl;
	inorder(T); cout << endl << endl;

	cout << "# Tree - Search" << endl;
	n = Search(T, "Choi");
	n = Search(T, "Yoo");
	inorder(n); cout << endl << endl;

	cout << "# Tree - Delete" << endl;
	Delete(T, "Cho");
	inorder(T); cout << endl << endl;
	Delete(T, "Min");
	inorder(T); cout << endl << endl;

	cout << "# Tree - Update" << endl;
	Update(T, "Lee");
	Update(T, "Ja");

	return 0;
}