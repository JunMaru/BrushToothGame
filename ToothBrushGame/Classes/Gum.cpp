//
//  Gum.cpp
//  ToothBrushGame
//
//  Created by 丸山 潤 on 2014/10/14.
//
//
#include "TextureFile.h"
#include "Gum.h"
#include "LifeBar.h"

//================================================================================
// コンストラクタ
//================================================================================
Gum::Gum(void)
{
    // メンバ変数の初期化
    m_pSprite = nullptr;
    m_nDamageTimer = DAMAGE_PERMISSION_TIME;
}

//================================================================================
// デストラクタ
//================================================================================
Gum::~Gum()
{
    
}

//================================================================================
// 初期化処理
//================================================================================
bool Gum::init(void)
{
    // スプライトの作成
    m_pSprite = Sprite::create();
    
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
void Gum::uninit(void)
{
    
}

//================================================================================
// 更新処理
//================================================================================
void Gum::update(void)
{
    m_nDamageTimer++;
}

//================================================================================
// 生成処理
//================================================================================
Gum* Gum::create(const Vec2& pos)
{
    // インスタンスの生成
    Gum* pGum = new Gum();
    
    // メンバ変数の代入
    pGum->m_pos = pos;
    
    // 初期化
    pGum->init();
    
    return pGum;
}

//================================================================================
// ダメージ処理
//================================================================================
void Gum::addDamage(int nDamage)
{
    if(m_nDamageTimer >= DAMAGE_PERMISSION_TIME)
    {
        m_nDamageTimer = 0;
    }
}