
////////////////////////////////////////////////////////////////

///// Includes /////

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <array>

////////////////////////////////////////////////////////////////

///// Constants /////

/* Chord Types */

enum ChordType : size_t
{
	Chd_Major = 0,
	Chd_MajorDom,
	Chd_Minor,
	Chd_HalfDim
};

inline std::string const& Str(ChordType the)
{
	switch (the)
	{
	case Chd_Major:
		{
			static const std::string ret("Major");
			return ret;
		}
	case Chd_MajorDom:
		{
			static const std::string ret("Major-Dominant");
			return ret;
		}
	case Chd_Minor:
		{
			static const std::string ret("Minor");
			return ret;
		}
	case Chd_HalfDim:
		{
			static const std::string ret("Half-Diminished");
			return ret;
		}
	default:
		{
			static const std::string ret("ERROR-CHORD");
			return ret;
		}
	}
}

/* Intervals */

typedef size_t Interval;

enum : Interval
{
	Itv_1 = 0,
	Itv_b2,
	Itv_2,
	Itv_b3,
	Itv_3,
	Itv_4,
	Itv_b5,
	Itv_5,
	Itv_b6,
	Itv_6,
	Itv_b7,
	Itv_7,
	Itv_8 // should be 12
};

inline std::string const& Str(Interval the)
{
	switch (the)
	{
	case Itv_1:
		{
			static const std::string ret("1");
			return ret;
		}
	case Itv_b2:
		{
			static const std::string ret("b2");
			return ret;
		}
	case Itv_2:
		{
			static const std::string ret("2");
			return ret;
		}
	case Itv_b3:
		{
			static const std::string ret("b3");
			return ret;
		}
	case Itv_3:
		{
			static const std::string ret("3");
			return ret;
		}
	case Itv_4:
		{
			static const std::string ret("4");
			return ret;
		}
	case Itv_b5:
		{
			static const std::string ret("b5");
			return ret;
		}
	case Itv_5:
		{
			static const std::string ret("5");
			return ret;
		}
	case Itv_b6:
		{
			static const std::string ret("b6");
			return ret;
		}
	case Itv_6:
		{
			static const std::string ret("6");
			return ret;
		}
	case Itv_b7:
		{
			static const std::string ret("b7");
			return ret;
		}
	case Itv_7:
		{
			static const std::string ret("7");
			return ret;
		}
	case Itv_8:
		{
			static const std::string ret("8");
			return ret;
		}
	default:
		{
			static const std::string ret("ERROR-NOTE");
			return ret;
		}
	}
}

/* Scales */

static const std::vector<std::tuple<Interval, ChordType>> Scl_Ionian
{
	std::make_tuple(Itv_1, Chd_Major),
	std::make_tuple(Itv_2, Chd_Minor),
	std::make_tuple(Itv_3, Chd_Minor),
	std::make_tuple(Itv_4, Chd_Major),
	std::make_tuple(Itv_5, Chd_MajorDom),
	std::make_tuple(Itv_6, Chd_Minor),
	std::make_tuple(Itv_7, Chd_HalfDim)
};

static const std::vector<std::tuple<Interval, ChordType>> Scl_Dorian
{
	std::make_tuple(Itv_1, Chd_Minor),
	std::make_tuple(Itv_2, Chd_Minor),
	std::make_tuple(Itv_b3, Chd_Major),
	std::make_tuple(Itv_4, Chd_MajorDom),
	std::make_tuple(Itv_5, Chd_Minor),
	std::make_tuple(Itv_6, Chd_HalfDim),
	std::make_tuple(Itv_b7, Chd_Major)
};

static const std::vector<std::tuple<Interval, ChordType>> Scl_Phrygian
{
	std::make_tuple(Itv_1, Chd_Minor),
	std::make_tuple(Itv_b2, Chd_Major),
	std::make_tuple(Itv_b3, Chd_MajorDom),
	std::make_tuple(Itv_4, Chd_Minor),
	std::make_tuple(Itv_5, Chd_HalfDim),
	std::make_tuple(Itv_b6, Chd_Major),
	std::make_tuple(Itv_b7, Chd_Minor)
};

////////////////////////////////////////////////////////////////

///// Main /////

typedef std::array<std::array<std::vector<std::string>, 4>, 12> pathsFound_t;

/* Forward Declarations */

void addChordsFrom(int maxRecursion, pathsFound_t& pathsFound, Interval newRoot);
void addChordsFrom_h(int maxRecursion, pathsFound_t& pathsFound, std::string pathStr, Interval newRoot);

/* Main */

int main(void)
{
	pathsFound_t pathsFound;

	addChordsFrom(2, pathsFound, Itv_1);

	for (size_t i = 0; i < pathsFound.size(); i++)
	{
		std::cout << "(" << Str((Interval)i) << ")\n";

		for (size_t j = 0; j < pathsFound[i].size(); j++)
		{
			std::cout << "  " << Str((ChordType)j) << "\n";

			for (size_t k = 0; k < pathsFound[i][j].size(); k++)
			{
				std::cout << "    * " << pathsFound[i][j][k] << "\n";
			}
		}
	}

	return 0;
}

/* Helpers */

void addChordsFrom(int maxRecursion, pathsFound_t& pathsFound, Interval newRoot)
{
	addChordsFrom_h(maxRecursion, pathsFound, "", newRoot);
}

void addChordsFrom_h(int maxRecursion, pathsFound_t& pathsFound, std::string pathStr, Interval newRoot)
{
	if (maxRecursion <= 0)
	{ return; }

	for (size_t i = 0; i < Scl_Ionian.size(); i++)
	{
		Interval interval = std::get<0>(Scl_Ionian[i]);
		Interval actualNote = (newRoot + interval) % 12;
		ChordType chordType = std::get<1>(Scl_Ionian[i]);

		std::string newPathStr = pathStr;
		if (pathStr.size() > 0)
		{ newPathStr += "-"; }
		newPathStr += Str(interval);

		pathsFound[actualNote][chordType].push_back(newPathStr);
		addChordsFrom_h(maxRecursion - 1, pathsFound, newPathStr, actualNote);
	}
}

////////////////////////////////////////////////////////////////
