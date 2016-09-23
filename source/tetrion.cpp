Tetrion::Tetrion(Playfield *playfield) : Component(playfield) {
	const int CEILING = 0;
	const int FLOOR = canvas.height - 1;
	const int LEFT = 0;
	const int RIGHT = canvas.width - 1;
	
	int pos;
	
	for(int i = CEILING; i <= FLOOR; i++) {
		for(int j = LEFT; j <= RIGHT; j++) {
			pos = (i + x) * width + (j + y);
			if(i == CEILING || i == FLOOR) {
				canvas[pos] = true;
			} else {
				if(j == LEFT || j == RIGHT) {
					canvas[pos] = true;
				} else {
					canvas[pos] = false;
				}
			}
		}
	}
}
