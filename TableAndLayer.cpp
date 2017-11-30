#include "Elements\Table\Table.h"
#include "GUI\GUILayer.h"

//костыль
void buttonAction123()
{
	std::cout << "Button pressed!" << std::endl;
}

void Table::handleEvent(const sf::Event & event)
{
	if (event.type == Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::A)
		{
			SetFieldSize(Vector2f(GetFieldSize().x + 1, GetFieldSize().y + 1));
		}
		if (event.key.code == sf::Keyboard::D)
		{
			SetFieldSize(Vector2f(GetFieldSize().x - 1, GetFieldSize().y - 1));
		}
		if (event.key.code == sf::Keyboard::W)
		{
			SetSize(Vector2f(GetSize().x + 1, GetSize().y));
		}
		if (event.key.code == sf::Keyboard::S)
		{
			SetSize(Vector2f(GetSize().x - 1, GetSize().y - 1));
		}
		if (event.key.code == sf::Keyboard::Add)
		{
			SetBorderSize(GetBorderSize() + 1);
		}
		if (event.key.code == sf::Keyboard::BackSpace)
		{
			SetBorderSize(GetBorderSize() - 1);
		}
		if (event.key.code == sf::Keyboard::K)
		{
			std::shared_ptr<GUIButton> button = fabric->CreateButton(20, 20, 100, 100, "button", tstyle, gstyle, &buttonAction123);
			AddElement(button, 1, 1);
			std::shared_ptr<GUIButton> button2 = fabric->CreateButton(20, 20, 100, 100, "button", tstyle, gstyle, &buttonAction123);
			AddElement(button2, 2, 2);
		}
		if (event.key.code == sf::Keyboard::Q)
		{
			//elements[0][0].~shared_ptr();
			elements[0][0]->~IDrawable();
		}

	}
}

void Table::init(float x, float y, float width, float height)
{
	borderSize = 5;
	fieldSize.x = 50;
	fieldSize.y = 50;
	tableSize = Vector2f((width)*(fieldSize.x + borderSize) + borderSize, (height)*(fieldSize.y + borderSize) + borderSize);
	border.setFillColor(sf::Color::Red);
	elements = new std::shared_ptr<IDrawable> *[height];
	for (int i = 0; i < height; i++)
	{
		elements[i] = new std::shared_ptr<IDrawable>[width];
		for (int j = 0; j < width; j++)
		{
			std::shared_ptr<GUIButton> button = fabric->CreateButton(20, 20, 100, 100, "button", tstyle, gstyle, &buttonAction123);
			//AddElement(button, i, j);
		}
	}

	Update(x, y, width, height);
}