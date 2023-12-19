#include "TutorialScene.h"

#include <ui/Label.h>
#include <ui/Button.h>
#include <ui/AnimatedSpriteImage.h>

TutorialScene::TutorialScene() : Scene() {

	GUIPanel = Panel(Vector2f(0, 0), Color(200, 180, 190, 50));

}

void TutorialScene::update(Vector2f mousePosition) {
	GUIPanel.update(mousePosition);
}

void TutorialScene::loadScene() {

	GUIPanel.addComponent(new Label(Vector2f(400, 80), "CONTROLES", 30, false, true));

	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::WASD), Vector2f(100, 200), Vector2f(2, 2), Vector2f(31.5f, 21)));
	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::playerRun), Vector2f(100, 320), Vector2f(4, 4), Vector2f(12, 12)));

	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::H), Vector2f(300, 200), Vector2f(2, 2), Vector2f(9.5f, 0)));
	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::playerHeal), Vector2f(300, 320), Vector2f(4, 4), Vector2f(12, 12)));

	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::TAB), Vector2f(500, 200), Vector2f(2, 2), Vector2f(16.5f, 0)));
	GUIPanel.addComponent(new Label(Vector2f(500, 320), "Inventario", 16, false, true, true));

	GUIPanel.addComponent(new AnimatedSpriteImage(Animation(0.6f, Assets::ESC), Vector2f(700, 200), Vector2f(2, 2), Vector2f(20.5f, 0)));
	GUIPanel.addComponent(new Label(Vector2f(700, 320), "Pausa", 16, false, true, true));

	GUIPanel.addComponent(new Label(Vector2f(400, 430), "Click izquierdo para atacar", 16, false, true, true));

	Button* backButton = new Button(Vector2f(400, 520), "Volver", 20);
	backButton->setCallback(&SceneManager::showTutorial);
	GUIPanel.addComponent(backButton);

}
