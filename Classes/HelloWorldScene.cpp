#include "HelloWorldScene.h"
#include "UILayer.h"
#include "MissionTest.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    // test xcode local commit
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //auto gameUi = UILayer::createUILayer();
    //this->addChild(gameUi);
    //gameUi->Start();
    //curMission = MissionTest::createMissionTest();
    //curMission->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height/2));
    //addChild(curMission);
    
    auto ui = UILayer::createUILayer();
    ui->Load();
    ui->setPosition(cocos2d::Vec2(visibleSize.width/2,visibleSize.height/2));
    //ui->Start();
    addChild(ui);
    
    //터치 활성화
    auto listener = EventListenerTouchOneByOne::create();
    listener->setEnabled(true);
    listener->onTouchBegan = CC_CALLBACK_2(UILayer::onTouchBegan, ui);
    listener->onTouchMoved = CC_CALLBACK_2(UILayer::onTouchMoved, ui);
    listener->onTouchEnded = CC_CALLBACK_2(UILayer::onTouchEnded, ui);
    listener->onTouchCancelled = CC_CALLBACK_2(UILayer::onTouchCancelled, ui);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, ui);
    return true;
}
bool HelloWorld::onTouchBegan(cocos2d::Touch*, cocos2d::Event*) {
    return true;
}
void HelloWorld::onTouchEnded(cocos2d::Touch*, cocos2d::Event*) {
    
}
void HelloWorld::onTouchMoved(cocos2d::Touch*, cocos2d::Event*) {
    
}
void HelloWorld::onTouchCancelled(cocos2d::Touch*, cocos2d::Event*) {
    
}

