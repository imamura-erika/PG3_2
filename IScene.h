#pragma once

#include "Novice.h"

// シーンの定義
enum SCENE { TITLE, STAGE, CLEAR };

// シーン内での処理を行う基底クラス
class IScene {
protected:
	// シーン番号を管理する変数
	static int sceneNo;

public:
	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update(char* keys, char* preKeys) = 0;
	virtual void Draw() = 0;

	// 仮想デストラクタ
	virtual ~IScene();

	// シーン番号のゲッター
	int GetSceneNo();
};