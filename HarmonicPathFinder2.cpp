
////////////////////////////////////////////////////////////////

///// Includes /////

#include <cstdio>
#include <string>
#include <vector>
#include <map>

////////////////////////////////////////////////////////////////

///// Constants /////

/* Chord Types */

enum Chord
{
	Chd_Major,
	Chd_MajorDom,
	Chd_Minor,
	Chd_HalfDim
};
inline std::string const&

/* Intervals */

enum : int
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
	Itv_8
};

/* Scales */

// static const std::map<int, >

////////////////////////////////////////////////////////////////

///// Main /////

int main(void)
{
	std::printf("uhhh %i\n", Chd_MajorDom);

	return 0;
}

////////////////////////////////////////////////////////////////
