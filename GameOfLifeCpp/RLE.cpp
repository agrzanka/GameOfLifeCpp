#include"RLE.h"
#include"GOL.h"
#include <string>

//decoder needs to change strings like 3t3f|1t5f to: true,true, true, false, false, false|true, false, false, false, false, false
//which gives us coordinates for pattern: {0,0},{1,0},{2,0},{0,1} and those are the "alive" cells to init a board. 

//encoder - analogical situation but reverse xD
vector<int>RLE::decode(vector<string>lines, int width)
{
	vector<int> output;

	for (int y = 0; y < lines.size(); y++)
	{
		string number = "";
		int x = 0;
		for (auto&c : lines[y])
		{
			if (c != 'F'&&c != 'T')
			{
				number += c;
				//x++;
			}
			else if (c == 'T')
			{
				int num = stoi(number);
				x += num;

				for (int xx = x + 1 - num; xx < x + 1; xx++)
				{
					int id = y * width + xx - 1;
					output.push_back(id);
					cout << id << endl;
				}
				number = "";
			}
			else {
				int num = stoi(number);
				x += num;
				number = "";
			}


		}
	}


	return output;
}