// Implemantation of single and dual lists

#include<iostream>
#include"List_SingleLinked.h"
#include"List_DualLinked.h"

int main()
{
	List_DualLinked<int> ls;
	ls.pushBack(5);
	ls.pushBack(10);
	ls.pushBack(15);
	ls.pushBack(20);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.popFront();

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.clear();

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.pushFront(2);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.pushFront(4);
	ls.pushBack(6);
	ls.pushBack(8);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.removeAt(1);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.removeAt(2);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.insert(111, 1);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.insert(222, 2);

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.popBack();

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	ls.popBack();

	std::cout << "Size = " << ls.getSize() << std::endl;

	for (int i = 0; i < ls.getSize(); ++i)
		std::cout << ls[i] << ' ';
	std::cout << std::endl;

	return 0;
}