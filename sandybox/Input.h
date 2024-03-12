#pragma once

namespace Input{
	void Init();
	void Update();

	bool isKeyDown(unsigned int key);
	bool isKeyPressed(unsigned int key);

	double GetMouseX();
	double GetMouseY();


}