
////////////////////////////////////////////////////////////////

///// Includes /////

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <array>
#include <memory>

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

typedef std::vector<std::tuple<Interval, ChordType>> Scl_t;

static std::unique_ptr<Scl_t const> const Scl_Ionian = std::make_unique<Scl_t const>
(
	Scl_t
	{
		std::make_tuple(Itv_1, Chd_Major),
		std::make_tuple(Itv_2, Chd_Minor),
		std::make_tuple(Itv_3, Chd_Minor),
		std::make_tuple(Itv_4, Chd_Major),
		std::make_tuple(Itv_5, Chd_MajorDom),
		std::make_tuple(Itv_6, Chd_Minor),
		std::make_tuple(Itv_7, Chd_HalfDim)
	}
);

static std::unique_ptr<Scl_t const> const Scl_Dorian = std::make_unique<Scl_t const>
(
	Scl_t
	{
		std::make_tuple(Itv_1, Chd_Minor),
		std::make_tuple(Itv_2, Chd_Minor),
		std::make_tuple(Itv_b3, Chd_Major),
		std::make_tuple(Itv_4, Chd_MajorDom),
		std::make_tuple(Itv_5, Chd_Minor),
		std::make_tuple(Itv_6, Chd_HalfDim),
		std::make_tuple(Itv_b7, Chd_Major)
	}
);

////////////////////////////////////////////////////////////////

///// Main /////

typedef std::array<std::array<std::vector<std::string>, 4>, 12> pathsFound_t;

/* Forward Declarations */

void addChordsFrom(int maxRecursion, pathsFound_t& pathsFound, Interval newRoot);
void addChordsFrom_h(int recursionLevel, pathsFound_t& pathsFound, Scl_t const* scale, Interval newRoot, std::string pathStr);

/* Main */

int main(void)
{
	pathsFound_t pathsFound;

	addChordsFrom(3, pathsFound, Itv_1);

	for (size_t i = 0; i < pathsFound.size(); i++)
	{
		std::cout << "(" << Str((Interval)i) << ")\n";

		for (size_t j = 0; j < pathsFound[i].size(); j++)
		{
			std::cout << "  " << Str((ChordType)j) << "\n";

			for (size_t k = 0; k < pathsFound[i][j].size(); k++)
			{
				std::cout << "    " << pathsFound[i][j][k] << "\n";
			}
		}
	}

	return 0;
}

/* Helpers */

void addChordsFrom(int maxRecursion, pathsFound_t& pathsFound, Interval newRoot)
{
	addChordsFrom_h(maxRecursion, pathsFound, Scl_Ionian.get(), newRoot, "");
	addChordsFrom_h(1, pathsFound, Scl_Dorian.get(), newRoot, "");
}

void addChordsFrom_h(int recursionLevel, pathsFound_t& pathsFound, Scl_t const* scale, Interval newRoot, std::string pathStr)
{
	if (recursionLevel <= 0)
	{ std::fprintf(stderr, "THIS SHOULD NOT HAPPEN\n"); }

	for (size_t i = 1; i < scale->size(); i++)
	{
		Interval interval = std::get<0>(scale->at(i));
		Interval actualNote = (newRoot + interval) % 12;
		ChordType chordType = std::get<1>(scale->at(i));

		std::string newPathStr;
		{
			newPathStr += pathStr;

			if (pathStr.size() > 0)
			{ newPathStr += "-"; }

			if (scale == Scl_Dorian.get())
			{ newPathStr += "(dor)"; }

			newPathStr += Str(interval);
		}

		pathsFound[actualNote][chordType].push_back(newPathStr);

		if (recursionLevel > 1)
		{
			addChordsFrom_h(recursionLevel - 1, pathsFound, Scl_Ionian.get(), actualNote, newPathStr);
			addChordsFrom_h(1, pathsFound, Scl_Dorian.get(), actualNote, newPathStr);
		}
	}
}

////////////////////////////////////////////////////////////////
