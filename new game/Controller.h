#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

/* 
 * SDL與Core的交界，操作不是鍵盤或搖桿的待碼
 */

// C/C++ include
#include <map>

// SDL include
#include "SDL.h"

/*
 * 控制器為子物件，要回頭控制狀態機
 */
class StateMachine;

enum KeyCode
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT,

	SQUARE,
	TRIANGLE,
	CIRCLE,
	CROSS,

	CODE_NUM,// 迴圈計次用
};
enum KeyType
{
	RELEASED = 0,
	PRESSED = 1
};

struct ControlKey
{
	struct KeysData
	{
		KeyType type;
		int pressTime = 0;
		int releaseTime = 0;
	};

	KeyCode curr;// 最後觸發的KEY
	std::map<KeyCode, KeysData> log;// KEY紀錄大全
};

/*
 * 紀錄該控制器的設定
 */
struct ControlKeys
{
	int data[CODE_NUM];
};

class Controller
{
public:
	Controller();
	~Controller();

	Controller(ControlKeys controlKeys, StateMachine* stateMachine);

	void setControlKeys(ControlKeys ControlKeys);
	void transControl(SDL_Event &event);//操作輸入轉接介面


	ControlKeys getControlKeys();
	StateMachine* stateMachine_;
private:
	ControlKeys controlKeys_;//TODO : 紀錄控制鍵是那些，取得很爛重取
	
	ControlKey controlKey_;
};

#endif //INPUT_CONTROLLER_H