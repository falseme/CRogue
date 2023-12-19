#include "MenuScene.h"

#include <ui/Label.h>
#include <ui/Button.h>

MenuScene::MenuScene() : Scene() {

}

void MenuScene::update(Vector2f mousePosition) {
	GUIPanel.update(mousePosition);
}

void MenuScene::loadScene() {

	GUIPanel.addComponent(new Label(Vector2f(400, 100), "CROGUE", 50, true, true));

	Button* playButton = new Button(Vector2f(400, 400), "Jugar", 16);
	playButton->setCallback(&SceneManager::startGame);
	GUIPanel.addComponent(playButton);

	Button* statsButton = new Button(Vector2f(400, 450), "Estadísticas", 16);
	statsButton->setCallback(&SceneManager::showStats);
	GUIPanel.addComponent(statsButton);

	Button* tutorialButton = new Button(Vector2f(400, 500), "Controles", 16);
	tutorialButton->setCallback(&SceneManager::showTutorial);
	GUIPanel.addComponent(tutorialButton);

	Button* quitButton = new Button(Vector2f(400, 550), "Salir", 16);
	quitButton->setCallback(&SceneManager::quitGame);
	GUIPanel.addComponent(quitButton);

}
