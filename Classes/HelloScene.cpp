#include "HelloScene.h"

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
	return true;
}
