//
//  Item.cpp
//  ToothBrushGame
//
//  Created by 川原 岳大 on 2014/10/16.
//
//

//********************************************************************************
// インクルード
//********************************************************************************
#include "TextureFile.h"
#include "Sound.h"
#include "Item.h"

//================================================================================
// コンストラクタ
//================================================================================
Item::Item(void)
{
    // メンバ変数の初期化
    m_pSprite = nullptr;
}

//================================================================================
// デストラクタ
//================================================================================
Item::~Item()
{

}

//================================================================================
// 初期化処理
//================================================================================
bool Item::init(void)
{
    // スプライトの作成
    m_pSprite = Sprite::create(TEX_ITEM_BACK);

    // エラーチェック
    if(m_pSprite == nullptr)
    {
        // スプライト生成エラー
        return false;
    }

    // スプライトの座標設定
    m_pSprite->setPosition(m_pos);

    // 正常終了
    return true;
}

//================================================================================
// 終了処理
//================================================================================
void Item::uninit(void)
{

}

//================================================================================
// 更新処理
//================================================================================
void Item::update(void)
{
    //m_pToothSprite->setPosition(m_pos);


}

//================================================================================
// 生成処理
//================================================================================
Item* Item::create(const Vec2& pos)
{
    // インスタンスの生成
    Item* pItem = new Item();

    // メンバ変数の代入
    pItem->m_pos = pos;

    // 初期化
    pItem->init();

    return pItem;
}