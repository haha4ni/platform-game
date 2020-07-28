#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

/* 
 * SDL�PCore����ɡA�ާ@���O��L�ηn�쪺�ݽX
 */

// C/C++ include
#include <map>

// SDL include
#include "SDL.h"

/*
 * ������l����A�n�^�Y����A��
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

	CODE_NUM,// �j��p����
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

	KeyCode curr;// �̫�Ĳ�o��KEY
	std::map<KeyCode, KeysData> log;// KEY�����j��
};

/*
 * �����ӱ�����]�w
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
	void transControl(SDL_Event &event);//�ާ@��J�౵����


	ControlKeys getControlKeys();
	StateMachine* stateMachine_;
private:
	ControlKeys controlKeys_;//TODO : ����������O���ǡA���o���꭫��
	
	ControlKey controlKey_;
};

#endif //INPUT_CONTROLLER_H