#pragma once

#include <Player.h>
class Player;

// コマンドを抽象的に呼び出すクラス
class ICommand {
public:
	virtual ~ICommand(); // デストラクタ
	virtual void Exec(Player& player) = 0; //コマンド実行関数
};

// 右移動
class MoveRightCommand :public ICommand {
public:
	void Exec(Player& Player) override;
};

// 左移動
class MoveLeftCommand :public ICommand {
public:
	void Exec(Player& Player) override;
};