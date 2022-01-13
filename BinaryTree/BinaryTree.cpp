#include <iostream>
#include"BinaryTree.h"

int main()
{
    Tree<int> t;
	//for (size_t i = 0; i < 10; i++)
	//{
	//	int n = rand() % 100;
	//	t.add(n);
	//	std::cout << n << "\t";
	//}
	//t.remove(1);

	//std::cout << "\n====================\n";
	//t.show();
	//std::cout << "\n====================\n";
	////t.funnyShow();
	////std::cout << "\n====================\n";

	//int min = t.findMin()->value;
	//std::cout << min;

	//std::cout << "\n====================\n";
	//t.remove(41);
	//t.show();
	//std::cout << "\n====================\n";
	//t.funnyShow();
	//std::cout << "\n====================\n";

	while (true)
	{
		t.add(1);
		t.remove(1);
	}

}

