//
//  MissionGenerator.cpp
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//

#include "MissionGenerator.h"
#include "MissionTest.h"

MissionGenerator * MissionGenerator::singleGenerator = 0;

Mission * MissionGenerator::Generator() {
    auto * _mission = MissionTest::createMissionTest();
    return _mission;
}