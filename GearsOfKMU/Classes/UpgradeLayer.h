//
//  UpgradeLayer.h
//  GearsOfKMU
//
//  Created by admin on 12/3/15.
//
//

#ifndef __GearsOfKMU__UpgradeLayer__
#define __GearsOfKMU__UpgradeLayer__

#include "cocos2d.h"
#include <stdio.h>

using namespace cocos2d;

class UpgradeLayer : public LayerColor
{
private:
    
public:
    UpgradeLayer();
    virtual ~UpgradeLayer();
    
    virtual bool init();
    
    CREATE_FUNC(UpgradeLayer);
};

#endif /* defined(__GearsOfKMU__UpgradeLayer__) */
