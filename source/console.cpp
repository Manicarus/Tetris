#include "../header/console.h"
#include <sstream>
#include <cstdlib>

Console::Console(
	std::string title,
	Measure measure = {100, 30}
) : size(measure) {
	std::string conTitleStr("title ");
	conTitleStr.append(title);

	std::string conDimStr("mode con:");

	std::string conWidthStr = "cols=";
	std::stringstream ss;
	ss << width;
	conWidthStr.append(ss.str());

	ss.str("");
	std::string conHeightStr = " lines=";
	ss << height;
	conHeightStr.append(ss.str());

	conDimStr.append(conWidthStr);
	conDimStr.append(conHeightStr);

	system(conDimStr.c_str());
	system(conTitleStr.c_str());
}

void Console::render() {

}

// Referenced: https://gist.github.com/enghqii/c8711c5f04d3f3d2f8f2
