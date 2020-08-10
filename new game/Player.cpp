#include "Player.h"
#include "Controller.h"

Player::Player()
{
	//暫時開出一個夏露芙

	//設定碰撞
	struct CollisionBox* box = new CollisionBox{ 28, 12 ,18, 92};
	this->collisionBox_ = box;

	//設定sprite
	//載入圖
	this->sprite_ = new AnimatedSprite("Shalof_main.png");
	//載入相對應的frame
	int tmp[8] = { 10,10,10,10,10,10,10,10 };
	this->sprite_->addAnimation("idle", 8, tmp, 0, 0, 80, 120);
	this->sprite_->changeAnimation("idle");
	int tmp2[8] = { 10,10,10,10,10,10,10,10 };
	this->sprite_->addAnimation("walk", 8, tmp2, 0, 120, 80, 120);
	int tmp3[10] = { 5,5,5,5,5,5,5,5,5,5 };
	this->sprite_->addAnimation("run", 10, tmp3, 0, 240, 80, 120);
	int tmp4[2] = { 5,5 };
	this->sprite_->addAnimation("jump", 1, tmp4, 0, 480, 80, 120);
	int tmp5[5] = { 5,5,5,5,5 };
	this->sprite_->addAnimation("fall", 5, tmp5, 0, 360, 80, 120);


	//動作資料(座標 速度 狀態機)
	motionData_ = new MotionData;

	//目前的狀態機載入
	this->stateMachine_ = new Shalof::IdleState(this, this->motionData_);

	//控制器設定
	ControlKeys controlKeys;
	controlKeys.data[KeyCode::UP] = SDLK_UP;
	controlKeys.data[KeyCode::DOWN] = SDLK_DOWN;
	controlKeys.data[KeyCode::LEFT] = SDLK_LEFT;
	controlKeys.data[KeyCode::RIGHT] = SDLK_RIGHT;
	controlKeys.data[KeyCode::SQUARE] = 66666;
	controlKeys.data[KeyCode::TRIANGLE] = 66666;
	controlKeys.data[KeyCode::CIRCLE] = SDLK_x;
	controlKeys.data[KeyCode::CROSS] = SDLK_z;
	//控制器載入
	this->controller_ = new Controller(controlKeys, this->stateMachine_);
}

Player::~Player()
{
}

void Player::setStateMachine(StateMachine * stateMachine)
{
	Object::setStateMachine(stateMachine);
	this->controller_->stateMachine_ = stateMachine;
}
