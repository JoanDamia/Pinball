#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"

class PhysBody;

struct Bumper {

	PhysBody* bump;
};

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
	//void player();
	//void CreateFlippers();
public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;
	p2List<Bumper*> bumpers;

	PhysBody* l_flipper;
	PhysBody* l_flipperC;
	PhysBody* r_flipper;
	PhysBody* r_flipperC;
	b2RevoluteJointDef revoluteJointDef_rFlipper;
	b2RevoluteJointDef revoluteJointDef_lFlipper;
	//int flipperF;
	
	//p2List<PhysBody*> palo1;

	Spring spring1;
	
	PhysBody* sensor;
	bool sensed;
	b2World* world;
	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	SDL_Texture* flipperL;
	SDL_Texture* flipperR;
	SDL_Texture* spring_1;
	//SDL_Texture* palo1_;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
};
