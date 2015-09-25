#include "Game.h"
#include "Services.h"
#include <Timer.h>
#include <ctime>

Game* Game::mspGameInstance = NULL;

Game::Game() :
	EventListener(),
	mIsInitialized(false),
	mIsGameRunning(false)
{
	mEventSystem.addListener(EVENT_GAME_EXIT, this);

	setRemoveOnDestruct(false); // Game shouldn't auto remove itself from the event system.
}

Game::~Game()
{
	cleanup();
}

bool Game::init()
{
	if (mIsInitialized)
		return false;

	// Testing
	int displayWidth = 800, displayHeight = 640;
	
	// Initalize the systems.
	if (!mGraphicsSystem.init("Title", displayWidth, displayHeight))
		return false;
	if (!mInputSystem.init())
		return false;

	// Provide systems to the service locator.
	Services::init();
	Services::provideGraphicsSystem(&mGraphicsSystem);
	Services::provideInputSystem(&mInputSystem);
	Services::provideEventSystem(&mEventSystem);

	// TEMP
	const std::string PATH = "../assets/";
	mpStillKirbyTex = new Texture(PATH + "kirby.png");
	mpMovingKirbyTex = new Texture(PATH + "Kirby_12Frames_27x.png");
	mpBackgroundTex = new Texture(PATH + "background.png");

	// KIRBY WIDTH & HEIGHT
	const int KIRBYWIDTH = 27;
	const int KIRBYHEIGHT = 23;

	mpKirbyE = new Entity();
	mpKirbyAnim = new Animation(PLAYMODE_LOOP, 50);

	for (int i = 0; i < 12; i++)
	{
		Rect mKirbyRect;
		mKirbyRect.setX((float)(i % 12) * KIRBYWIDTH); // 12 is the # of sprites going across * how many pixels wide each is
		//mKirbyRect.setY((i / 0) * KIRBYHEIGHT); // 1 is the # of sprites going down * how many pixels tall each is
		mKirbyRect.setY(0);
		mKirbyRect.setWidth((float)KIRBYWIDTH);
		mKirbyRect.setHeight((float)KIRBYHEIGHT);

		mpKirbySprites[i] = new Sprite(mpMovingKirbyTex, mKirbyRect.getX(), mKirbyRect.getY(), mKirbyRect.getWidth(), mKirbyRect.getHeight());

		//mpKirbySprite[i].init(mpMovingKirbyTex, mKirbyRect.getX(), mKirbyRect.getY(), mKirbyRect.getWidth(), mKirbyRect.getHeight());
		mpKirbyAnim->addSprite(mpKirbySprites[i]);
	}

	mpKirbyE->setAnimation(*mpKirbyAnim);
	mpKirbyE->setRect(150, 150, KIRBYWIDTH, KIRBYHEIGHT);

	mpBackgroundSprite = new Sprite(mpBackgroundTex);
	mpBackgroundRect = new Rect(mpBackgroundSprite->getSourceX(), mpBackgroundSprite->getSourceY(), (float)(mpBackgroundSprite->getWidth()*2.5), (float)(mpBackgroundSprite->getHeight()*2.5));

	mIsInitialized = true;
	return true;
}

void Game::cleanup()
{
	if (mIsInitialized)
	{
		// Delete objects
		
		delete mpMovingKirbyTex;
		delete mpStillKirbyTex;
		delete mpKirbySprite;
		delete mpBackgroundRect;
		delete mpBackgroundSprite;
		delete mpBackgroundTex;
		
		delete mpKirbyE;
		//delete mpKirbyAnim;



		// Shutdown systems.
		mGraphicsSystem.cleanup();
		

		Services::cleanup();

		mIsInitialized = false;
	}
}

void Game::gameLoop()
{
	mIsGameRunning = true;

	int desiredFrameRate = 30; // Can load from a file later

	double mMSPerFrame = 1000.0 / (double) desiredFrameRate;
	float timeDelta = (float)(mMSPerFrame / 1000.0);
	Timer timer;

	// Begin game w/ intro here or go into loop

	// Main game loop.
	while (mIsGameRunning)
	{
		timer.start();

		mInputSystem.pollInput();
		update(timeDelta);
		draw();

		timer.sleepUntilElapsed(mMSPerFrame);
	}
}

void Game::endGame()
{
	mIsGameRunning = false;
}

void Game::update(float timeDelta)
{
	// Update
	mpKirbyE->update(timeDelta);
}

void Game::draw()
{
	// Draw
	Color blue(0, 0, 255, 255);
	mGraphicsSystem.clearToColor(blue);
	mGraphicsSystem.drawSprite(*mpBackgroundSprite, *mpBackgroundRect);
	mpKirbyE->draw();

	Color color(0, 0, 0, 255);
	Vector2f vect(300, 300);
	mGraphicsSystem.writeText("sup", color, vect, 64);

	mGraphicsSystem.drawTexture(mpStillKirbyTex, 200, 200);

	// Present the display and clear it
	mGraphicsSystem.flipDisplay();
}

void Game::handleEvent(const Event& theEvent)
{
	switch (theEvent.getType())
	{
		case EVENT_GAME_EXIT:
			endGame();
			break;
	}
}