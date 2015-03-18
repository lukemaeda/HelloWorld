#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = HelloWorld::create();

    // シーンに子としてレイヤーを追加
    scene->addChild(layer);

    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面のサイズを取得
    // (画面の縦と横のサイズがとれる)
    Size visibleSize = Director::getInstance()->getVisibleSize();

    // 0座標を取得(画面の左下)
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    // 2. あなたはそれを修正することができ、プログラムを終了するをクリックする「X」の画像とメニュー項目を追加します。

    // ボタンイメージを設定
    // ここではMenuItemImageを使っています。
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",   // 第一引数は押下する前の画像
                                           "CloseSelected.png", // 第二引数は押下しているときの画像
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // メニュー作成は、自動解放オブジェクトです
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    
    // this
    //this->addChild(menu, 1);
    
    // this = HelloWorld::に変更
    HelloWorld::addChild(menu, 1);
    

    /////////////////////////////
    // 3. add your codes below...

    // ラベルを作成し、初期化する。
    // Label::createWithSystemFont("文字列", "フォントの種類", 文字サイズ);
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // ラベルを中央上部に位置に表示 座標を指定
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // this
    //this->addChild(label, 1);
    
    // labelをHelloWorld::layerに追加
    // this = HelloWorld::に変更
    HelloWorld::addChild(label, 1);

    // "HelloWorld" 画像を生成
    auto sprite = Sprite::create("HelloWorld.png");

    // "HelloWorld" 画像を画面の中央位置に表示  座標を指定
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // this
    //this->addChild(sprite, 0);
    
    // 画像をHelloWorld::layerに追加
    // this = HelloWorld::に変更
    HelloWorld::addChild(sprite, 0);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
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
