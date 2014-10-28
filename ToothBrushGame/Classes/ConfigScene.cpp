//********************************************************************************

//  ConfigScene.cpp
//  ToothBrushGame
//
//  Created by 丸山 潤 on 2014/10/27.
//
//********************************************************************************
//********************************************************************************
// インクルード
//********************************************************************************
#include "ConfigScene.h"
#include "common.h"
#include "GameMainScene.h"

//********************************************************************************
// 静的メンバ変数宣言
//********************************************************************************
float ConfigScene::m_fShakePermissionDistance = 0.3f;

//================================================================================
// コンストラクタ
//================================================================================
ConfigScene::ConfigScene()
{

}

//================================================================================
// デストラクタ
//================================================================================
ConfigScene::~ConfigScene()
{

}

//================================================================================
// シーン生成
//================================================================================
Scene* ConfigScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = ConfigScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

//================================================================================
// 初期化処理
//================================================================================
bool ConfigScene::init(void)
{
    if( !Layer::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize() / 2 + SCREEN_CENTER;
    Vec2 origin = Director::getInstance()->getVisibleSize() / 2 - SCREEN_CENTER;

    //終了ボタン生成
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(ConfigScene::menuCloseCallback, this));

    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // 更新処理の追加
    this->scheduleUpdate();

    // タッチ機能の有効化
    m_pTouchEventOneByOne =  EventListenerTouchOneByOne::create();
    m_pTouchEventOneByOne->setSwallowTouches(true);
    m_pTouchEventOneByOne->onTouchBegan = CC_CALLBACK_2(ConfigScene::onTouchBegin,this);
    m_pTouchEventOneByOne->onTouchMoved = CC_CALLBACK_2(ConfigScene::onTouchMoved,this);
    m_pTouchEventOneByOne->onTouchCancelled = CC_CALLBACK_2(ConfigScene::onTouchCancelled, this);
    m_pTouchEventOneByOne->onTouchEnded = CC_CALLBACK_2(ConfigScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithFixedPriority(m_pTouchEventOneByOne, 1);

    // シェイク感度のラベル生成
    m_pShakeStatementLabel = Label::createWithSystemFont("シェイクの感度 低1~10高", "ariel", 16);
    m_pShakeStatementLabel->setColor(Color3B::WHITE);
    m_pShakeStatementLabel->enableOutline(Color4B::BLACK,5);
    m_pShakeStatementLabel->setPosition(visibleSize.width / 2,visibleSize.height / 2);
    this->addChild(m_pShakeStatementLabel);

    return true;
}

//================================================================================
// 更新処理
//================================================================================
void ConfigScene::update(float fTime)
{
        CCLOG("コンフィグなう");
}

//================================================================================
// ゲーム終了処理
//================================================================================
void ConfigScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

//================================================================================
// タップ開始判定
//================================================================================
bool ConfigScene::onTouchBegin(Touch* pTouch,Event* pEvent)
{
    // タッチ座標の取得
    m_touchPos = pTouch->getLocation();


    return true;
}

//================================================================================
// スワイプ判定
//================================================================================
void ConfigScene::onTouchMoved(Touch* pTouch,Event* pEvent)
{

    // タッチ座標の取得
    m_oldTouchPos = m_touchPos;
    m_touchPos = pTouch->getLocation();
}

//================================================================================
// タップ離した判定
//================================================================================
void ConfigScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
    this->getEventDispatcher()->removeEventListener(m_pTouchEventOneByOne);
    this->removeAllChildren();
    this->unscheduleUpdate();

    Director::getInstance()->popScene();

}

//================================================================================
// タッチ時に割り込み処理
//================================================================================
void ConfigScene::onTouchCancelled(Touch* pTouch, Event* pEvent)
{
    
}