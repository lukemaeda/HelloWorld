#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

// public cocos2d::Layerクラスを継承している　一枚の透明の紙のようなもの
class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // 初期化のメソッド
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // create()を使えるようにしている。
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
