#include "HelloScene.h"
#include "GameScene.h"

Scene* HelloScene::createScene()
{
	Scene* scene = Scene::create();
	auto layer = HelloScene::create();
	scene->addChild(layer);
	return scene;
}

bool HelloScene::init() {
	if (!Layer::init()) {
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();


	addMenu();

	return true;
}

void HelloScene::addMenu() {
	auto fontSize = 24;
	auto menu = Menu::create();
	menu->setPosition(visibleSize / 2);
	this->addChild(menu);

	auto labelStart = Label::createWithTTF("START", "fonts/Marker Felt.ttf", fontSize);
	auto labelHelp = Label::createWithTTF("HELP", "fonts/Marker Felt.ttf", fontSize);
	auto labelExit = Label::createWithTTF("EXIT", "fonts/Marker Felt.ttf", fontSize);

	auto buttonStart = MenuItemLabel::create(labelStart, CC_CALLBACK_1(HelloScene::switchScene, this));
	auto buttonHelp = MenuItemLabel::create(labelHelp, CC_CALLBACK_1(HelloScene::switchScene, this));
	auto buttonExit = MenuItemLabel::create(labelExit, CC_CALLBACK_1(HelloScene::exit, this));

	buttonStart->setPosition(0, fontSize);
	buttonHelp->setPosition(0, 0);
	buttonExit->setPosition(0, -fontSize);

	menu->addChild(buttonStart);
	menu->addChild(buttonHelp);
	menu->addChild(buttonExit);

}

void HelloScene::switchScene(Ref* pSender) {
	Director::getInstance()->replaceScene(GameScene::createScene());
}

void HelloScene::exit(Ref* pSender) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
