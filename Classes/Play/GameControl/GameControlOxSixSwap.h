//
//  GameHUD.h
//  BullfightGame
//
//  Created by 张 恒 on 15/3/16.
//
//
#pragma once
#include "GameControlBase.h"
#include "../../GameLogic/GameLogic.h"
class GameControlOxSixSwap:public GameControlBase,public GameLogic
{
public:
	GameControlOxSixSwap();
	~GameControlOxSixSwap();
	virtual void onEnter();
	virtual void onExit();
    CREATE_FUNC(GameControlOxSixSwap);
private:
	int getChairIndex(int meChairID,int chairID);
	//开牌
	virtual void menuOpenCard(CCObject* pSender, TouchEventType type);
	//用户进入
	virtual void onUserEnter();

	//游戏状态
	virtual bool OnSocketSubGameStatus(void * pData, WORD wDataSize);
	//游戏场景
	virtual bool OnEventSceneMessage(void * pData, WORD wDataSize);
	//////////////////////////////////////////////////////////////////////////
	//游戏中
	virtual void onEventGameIng(WORD wSubCmdID, void * pDataBuffer, unsigned short wDataSize);
	//用户叫庄
	virtual bool OnSubCallBanker(const void * pBuffer, WORD wDataSize);
	//用户下注
	virtual bool OnSubAddScore(const void * pBuffer, WORD wDataSize);
	//游戏开始
	virtual bool OnSubGameStart(const void * pBuffer, WORD wDataSize);
	//发牌消息
	virtual bool OnSubSendCard(const void * pBuffer, WORD wDataSize);
	//开牌
	virtual bool OnSubOpenCard(const void * pBuffer, WORD wDataSize);
	//设置基数
	bool OnSubGameBase(const void * pBuffer, WORD wDataSize);
	//用户换牌
	bool OnSubChangeCard(const void * pBuffer, WORD wDataSize);
	//游戏结束
	virtual bool OnSubGameEnd(const void * pBuffer, WORD wDataSize);
	//////////////////////////////////////////////////////////////////////////
	//获取视图位置
	virtual int getViewChairID(int severChairID);
	//隐藏用户
	virtual void hidePlayer(CMD_GR_UserStatus *userInfo);

	//用户准备
	virtual void onUserReady(CMD_GR_UserStatus *info);
	//virtual void onUserEnterWithUpdate(tagUserInfo *user);
	//换牌消息
	virtual void onUserChangeCard(int wParam, long lParam);
};
