//
//  ResetLayer.h
//  GearsOfKMU
//
//  Created by admin on 12/3/15.
//
//

#ifndef __GearsOfKMU__ResetLayer__
#define __GearsOfKMU__ResetLayer__

#include <stdio.h>
#include "cocos2d.h"

class ResetLayer : public cocos2d::LayerColor
{
private:
	cocos2d::Vec3 initialPos;
	cocos2d::Label* txt;
	cocos2d::Menu* Yes;
	cocos2d::Menu* No;
	cocos2d::MoveTo* In;
	cocos2d::MoveTo* Out;

public:
	virtual bool init();
	void YesFunction(cocos2d::Ref *pSender);
	void NoFunction(cocos2d::Ref *pSender);
	void Show();
	void Hide();
	virtual void update(float dt);
	ResetLayer();
	virtual ~ResetLayer();
	CREATE_FUNC(ResetLayer);
};

#endif /* defined(__GearsOfKMU__ResetLayer__) */
