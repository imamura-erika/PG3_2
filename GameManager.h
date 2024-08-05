#pragma once

#include <memory> // std::unique_ptrの使用
#include "IScene.h" // シーンの基底クラス
#include "StageScene.h" // 各シーンの読み込み
#include "TitleScene.h"
#include "ExplainScene.h"
#include "ClearScene.h"
#include "GameoverScene.h"

class GameManager {
private:
	// シーンを保持するメンバ変数　ポインタ
	std::unique_ptr<IScene> sceneArr_[5];

	// どのステージを呼び出すかを管理する変数
	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン

public:
	GameManager(); // コンストラクタ
	~GameManager(); // デストラクタ

	int Run(char* keys, char* preKeys); // ゲームループを呼び出す関数
};