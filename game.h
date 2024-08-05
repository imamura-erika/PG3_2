#pragma once
#define _USE_MATH_DEFINES
#include <Novice.h>
#include <math.h>
#include <Vector2.h>

extern const int kWindowWidth;
extern const int kWindowHeight;

void InitializeResources();

typedef struct Bullet {
	Vector2 pos;
	float width;
	float height;
	float radius;
	float speed;
	int isShoot;
} Bullet;

extern int title;
extern int explain;
extern int winImage;
extern int loseImage;

//ステージ
extern int stage;
extern int bgHeight;
extern int bgPosX;
extern int bgPosY;
extern int bgPosY2;
extern int bg1SpeedY; //スクロールスピード
extern int bg2SpeedY;

//プレイヤー
extern int player;
extern int playerBullet;

//敵
extern int enemy;
extern int enemyBullet;

//爆発画像
extern int explosion;

//プレイヤー
extern int playerPosX;
extern int playerPosY;
extern int playerSpeed;
extern int playerRadius; //プレイヤーの当たり判定の大きさ

// 弾の変数
extern Bullet bullet[1000];

extern int isPlayerAlive; //自機が生きているか
extern int playerAttackCount; //攻撃を当てた回数

//敵
extern int enemyPosX;
extern int enemyPosY;
extern int enemySpeed;
extern int enemyRadius; //敵の当たり判定の大きさ
//敵の弾
extern int enemyBulletPosX;
extern int enemyBulletPosY;
extern int enemyBulletRadius;
extern int enemyBulletSpeed;
extern bool isEnemyBulletShot;

extern int enemyRespawnTimer; //復活タイマー
extern int isEnemyAlive; //敵が生きているか

extern int enemyBulletShootTimer; // 敵の弾の発射間隔用のタイマー
extern int enemyBulletShootInterval; // 敵の弾の発射間隔（フレーム数）

extern int i; // iをforループの外で宣言

extern int plessToTitle;