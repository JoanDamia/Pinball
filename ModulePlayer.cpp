#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");


	/*spring.pivot = App->physics->CreateSpring1(555, 1010, 50, 30);
	spring.mobile = App->physics->CreateSpring2(555, 920, 40, 40);
	App->physics->CreatePrismaticJoint(spring.mobile, { 0,0 }, spring.pivot, { 0,0 }, { 0,4 }, 3.9f);*/
	/*spring_1 = App->textures->Load("pinball/muelle.png");*/
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	/*App->textures->Unload(spring_1);*/
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	/*App->renderer->Blit(spring_1, x, y, false);*/
	//App->renderer->Blit(spring_, 555, 920, NULL, 1.0f);
	/*spring.mobile->body->ApplyForce({ 0,-30 }, { 0,0 }, true);
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		spring.mobile->body->ApplyForce({ 0,80 }, { 0,0 }, true);
	}
	else if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP)
	{
		spring.mobile->body->ApplyForce({ 0,-900 }, { 0,0 }, true);
		
	}
	

	/*if (App->input->GetKey(SDL_SCANCODE_DOWN) != KEY_REPEAT)
	{
		App->renderer->Blit(spring_1, 555, 1010);
	}
	else
	{
		App->renderer->Blit(spring_1, 555, 920);
	}*/


	return UPDATE_CONTINUE;

}



