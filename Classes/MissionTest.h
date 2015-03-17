//
//  MissionTest.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//
//  Preconstructed Mission made for TESTING Mission's Public Methods (ex. UpdateAllObjectPosition() )
//  미션의 public 메서드를 테스트 하기 위해서 미리 제작된 미션

#ifndef __Slingshot__MissionTest__
#define __Slingshot__MissionTest__

#include "Mission.h"

class MissionTest : public Mission {
public:
    MissionTest();
    ~MissionTest();
    static MissionTest * createMissionTest();
};
#endif /* defined(__Slingshot__MissionTest__) */
