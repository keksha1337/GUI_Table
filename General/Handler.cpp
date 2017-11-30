#include "../Window/WindowTab.h"
#include <Windows.h>

const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 700;

void buttonAction()
{
	std::cout << "Button pressed!" << std::endl;
}

//функция, которая будет вызываться каждый кадр во время перемещения слайдера
void onSliderMove(float slider_value)
{
	std::cout << "slider value = " << slider_value << std::endl;
}

//окей. теперь fun part
void main()
{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.background.loadFromFile("statusBar.png");
	gst.frameWid = 5;
	//текстуры слайдера
	+gst.sliderBackTex.loadFromFile("slider_back_line.png");
	+gst.sliderFrontTex.loadFromFile("slider_front_line.png");
	+gst.sliderHandlerTex.loadFromFile("slider_handler.png");

	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 22;
	tst.align = 'c';

	static GUIStyle sBarStyle;
	sBarStyle.background.loadFromFile("statusBar.png");
	
	//создание окна и слоя гуи на нем 
	WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
	std::shared_ptr<GUILayer> layer = main.CreateGUILayer(Vector2f(0,0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	//вот досюда

	//пример создания кнопки
	std::shared_ptr<GUIButton> button = layer->CreateButton(20, 20, 100,100, "button", &tst, &gst, &buttonAction);
	
	// создание label
	Texture icon, icon2;
	icon.loadFromFile("Danger.png");
	icon2.loadFromFile("Galaxy.png");
	// просто текст
	std::shared_ptr<GUILabel> label = layer->CreateLabel(0, 300, 100, 20, "Just text", &tst, &gst);
	// иконка
	std::shared_ptr<GUILabel> label1 = layer->CreateLabel(0, 330, 100, 40, "", &tst, &icon, &gst);
	// текст и иконка
	std::shared_ptr<GUILabel> label2 = layer->CreateLabel(0, 400, 100, 40, "text to the right of the icon", &tst, &icon2, &gst);

	//сохраняем ID label2
	int label2ID = label2->GetID();
	//добавляем label1 уже существующий label2 как дочерний
	label1->AddElement(label2);
	//получаем указатель на label2, находя его по id
	auto label2again = label1->GetElement(label2ID);
	if (label2again.get() != nullptr)//если label2 дочерний для label1, то вернется указатель на него, если нет, то на nullptr
		std::cout << "label2 is child of label1!" << std::endl;
	// Cоздание прогресс бара. 
	std::shared_ptr<GUIProgressBar> progressBar = layer->CreateProgressBar(layer, SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 3, 200, 30, "Sorting...", &tst, &gst,
		0, 200, Color::White, Color::Green);

    std::shared_ptr<ScrollBar> scrollbarHor = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::HORIZONTAL, 1600);

    std::shared_ptr<ScrollBar> scrollbarVert = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::VERTICAL, 1800);

	//создаем слайдер
	std::shared_ptr<Slider> slider = layer->CreateSlider(225, 450, 350, 20, 35, 38, &gst, 0, 100, 20, &onSliderMove);

	////Создание статус бара
	//std::shared_ptr<GUIStatusBar>  statusBar = layer->CreateStatusBar(40, 5, 10, &sBarStyle);
	//std::shared_ptr<GUIButton> box1 = layer->CreateButton(100, 0, 50, 50, "", &tst, &gst, &buttonAction);
	//std::shared_ptr<GUIBox> box2 = layer->CreateButton(0, 0, 1, 1, "B", &tst, &gst, &buttonAction);
	//std::shared_ptr<GUIBox> box3 = layer->CreateButton(0, 0, 4, 1, "Test", &tst, &gst, &buttonAction);
	//statusBar->AddElement(box1);
	//statusBar->AddElement(box2);
	//statusBar->AddElement(box3);

	std::shared_ptr<TextField> textBox = layer->CreateTextField(650, 550, 100, 40, "textField", &tst, &gst);

	std::shared_ptr<TextArea> textArea = layer->CreateTextArea(300, 10, 200, 150, &tst, &gst);

	//Таблица
	std::shared_ptr<Table> table = (*layer).CreateTable(*layer, 800, 10, 5, 6, &tst, &gst);
	std::shared_ptr<GUILabel> labelForTable1 = layer->CreateLabel(0, 330, 100, 40, "", &tst, &icon, &gst);
	std::shared_ptr<GUILabel> labelForTable2 = layer->CreateLabel(0, 0, 0, 0, "Table", &tst, &gst);
	std::shared_ptr<GUILabel> labelForTable3 = layer->CreateLabel(0, 0, 0, 0, "Table", &tst, &gst);
	std::shared_ptr<TextField> textBoxForTable1 = layer->CreateTextField(0, 0, 0, 0, "textField1", &tst, &gst);
	std::shared_ptr<TextField> textBoxForTable2 = layer->CreateTextField(0, 0, 0, 0, "textField2", &tst, &gst);
	std::shared_ptr<GUIButton> fieldForTable00 = layer->CreateButton(0, 0, 0, 0, "field00", &tst, &gst, &buttonAction);
	std::shared_ptr<GUIButton> fieldForTable01 = layer->CreateButton(0, 0, 0, 0, "field01", &tst, &gst, &buttonAction);
	std::shared_ptr<GUIButton> fieldForTable33 = layer->CreateButton(0, 0, 0, 0, "field33", &tst, &gst, &buttonAction);
	std::shared_ptr<TextArea> textAreaForTable1 = layer->CreateTextArea(0, 0, 50, 50, &tst, &gst);
	std::shared_ptr<TextArea> textAreaForTable2 = layer->CreateTextArea(0, 0, 50, 50, &tst, &gst);
	std::shared_ptr<TextArea> textAreaForTable3 = layer->CreateTextArea(0, 0, 50, 50, &tst, &gst);
	table->AddElement(labelForTable1);
	table->AddElement(labelForTable2, 0, 3);
	table->AddElement(labelForTable3, 4, 4);
	table->AddElement(textBoxForTable1, 4, 1);
	table->AddElement(textBoxForTable2, 2, 3);
	table->AddElement(textAreaForTable1, 1, 0);
	table->AddElement(textAreaForTable2, 2, 0);
	table->AddElement(textAreaForTable3, 2, 1);
	table->AddElement(fieldForTable00, 0, 2);
	table->AddElement(fieldForTable01, 0, 1);
	table->AddElement(fieldForTable33, 3, 3);
	int x = 50;
	while (1)
	{
		// Костыль для теста на время, пока нет Observer.
		// Потом будет передаваться ивент об изменении значения бара.
		//*****тест ProgressBar****
		//progressBar->increase();
		progressBar->setValue(x);
		x += 50;
		//*************************

		main.Redraw();
	}	
}
