#ifndef __CAMERA__
#define __CAMERA__

class Camera
{
public:
	Camera();
	~Camera();

	/*
		Tal�n valami ilyan lenne j�. 
		Ezen bel�l pedig lenne a j�t�kosok egym�shoz viszony�tott poz�ci�j�nak a vizsg�lata, 
		ut�na pedig a SDL2_gfx rotozoomSurfaceXY (SDL_Surface *src, double angle, double zoomx, double zoomy, int smooth)
		????
	*/
	void update(SDL_Surface* surface, const std::vector<Game_object*> p_player_objects);

private:

};

#endif