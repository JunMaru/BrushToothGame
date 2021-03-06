//
//  SoundManager.cpp
//  ToothBrushGame
//
//  Created by 川原 岳大 on 2014/10/27.
//
//

#include "SoundManager.h"

int SoundManager::m_nSoundId[SOUND_MAX];

const char* SOUND_NAME[SOUND_MAX] = {
    SE_POWDER_2,
    SE_BUTTON_1,
};

using namespace CocosDenshion;

void SoundManager::init()
{
    // BGM
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_ENEMY_SCENE_1);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_ENEMY_SCENE_5);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_GAME_CLEAR_1);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_STAGE_SELECT_1);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_STAGE_SELECT_2);
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(BGM_RESULT_1);

    //SE
    SimpleAudioEngine::getInstance()->preloadEffect(SE_BUTTON_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_START_BUTTON_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_ENEMY_DOWN_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_ENEMY_DOWN_2);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_ENEMY_DOWN_3);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_SWIPE_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_2);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_FULL_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_FULL_2);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_EXPLOSION_1);
        SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_EXPLOSION_2);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_SHAKE_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_SHAKE_2);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_FANFARE_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_GAME_OVER_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_GAME_OVER_2);
//    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_GET_ACHIEVEMENT_3);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_GET_ACHIEVEMENT_4);

    SimpleAudioEngine::getInstance()->unloadEffect(SE_TIME_REMAIND_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_TIME_REMAIND_2);

    for(int nloop = 0 ; nloop < SOUND_MAX;nloop++)
    {
        m_nSoundId[nloop] = 0;

    }

}


void SoundManager::uninit()
{

     //BGM

     SimpleAudioEngine::getInstance()->unloadEffect(BGM_ENEMY_SCENE_1);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_ENEMY_SCENE_2);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_ENEMY_SCENE_3);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_ENEMY_SCENE_4);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_GAME_CLEAR_1);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_STAGE_SELECT_1);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_STAGE_SELECT_2);
     SimpleAudioEngine::getInstance()->unloadEffect(BGM_RESULT_1);


    //SE
    SimpleAudioEngine::getInstance()->unloadEffect(SE_BUTTON_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_START_BUTTON_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_ENEMY_DOWN_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_ENEMY_DOWN_2);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_ENEMY_DOWN_3);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_SWIPE_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_POWDER_2);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_POWDER_FULL_1);
    SimpleAudioEngine::getInstance()->preloadEffect(SE_POWDER_FULL_2);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_POWDER_EXPLOSION_1);
        SimpleAudioEngine::getInstance()->unloadEffect(SE_POWDER_EXPLOSION_2);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_SHAKE_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_SHAKE_2);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_FANFARE_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_GAME_OVER_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_GAME_OVER_2);

    SimpleAudioEngine::getInstance()->unloadEffect(SE_GET_ACHIEVEMENT_3);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_GET_ACHIEVEMENT_4);

    SimpleAudioEngine::getInstance()->unloadEffect(SE_TIME_REMAIND_1);
    SimpleAudioEngine::getInstance()->unloadEffect(SE_TIME_REMAIND_2);
}

void SoundManager::playSoundID(SOUND_LABEL soundlabel)
{
    if(m_nSoundId[soundlabel] == 0)
    {
    //音量を設定 1.0 ~ 0.0
    SimpleAudioEngine::getInstance()->setEffectsVolume(SE_VOLUME_MAX);
    m_nSoundId[soundlabel] = SimpleAudioEngine::getInstance()->playEffect(SOUND_NAME[soundlabel], true);
    }
}

void SoundManager::stopSoundID(SOUND_LABEL soundlabel)
{
    if(m_nSoundId[soundlabel] != 0)
    {
    SimpleAudioEngine::getInstance()->stopEffect(m_nSoundId[soundlabel]);

    m_nSoundId[soundlabel] = 0;
    }

}
