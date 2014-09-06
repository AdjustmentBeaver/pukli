#ifndef __CAMERA__
#define __CAMERA__

class Camera
{
public:
	Camera();
	~Camera();

	/*
		Talán valami ilyan lenne jó. 
		Ezen belül pedig lenne a játékosok egymáshoz viszonyított pozíciójának a vizsgálata, 
		utána pedig a SDL2_gfx rotozoomSurfaceXY (SDL_Surface *src, double angle, double zoomx, double zoomy, int smooth)
		????
	*/
	void update(SDL_Surface* surface, const std::vector<Game_object*> p_player_objects);

private:

};

#endif