#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "ModulePhysics.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void map();
	void colisions();
	void player();

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;
	p2List<PhysBody*> l_flipper;
	p2List < PhysBody*> r_flipper;

	
	//p2List<PhysBody*> palo1;
	
	PhysBody* sensor;
	bool sensed;
	b2World* world;
	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	SDL_Texture* flipperL;
	SDL_Texture* lKiker, * rKiker;
	SDL_Texture* spring3;
	//SDL_Texture* palo1_;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
};
