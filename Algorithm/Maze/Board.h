#pragma once
#include "ConsoleHelper.h"

class Player;

enum 
{
	BOARD_MAX_SIZE = 100
};

enum class TileType
{
	NONE = 0,
	EMPTY,
	WALL,
};



class Board
{
public:
	Board();
	~Board();

	void Init(int32 size, Player* player);
	void Render();
	
	void GenerateMap_Kruskal();
	void GenerateMap_Prim();
	TileType GetTileType(Pos pos);
	ConsoleColor GetTileColor(Pos pos);

	// 시작 지점
	Pos GetEnterPos() { return Pos{ 1, 1 }; }
	// 출구
	Pos GetExitPos() { return Pos{ _size - 2, _size - 2 }; }
	int32 GetSize() { return _size; }
private:
	TileType _tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE] = {};
	int32 _size = 0;
	Player* _player = nullptr;
};