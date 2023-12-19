#include "PauseMenu.h"

#include <ui/Label.h>
#include <ui/Button.h>

PauseMenu::PauseMenu() : Scene() {

	GUIPanel = Panel({ 0,0 }, Color(0, 0, 0, 50));

}

void PauseMenu::update(Vector2f mousePosition) {
	GUIPanel.update(mousePosition);
}

void PauseMenu::loadScene() {

	GUIPanel.addComponent(new Label(Vector2f(400, 200), "PAUSE", 35, false, true));

	Button* continueGame = new Button(Vector2f(400, 450), "Continue", 20);
	continueGame->setCallback(&SceneManager::pauseGame);
	GUIPanel.addComponent(continueGame);

	Button* quitButton = new Button(Vector2f(400, 500), "Menu", 20);
	quitButton->setCallback(&SceneManager::init);
	GUIPanel.addComponent(quitButton);

}
