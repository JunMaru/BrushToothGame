//
//  GameDifficult.h
//  ToothBrushGame
//
//  Created by 鈴木愛忠 on 2014/10/24.
//
//

#ifndef ToothBrushGame_GameDifficult_h
#define ToothBrushGame_GameDifficult_h
#include <cocos2d.h>
#include "Enemy.h"
using namespace cocos2d;

//ゲームのウェーブ調整
enum GAME_PHASE{
    PHASE_ONE = 0,
    PHASE_TWO,
    PHASE_TREE,
    PHASE_MAX
};

struct GAME_PASE_DATA{
    Enemy::ENEMY_KIND enemykind;//どの種類の敵か
    int spawn;//軟体出てくるか
    int spawnTime;//何秒後に出てくるか
    Point pos;//どこに出てくるか

};

#endif