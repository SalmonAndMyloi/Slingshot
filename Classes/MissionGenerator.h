//
//  MissionGenerator.h
//  Slingshot
//
//  Created by Salmon on 2015. 3. 16..
//
//  Singleton Pattern MissionGenerator that creates random missions
//  싱글턴패턴으로 만든 랜덤 미션 제너레이터

#ifndef __Slingshot__MissionGenerator__
#define __Slingshot__MissionGenerator__

#include "Mission.h"

class MissionGenerator {
protected:
    static MissionGenerator * singleGenerator;
    //Declair all constructors protected so it can be never called outside
    MissionGenerator() {}
    MissionGenerator(MissionGenerator const&) {}
    MissionGenerator& operator=(MissionGenerator const&) {}
public:
    static MissionGenerator * getInstance() {
        if(!singleGenerator)
            singleGenerator = new MissionGenerator();
        return singleGenerator;
    }
    Mission * Generator();
};

#endif /* defined(__Slingshot__MissionGenerator__) */
