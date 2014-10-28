//********************************************************************************
//  ConfigScene.h
//  ToothBrushGame
//
//  Created by 丸山 潤 on 2014/10/27.
//
//********************************************************************************
//********************************************************************************
// インクルードガード
//********************************************************************************
#ifndef __ToothBrushGame__ConfigScene__
#define __ToothBrushGame__ConfigScene__

//********************************************************************************
// インクルード
//********************************************************************************
#include "cocos2d.h"

//********************************************************************************
// 名前空間の使用
//********************************************************************************
using namespace cocos2d;

//********************************************************************************
// クラス宣言
//********************************************************************************
class ConfigScene : public cocos2d::Layer
{
public:
    ConfigScene();
    ~ConfigScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void update(float fTime);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(ConfigScene);

    void configCloseCallback(void);

    void shakePermissionDistanceUpCallback(void);
    void shakePermissionDistanceDownCallback(void);

    static float getShakePermissionDistance(void);
    static void setShakePermissionDistance(float fDistance);

private:
    bool onTouchBegin(Touch* pTouch,Event* pEvent);
    void onTouchMoved(Touch* pTouch,Event* pEvent);
    void onTouchCancelled(Touch* pTouch,Event* pEvent);
    void onTouchEnded(Touch* pTouch,Event* pEvent);

    //メンバ変数
    Point m_touchPos;
    Point m_oldTouchPos;
    EventListenerTouchOneByOne* m_pTouchEventOneByOne;

    Sprite* m_pConfigCloseSprite;

    Sprite* m_pShakeUpArrowSprite;
    Sprite* m_pShakeDownArrowSprite;
    Label* m_pShakeStatementLabel;
    Label* m_pShakeNumLabel;

    static float m_fShakePermissionDistance;
};

#endif /* defined(__ToothBrushGame__ConfigScene__) */
