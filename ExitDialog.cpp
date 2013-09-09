#include "ExitDialog.h"
#include "cocos2d.h"
#include "PlayScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;
bool ExitDlg::onInitDialog()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite* pSprite = CCSprite::create("hui.png");
	pSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(pSprite, 0);

    CCLabelTTF *label = CCLabelTTF::create("you win", "", 64);
    label->setPosition(ccp(winSize.width / 2, winSize.height / 2 + 50));
    this->addChild(label);

    CCMenuItemFont *okMenuItem = CCMenuItemFont::create("Start", this, menu_selector(ExitDlg::okMenuItemCallback));
    okMenuItem->setPosition(ccp(winSize.width / 2 - 100, winSize.height / 2 - 50));

    CCMenuItemFont *cancelMenuItem = CCMenuItemFont::create("Exit", this, menu_selector(ExitDlg::cancelMenuItemCallback));
    cancelMenuItem->setPosition(ccp(winSize.width / 2 + 100, winSize.height / 2 - 50));

    pushMenu(okMenuItem);
    pushMenu(cancelMenuItem);

    //setColor(ccc3(255,0,0));
    setOpacity(128);
    return true;
}

void ExitDlg::okMenuItemCallback(CCObject *obj)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5, PlayScene::scene()));
}

void ExitDlg::cancelMenuItemCallback(CCObject *obj)
{
    //removeFromParentAndCleanup(true);
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5, HelloWorld::scene()));
}