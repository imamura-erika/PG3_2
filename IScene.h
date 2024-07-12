#pragma once
#include "stdio.h"

// 基底クラス
class IScene
{
public:
	// 純粋仮想関数
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//virtual ~IScene();
};