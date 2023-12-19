#include "StatsScene.h"

#include <ui/Label.h>
#include <ui/Button.h>
#include <ui/SpriteImage.h>
#include <gameObject/Player.h>
#include <fstream>
#include <sstream>
#include <iostream>

StatsScene::StatsScene(string title) {

	GUIPanel = Panel({ 0,0 }, Color(255, 255, 255, 30));
	GUIPanel.addComponent(new Label(Vector2f(400, 100), title, 40, false, true));

}

void StatsScene::update(Vector2f mousePosition) {
	GUIPanel.update(mousePosition);
}

void StatsScene::loadScene() {

	vector<Vector2f> layout{ {700, 250} ,{700, 300},{700, 350},{700, 400} };

	GUIPanel.addComponent(new Label(Vector2f(100, 250), "Enemigos abatidos:", 16));
	GUIPanel.addComponent(new Label(Vector2f(100, 300), "Enemigos abatidos en total:", 16));
	GUIPanel.addComponent(new Label(Vector2f(100, 350), "Victorias:", 16));
	GUIPanel.addComponent(new Label(Vector2f(100, 400), "Derrotas:", 16));

	Button* menubtn = new Button(Vector2f(400, 550), "Menu", 20);
	menubtn->setCallback(&SceneManager::init);
	GUIPanel.addComponent(menubtn);

	UserStats* stats = new UserStats();
	FILE* statsI;
	fopen_s(&statsI, "data/save.dat", "rb");
	if (statsI) {
		fread(stats, sizeof(UserStats), 1, statsI);
		fclose(statsI);
	}

	GUIPanel.addComponent(new Label(layout[0], to_string(stats->kills), 16));
	GUIPanel.addComponent(new Label(layout[1], to_string(stats->totalKills), 16));
	GUIPanel.addComponent(new Label(layout[2], to_string(stats->victories), 16));
	GUIPanel.addComponent(new Label(layout[3], to_string(stats->losses), 16));

}


