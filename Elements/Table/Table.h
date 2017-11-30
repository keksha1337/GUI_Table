#pragma once

#include"../../IDisplayable.h"
#include"../../General/Styles.hpp"
#include"../../Elements/Button/GUIButton.h"
class GUILayer;

class Table : public IDisplayable
{
public:
	~Table();

	//void setDesign(Design design_);
	void SetFieldSize(Vector2f fieldSize_);
	void SetSize(Vector2f size_);
	void SetBorderSize(int borderSize_);
	int GetBorderSize();
	void Draw() override;
	void Update(float x, float y, float width, float height);
	void handleEvent(const sf::Event& event) override;
	void AddElement(std::shared_ptr<IDrawable> element);
	void AddElement(std::shared_ptr<IDrawable> element, int i, int j);

	//Design getDesign();
	Vector2f GetFieldSize();

private:
	GUIStyle *gstyle;
	TextStyle *tstyle;
	GUILayer *fabric;
	friend class GUILayer;
	Table(GUILayer* fabric_, RenderWindow& renderWindow, float x, float y, float width, float height, TextStyle *tstyle, GUIStyle *gstyle);
	Table(RenderWindow& renderWindow, Vector2f xy, float width, float height);
	Table(RenderWindow& renderWindow, float x, float y, Vector2f size);
	Table(RenderWindow& renderWindow, Vector2f xy, Vector2f size);

	void init(float x, float y, float width, float height);


	//Design design;
	//Node ** fields; TODO
	std::shared_ptr<IDrawable> **elements;
	RectangleShape border;
	Vector2f tableSize;
	Vector2f fieldSize;
	int borderSize;

};
