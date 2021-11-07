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
	void CreateFlippers();
public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;
	p2List<Bumper*> bumpers;

	PhysBody* l_flipper1 = nullptr;
	PhysBody* l_flipperC1;
	PhysBody* l_flipper2;
	PhysBody* l_flipperC2;
	PhysBody* r_flipper1 = nullptr;
	PhysBody* r_flipperC1;
	PhysBody* r_flipper2;
	PhysBody* r_flipperC2;
	b2RevoluteJointDef revoluteJointDef_rFlipper1;
	b2RevoluteJointDef revoluteJointDef_lFlipper1;
	b2RevoluteJointDef revoluteJointDef_rFlipper2;
	b2RevoluteJointDef revoluteJointDef_lFlipper2;
	int flipperF;
	
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
