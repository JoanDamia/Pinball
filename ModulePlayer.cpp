#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePhysics.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"



ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	player();

	return true;
}
void ModulePlayer::player() {
	ball = App->physics->CreateCircle(550, 750, 15);
	
	ball->listener = this;
}
// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	if (fall == true)
	{
		ball->body->SetTransform(b2Vec2(PIXEL_TO_METERS(550), PIXEL_TO_METERS(750)), 0);

		/*muell = true;*/
		
		fall = false;
		
	}
	return UPDATE_CONTINUE;
}


update_status ModulePlayer::PostUpdate() {
	if (IsEnabled())
	{
		//SDL_Rect rect = currentAnimation->GetCurrentFrame();
		//App->renderer->Blit(texture, position.x, position.y, &rect);
	}
	else {
		score = 0000;
		scoreAnt = 00;
		highScore = 00;
		
	}
	sprintf_s(scoreText, 10, "%4d", score);
	//App->fonts->BlitText(339, 24, scoreFont, scoreText);

	sprintf_s(limitText, 10, "%4d", score);
//	App->fonts->BlitText(339, 34, scoreFont, limitText);

	sprintf_s(stageText, 10, "%2d", highScore);
	//App->fonts->BlitText(356, 12, scoreFont, stageText);

	App->renderer->Blit(table, 310, 10, NULL);

	return update_status::UPDATE_CONTINUE;
}
