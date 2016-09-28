#define DIMENSION 2

enum Color {
	RED,
	BLUE,
	GREEN
};

class Block {
public:
	Block();
	Block(float * newCenter);
	Block(const Block &block);

	void move(float [] d);
	void draw() const;
	void changeColor(int i);
    
private:
	float width  = 1.0;
	float height = 1.0;
	
	float center[DIMENSION] = {0.0, 0.0};
	
	enum Color color; 
};
