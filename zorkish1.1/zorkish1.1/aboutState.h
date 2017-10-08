#pragma once
#include "GameState.h"
class aboutState :
	public GameState
{
public:
	aboutState();
	~aboutState();
	void input();
	void render();
};

