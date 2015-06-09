#include "GameScene.h"
#include "HelloScene.h"

Scene* GameScene::createScene()
{
	Scene* scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init() {
	if (!Layer::init()) {
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	addMenu();

	auto sprite = Sprite::create("image/box.png");
	sprite->setColor(Color3B::BLUE);
	sprite->setPosition(100, 100);
	sprite->setContentSize(Size(20, 20));
	this->addChild(sprite);

	return true;
}

void GameScene::addMenu() {
	auto fontSize = 24;
	auto menu = Menu::create();
	menu->setPosition(visibleSize.width - 80, visibleSize.height - fontSize);
	this->addChild(menu);

	auto labelPlayOrPause = Label::createWithTTF("PLAY/PAUSE", "fonts/Marker Felt.ttf", fontSize);
	auto labelRestart = Label::createWithTTF("RESTART", "fonts/Marker Felt.ttf", fontSize);
	auto labelReturn = Label::createWithTTF("RETURN", "fonts/Marker Felt.ttf", fontSize);

	auto buttonPlayOrPause = MenuItemLabel::create(labelPlayOrPause, CC_CALLBACK_1(GameScene::playOrPause, this));
	auto buttonRestart = MenuItemLabel::create(labelRestart, CC_CALLBACK_1(GameScene::restart, this));
	auto buttonReturn= MenuItemLabel::create(labelReturn, CC_CALLBACK_1(GameScene::switchScene, this));

	buttonPlayOrPause->setPosition(0, 0);
	buttonRestart->setPosition(0, -fontSize);
	buttonReturn->setPosition(0, -fontSize * 2);

	menu->addChild(buttonPlayOrPause);
	menu->addChild(buttonRestart);
	menu->addChild(buttonReturn);

	auto controller = Menu::create();
	controller->setPosition(visibleSize.width - 120, 120);
	this->addChild(controller);

	auto trianglePathNormal = "image/triangle_normal.png";
	auto trianglePathSelected = "image/triangle_selected.png";
	auto iconSize = 40;

	auto buttonUp = MenuItemImage::create(trianglePathNormal, trianglePathSelected, CC_CALLBACK_1(GameScene::changeDirection, this));
	auto buttonDown = MenuItemImage::create(trianglePathNormal, trianglePathSelected, CC_CALLBACK_1(GameScene::moveDown, this));
	auto buttonLeft = MenuItemImage::create(trianglePathNormal, trianglePathSelected, CC_CALLBACK_1(GameScene::moveLeft, this));
	auto buttonRight = MenuItemImage::create(trianglePathNormal, trianglePathSelected, CC_CALLBACK_1(GameScene::moveRight, this));

	buttonUp->setRotation(0);
	buttonDown->setRotation(180);
	buttonLeft->setRotation(270);
	buttonRight->setRotation(90);

	buttonUp->setPosition(0, iconSize);
	buttonDown->setPosition(0, -iconSize);
	buttonLeft->setPosition(-iconSize, 0);
	buttonRight->setPosition(iconSize, 0);

	controller->addChild(buttonUp);
	controller->addChild(buttonDown);
	controller->addChild(buttonLeft);
	controller->addChild(buttonRight);
}

void GameScene::switchScene(Ref* pSender) {
	Director::getInstance()->replaceScene(HelloScene::createScene());
}

void GameScene::playOrPause(Ref* pSender) {
	// TODO
}

void GameScene::restart(Ref* pSender) {
	// TODO
}

void GameScene::changeDirection(Ref* pSender) {
	// TODO
}

void GameScene::moveDown(Ref* pSender) {
	// TODO
}

void GameScene::moveLeft(Ref* pSender) {
	// TODO
}
void GameScene::moveRight(Ref* pSender) {
	// TODO
}