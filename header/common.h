#pragma once

// type turn y x
bool TetrominoLibrary[7][4][4][4]= {
	{ // SQUARE
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		}
	},
		
	{ // BAR
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		}
	},
	
	{ // R_SNAKE
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		},
			
		{
			0, 0, 0, 0,
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		},
		
		{
			0, 0, 0, 0,
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		}
	},
	
	{ // L_SNAKE
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0
		},
	
		{
			0, 0, 0, 0,
			0, 0, 1, 1,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,1,0
		},
		
		{
			0,0,0,0,
			0,0,1,1,
			0,1,1,0,
			0,0,0,0
		},
	},
	
	{ // R_GUN
		
		{
			0,0,0,0,
			0,1,0,0,
			0,1,0,0,
			0,1,1,0
		},
		
		{
			0,0,0,0,
			0,0,1,0,
			1,1,1,0,
			0,0,0,0
		},
		
		{
			0,0,0,0,
			1,1,0,0,
			0,1,0,0,
			0,1,0,0
		},
		
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,0,
			1,0,0,0
		}
	},

	{ // L_GUN
		
		{
			0,0,0,0,
			0,1,0,0,
			0,1,0,0,
			1,1,0,0
		},
		
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,0,
			0,0,1,0
		},
		
		{
			0,0,0,0,
			0,1,1,0,
			0,1,0,0,
			0,1,0,0
		},
		
		{
			0,0,0,0,
			1,0,0,0,
			1,1,1,0,
			0,0,0,0
		}
	},
	
	{ // T_SHAPE
		{
			0,0,0,0,
			0,1,0,0,
			1,1,1,0,
			0,0,0,0
		},
		
		{
			0,0,0,0,
			0,1,0,0,
			1,1,0,0,
			0,1,0,0
		},
		
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,0,
			0,1,0,0
		},
		
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,1,0,0
		}
	}
};