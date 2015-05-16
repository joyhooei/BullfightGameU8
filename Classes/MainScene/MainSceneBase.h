//
//  MainSceneBase.h主场景基类
//  BullfightGame
//
//  Created by 张 恒 on 15/3/16.
//
//
#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../GameLogic/GameLogic.h"
#include "../Play/CardLayer/CardLayerBase.h"
#include "../Play/PlayerLayer/PlayerLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;
#define MAX_CHAIR_COUNT        6				//最大椅子数
class MainSceneBase:public CCLayer,public GameLogic
{
public:
	//椅子位置
	CCPoint posChair[MAX_CHAIR_COUNT];
	//扑克层
	CardLayerBase *cardLayer;
	//玩家信息层
	PlayerLayer *playerLayer;
public:
    MainSceneBase();
    ~MainSceneBase();
	virtual void onEnter();
	virtual void onExit();
	//初始化玩家信息层
	void initPlayerLayer();
};
