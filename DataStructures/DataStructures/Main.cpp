#include <SFML\Graphics.hpp>

#include"BST\BST.h"
#include"LinkedList\LinkedList.h"
#include"Queue\Queue.h"
#include"Stack\Stack.h"
#include"Vector\Vector.h"

void createVector(sf::RenderWindow &window, sf::Font font)
{
	//Calling the class
	Vector v(window, font);
	v.inputHandler();
	v.drawVector(window);

	while (window.isOpen())
	{
		//Breaks if user chooses exit
		if (v.editingHandler(window) == false)
			break;
	}
}

void createLinkedList(sf::RenderWindow &window)
{
	LinkedList LL(window);
	LL.Drawinitial();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!LL.startWork())
			return;
	}

}
int main()
{
	int length = 1800, height = 720;

	//Creating display window
	sf::RenderWindow window(sf::VideoMode(length, height), "Vector", sf::Style::Close | sf::Style::Resize);

	//Loading font
	sf::Font font;
	font.loadFromFile("arial_font/arial.ttf");

	while (true)
	{
		std::cout << "Enter the desired choice number" << std::endl;
		std::cout << "[1]Vector  [2]Stack  [3]Queue  [4]LinkedList  [5]BinarySearchTree  [6]Exit" << std::endl;
		int choice;
		std::cin >> choice;

		if (choice == 1)
		{
			//Calling the Vector class
			createVector(window, font);
		}
		else if (choice == 4)
		{
			createLinkedList(window);
		}
		else if (choice == 6)
		{
			break;
		}
	}

	return 0;
}