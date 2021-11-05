#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
	ray_on = false;
	sensed = false;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/BB8 def.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/pinball3.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");
	App->audio->PlayMusic("pinball/starwars.ogg");
	flipperL=App->textures->Load("pinball/flipperL"); 
	
	map();
	colisions();
	player();
	//sensor = App->physics->CreateRectangleSensor(SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH, 50);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}
void ModuleSceneIntro::map() {
	// Pivot 0, 0
	int rick_head[50] = {
	1, 755,
	173, 1029,
	173, 1060,
	353, 1060,
	353, 1030,
	523, 773,
	530, 774,
	530, 1030,
	578, 1030,
	578, 174,
	573, 142,
	564, 114,
	553, 95,
	541, 79,
	527, 61,
	512, 46,
	493, 31,
	478, 21,
	462, 12,
	445, 4,
	426, 0,
	1, 1,
	0, 576,
	0, 637,
	0, 743
	};

	ricks.add(App->physics->CreateChain(0, 0, rick_head, 50));

	int wall[72] = {
	522, 773,
	527, 220,
	521, 201,
	512, 178,
	503, 160,
	491, 144,
	479, 131,
	458, 112,
	439, 100,
	411, 88,
	390, 82,
	369, 79,
	347, 78,
	326, 81,
	307, 86,
	287, 93,
	280, 98,
	259, 96,
	282, 84,
	296, 78,
	316, 74,
	338, 69,
	360, 69,
	382, 71,
	407, 76,
	428, 84,
	451, 95,
	469, 108,
	480, 118,
	495, 133,
	507, 148,
	517, 167,
	527, 186,
	534, 205,
	536, 217,
	532, 773
	};

	ricks.add(App->physics->CreateChain(0, 0, wall, 72));

	int rojo[10] = {
	434, 681,
	444, 680,
	443, 816,
	432, 815,
	434, 688
	};

	ricks.add(App->physics->CreateChain(0, 0, rojo, 10));
	int azul[10] = {
		71, 681,
		82, 682,
		90, 811,
		79, 811,
		71, 689
	};

	ricks.add(App->physics->CreateChain(0, 0, azul, 10));
	int verde[8] = {
		91, 809,
		172, 879,
		167, 886,
		79, 809
	};

	ricks.add(App->physics->CreateChain(0, 0, verde, 8));
	int otroverde[8] = {
		434, 804,
		357, 870,
		363, 881,
		443, 810
	};

	ricks.add(App->physics->CreateChain(0, 0, otroverde, 8));
	int otro[10] = {
		459, 329,
		462, 320,
		527, 351,
		526, 361,
		464, 332
	};

	ricks.add(App->physics->CreateChain(0, 0, otro, 10));
	int otromas[10] = {
		57, 316,
		61, 324,
		0, 353,
		-3, 345,
		53, 320
	};

	ricks.add(App->physics->CreateChain(0, 0, otromas, 10));
}
void ModuleSceneIntro::colisions() {
	circles.add(App->physics->_CreateCircle(98, 118, 45));

	circles.add(App->physics->_CreateCircle(266, 302, 45));
	circles.add(App->physics->_CreateCircle(345, 698, 45));
	circles.add(App->physics->_CreateCircle(173, 527, 45));
}
void ModuleSceneIntro::player() {
	circles.add(App->physics->CreateCircle(550, 750, 15));
	App->renderer->Blit(circle, 550, 750);
	
	/*circles.getLast()->data->listener = this;*/
}
// Update: draw background
update_status ModuleSceneIntro::Update()
{
	
	/*if(App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		ray_on = !ray_on;
		ray.x = App->input->GetMouseX();
		ray.y = App->input->GetMouseY();
	}*/

	
	
	//App->renderer->App->physics->l_flipper.Blit(flipperL, 183, 877);


	PhysBody* f = App->physics->l_flipper;

		int x, y;
		f->GetPosition(x, y);

		App->renderer->Blit(flipperL, x, y - 5, false, 1.0f, f->GetRotation());
		
		
	
	
		
	


	/*if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		boxes.add(App->physics->CreateRectangle(App->input->GetMouseX(), App->input->GetMouseY(), 100, 50));
	} */

	
		
		
	// Prepare for raycast ------------------------------------------------------
	
	iPoint mouse;
	mouse.x = App->input->GetMouseX();
	mouse.y = App->input->GetMouseY();
	int ray_hit = ray.DistanceTo(mouse);

	fVector normal(0.0f, 0.0f);

	// All draw functions ------------------------------------------------------
	p2List_item<PhysBody*>* c = circles.getFirst();

	/*while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		if(c->data->Contains(App->input->GetMouseX(), App->input->GetMouseY()))
			App->renderer->Blit(circle, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	c = boxes.getFirst();*/

	/*while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(box, x, y, NULL, 1.0f, c->data->GetRotation());
		if(ray_on)
		{
			int hit = c->data->RayCast(ray.x, ray.y, mouse.x, mouse.y, normal.x, normal.y);
			if(hit >= 0)
				ray_hit = hit;
		}
		c = c->next;
	}*/

	c = ricks.getFirst();

	while(c != NULL)
	{
		int x, y;
		c->data->GetPosition(x, y);
		App->renderer->Blit(rick, x, y, NULL, 1.0f, c->data->GetRotation());
		c = c->next;
	}

	App->renderer->Blit(lKiker, 100, 447, NULL, 1.0f, App->physics->l_flipper->GetRotation(), 10, 10);
	App->renderer->Blit(rKiker, 200, 447, NULL, 1.0f, App->physics->r_flipper->GetRotation(), 62, 9);
	

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		App->physics->r_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_UP)
		{
			App->physics->r_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		App->physics->l_flipper->body->ApplyForce({ 10, 80 }, { 0, 0 }, true);

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_UP)
		{
			App->physics->l_flipper->body->ApplyForce({ -10, -80 }, { 0, 0 }, true);
		}
	}

	
	static int forc = 0;
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		forc -= 10;
		App->physics->spring2->body->ApplyForceToCenter(b2Vec2(0, -forc), 1);
		/*forc -= 800;*/

		/*if (forc > 1800)
			forc = 1800;*/
		
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_UP) {
		/*App->physics->spring2->body->ApplyForceToCenter(b2Vec2(0, -forc), 1);*/
		if (forc > 4)
			forc = 4;
	}
	// ray -----------------
	if(ray_on == true)
	{
		fVector destination(mouse.x-ray.x, mouse.y-ray.y);
		destination.Normalize();
		destination *= ray_hit;

		App->renderer->DrawLine(ray.x, ray.y, ray.x + destination.x, ray.y + destination.y, 255, 255, 255);

		if(normal.x != 0.0f)
			App->renderer->DrawLine(ray.x + destination.x, ray.y + destination.y, ray.x + destination.x + normal.x * 25.0f, ray.y + destination.y + normal.y * 25.0f, 100, 255, 100);
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	int x, y;

	App->audio->PlayFx(bonus_fx);

	
	if(bodyA)
	{
		bodyA->GetPosition(x, y);
		App->renderer->DrawCircle(x, y, 50, 100, 100, 100);
	}

	if(bodyB)
	{
		bodyB->GetPosition(x, y);
		App->renderer->DrawCircle(x, y, 50, 100, 100, 100);
	}
}
