//
//  GameLayer.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "GameLayer.h"
#include "MissionGenerator.h"

GameLayer::GameLayer() {
    curMission = NULL;
}
GameLayer::~GameLayer() {
    
}
GameLayer * GameLayer::createGameLayer() {
    GameLayer * _gameLayer = new GameLayer();
    return _gameLayer;
}
bool GameLayer::Load() {
    if(curMission != NULL)
        return false;
    curMission = MissionGenerator::getInstance()->Generator();
    addChild(curMission,BACK_GROUND);
    return true;
}
bool GameLayer::Start() {
    this->scheduleUpdate();
    return true;
}
bool GameLayer::Stop() {
    this->unscheduleUpdate();
    return true;
}
int GameLayer::UpdateOneStep() {
    curMission->UpdateAllObjectPosition();
    return 0;
}