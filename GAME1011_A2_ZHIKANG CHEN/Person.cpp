#include "Person.h"
#include <random>
#include <time.h>
#include <fstream>
#include <string>

vector<string> LNAME {"Chen", "Goodman", "Last name", "Coolman" };
vector<string> FNAME { "Ken", "John", "Alice", "First Name", "Jack" };
vector<string> COLLEGE { "George Brown College", "Squidward Community College", "Asa Coco University",  };
vector<string> COURSE { "Game Programming", "Game Art", "Accounting", "Computer" };
vector<string> GPLATFOROM {"PC", "Temple OS", "Atari 2600", "TI-84", "Nokia N-Gage", "战斧F1", "KFConsole", "Google Stadia", "Xbox" };
vector<string> SPLATFOROM {"Disney Plus", "Crunchyroll","iTunes Store", "Netflix", "Youtube Premium", "Pornhub Premium" };

//Generate random student from the pool of string and put them into m_pParticipants
void Survey::Generate(int n)
{
	srand(time(nullptr));

	
	bool r = rand() % 2;
	for (int i = 0; i < n; ++i)
	{
		
		string name = FNAME[rand() % FNAME.size()] + " " + LNAME[rand() % LNAME.size()];
		int age = rand() % (100-18) + 18;
		string college = COLLEGE[rand() % COLLEGE.size()];
		string program = COURSE[rand() % COURSE.size()];
		int semester = rand() % 4 + 1;
		int timeWasted = rand() % 8766;
		
		//cout << "age " << age << endl;
		//cout << "semester " << semester << endl;
		//cout << "hour wasted " << timeWasted << endl;
		if (r)
		{
			string game = GPLATFOROM[rand() % GPLATFOROM.size()];
			m_pParticipants.push_back(new GamingStudent(name,age,college,program,semester, game,timeWasted));
			
		}
		else
		{
			string stream = SPLATFOROM[rand() % SPLATFOROM.size()];
			m_pParticipants.push_back(new NonGameingStudent(name, age, college, program, semester, stream, timeWasted));
		}
		r = rand() % 2;
	}
	
}

// Output string
string Survey::Process()
{
	int gamer = 0,
		nonGamer = 0;

	int gAverage = 0,
		gAverageHour = 0,
		ngAverage = 0,
		ngAverageHour = 0;

	int* stream = new int[SPLATFOROM.size()]{0},
		*game = new int[GPLATFOROM.size()]{0};

	int i1 = 0,
		i2 = 0;

	
	for (int i = 0; i < m_pParticipants.size(); ++i)
	{
		auto info = m_pParticipants[i]->GetInfo();
		if (info.type == GAMER)
		{
			++gamer;
			gAverage += info.age;
			gAverageHour += info.timeWaste;

			for(int i = 0; i < GPLATFOROM.size(); ++i)
			{
				if (info.preference == GPLATFOROM[i])
				{
					++game[i];

					if(game[i] > game[i1])
					{
						i1 = i;
					}
					break;
				}
			}
			
		}
		else
		{
			++nonGamer;
			ngAverage += info.age;
			ngAverageHour += info.timeWaste;
			for (int i = 0; i < SPLATFOROM.size(); ++i)
			{
				if (info.preference == SPLATFOROM[i])
				{
					++stream[i];
					if (stream[i] > stream[i2])
					{
						i2 = i;
					}
					break;
				}
			}
			
		}

		
	}
	gAverage /= gamer;
	gAverageHour /= gamer;
	
	ngAverage /= nonGamer;
	ngAverageHour /= nonGamer;
	string s;
	
	s += "Number of non gaming student: " + to_string(nonGamer);
	s += "\nAverage age of non gaming student: " + to_string(ngAverage);
	s += "\nMost perferred streaming service: " + SPLATFOROM[i2];
	s += "\nAverage hours spent consuming non-gaming entertainment: " + to_string(ngAverageHour);
	
	s += "\n\nNumber of gaming student: " + to_string(gamer);
	s += "\nAverage age of gaming student: " + to_string(gAverage);
	s += "\nMost perferred gaming device: " + GPLATFOROM[i1];
	s += "\nAverage hours spent consuming gaming entertainment: " + to_string(gAverageHour);
	return s;
}

void Survey::Clean()
{
	for (auto &p : m_pParticipants)
	{
		delete p;
		p = nullptr;
	}
	m_pParticipants.clear();
}
