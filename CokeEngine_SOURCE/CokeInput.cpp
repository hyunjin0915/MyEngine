#include "CokeInput.h"

namespace coke
{
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M'
	};

	std::vector<Input::Key> Input::mKeys = {};

	void Input::Initialize()
	{
		mKeys.resize((UINT)eKeyCode::End);
		for (int i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys[i] = key;
		}
	}
	void Input::Update()
	{
		for (int i = 0; i < mKeys.size(); i++)
		{
			//키가 눌렸는지여부
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Pressed;
				}
				else
				{
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed == true)
				{
					mKeys[i].state = eKeyState::Up;
				}
				else
				{
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;
			}
		}
	}
	bool Input::GetKeyDown(eKeyCode code)
	{
		return mKeys[(UINT)code].state == eKeyState::Down;
	}
	bool Input::GetKeyUp(eKeyCode code)
	{
		return mKeys[(UINT)code].state == eKeyState::Up;
	}
	bool Input::GetKey(eKeyCode code)
	{
		return mKeys[(UINT)code].state == eKeyState::Pressed;
	}
}