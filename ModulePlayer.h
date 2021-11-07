#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2List.h"
#include "ModulePhysics.h"

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
	
public:
	p2List<PhysBody*> circles;
	//SDL_Texture* circle;
	Spring spring;
	//
	

	bool sensed;

};