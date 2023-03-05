#pragma once
#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H

#include "CommonFunc.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 8
class MainObject : public BaseObject
{
public: 

	enum WalkType
	{
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
	};
	MainObject();
	~MainObject();

	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
	void set_clips();

	void DoPlayer(Map& map_data); //roi tu do va di chuyen nhan vat 
	void CheckToMap(Map& map_data); //Kiem tra xem su va cham i.e check xem co BLANK_TILE ko de roi tu do, dong cham vao tuong, vao dat
	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; };
	void CenterEntityOnMap(Map& map_data); //the name explains it: de nhan vat lam tam cua map => di chuyen map ezier
private:
	float x_val_;
	float y_val_;

	float x_pos_;
	float y_pos_;

	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[8];
	Input input_type_;
	int frame_;
	int status_;

	bool on_ground_;

	int map_x_; //dung de luu vi tri cua ban do
	int map_y_;
};





#endif