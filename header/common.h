#pragma once

#define X false
#define O true

// type turn y x
bool TetrominoLibrary[7][4][4][4]= {
	{ // SQUARE
		{
			X, X, X, X,
			X, O, O, X,
			X, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, O, O, X,
			X, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, O, O, X,
			X, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, O, O, X,
			X, O, O, X,
			X, X, X, X
		}
	},
		
	{ // BAR
		{
			X, X, X, X,
			X, X, X, X,
			O, O, O, O,
			X, X, X, X
		},
		
		{
			X, O, X, X,
			X, O, X, X,
			X, O, X, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			X, X, X, X,
			O, O, O, O,
			X, X, X, X
		},
		
		{
			X, O, X, X,
			X, O, X, X,
			X, O, X, X,
			X, O, X, X
		}
	},
	
	{ // R_SNAKE
		{
			X, X, X, X,
			X, X, O, X,
			X, O, O, X,
			X, O, X, X
		},
			
		{
			X, X, X, X,
			O, O, X, X,
			X, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, X, O, X,
			X, O, O, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			O, O, X, X,
			X, O, O, X,
			X, X, X, X
		}
	},
	
	{ // L_SNAKE
		{
			X, X, X, X,
			X, O, X, X,
			X, O, O, X,
			X, X, O, X
		},
	
		{
			X, X, X, X,
			X, X, O, O,
			X, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, O, X, X,
			X, O, O, X,
			X, X, O, X
		},
		
		{
			X, X, X, X,
			X, X, O, O,
			X, O, O, X,
			X, X, X, X
		},
	},
	
	{ // R_GUN
		
		{
			X, X, X, X,
			X, O, X, X,
			X, O, X, X,
			X, O, O, X
		},
		
		{
			X, X, X, X,
			X, X, O, X,
			O, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			O, O, X, X,
			X, O, X, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			X, X, X, X,
			O, O, O, X,
			O, X, X, X
		}
	},

	{ // L_GUN
		
		{
			X, X, X, X,
			X, O, X, X,
			X, O, X, X,
			O, O, X, X
		},
		
		{
			X, X, X, X,
			X, X, X, X,
			O, O, O, X,
			X, X, O, X
		},
		
		{
			X, X, X, X,
			X, O, O, X,
			X, O, X, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			O, X, X, X,
			O, O, O, X,
			X, X, X, X
		}
	},
	
	{ // T_SHAPE
		{
			X, X, X, X,
			X, O, X, X,
			O, O, O, X,
			X, X, X, X
		},
		
		{
			X, X, X, X,
			X, O, X, X,
			O, O, X, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			X, X, X, X,
			O, O, O, X,
			X, O, X, X
		},
		
		{
			X, X, X, X,
			X, O, X, X,
			X, O, O, X,
			X, O, X, X
		}
	}
};
