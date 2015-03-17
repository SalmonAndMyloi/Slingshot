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
    gameStatus = STATUS_INIT;
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
    gameStatus = STATUS_LOADED;
    return true;
}
bool GameLayer::Start() {
    if(STATUS_LOADED || STATUS_STOPED) {
        this->scheduleUpdate();
        gameStatus = STATUS_RUNNING;
        return true;
    }
    return false;
}
bool GameLayer::Stop() {
    if(STATUS_LOADED || STATUS_RUNNING) {
        this->unscheduleUpdate();
        gameStatus = STATUS_STOPED;
        return true;
    }
    return false;
}
int GameLayer::UpdateOneStep() {
    curMission->UpdateAllObjectPosition();
    return 0;
}