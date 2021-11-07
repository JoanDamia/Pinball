#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2List.h"
#include "ModulePhysics.h"
#include "Animation.h"
#include "ModuleTextures.h"


struct Spring
{
	PhysBody* pivot;
	PhysBody* mobile;
};


class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	void player();
	bool CleanUp();
	update_status PostUpdate();
	SDL_Texture* texture = nullptr;
	//Animation* currentAnimation;
	SDL_Texture* table = nullptr;
	int scoreFont = -1;
	char scoreText[10] = { "\0" };

	int limitFont = -1;
	char limitText[10] = { "\0" };

	int stageFont = -1;
	char stageText[10] = { "\0" };
	uint score = 0000;
	uint scoreAnt = 00;
	uint highScore = 00;
	iPoint position;
	int nPosX = 0;
	int nPosY = 0;
public:
	p2List<PhysBody*> circles;
	//SDL_Texture* circle;
	Spring spring;
	//
	

	bool sensed;

};