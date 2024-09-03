
////////////////////////////////////////////////////////////////

///// Includes /////

#include <cstdio>
#include <vector>

////////////////////////////////////////////////////////////////

///// Constants /////

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

/* Chords */

static const std::vector<int> Chd_major
{
	Itv_1,
	Itv_3,
	Itv_5
};

/* Modes */

static const std::vector<int> Scl_ionian
{
	Itv_1,
	Itv_2,
	Itv_3,
	Itv_4,
	Itv_5,
	Itv_6,
	Itv_7
};

static const std::vector<int> Scl_dorian
{
	Itv_1,
	Itv_2,
	Itv_b3,
	Itv_4,
	Itv_5,
	Itv_6,
	Itv_b7
};

static const std::vector<int> Scl_phrygian
{
	Itv_1,
	Itv_b2,
	Itv_b3,
	Itv_4,
	Itv_5,
	Itv_b6,
	Itv_b7
};

static const std::vector<int> Scl_lydian
{
	Itv_1,
	Itv_2,
	Itv_3,
	Itv_b5,
	Itv_5,
	Itv_6,
	Itv_7
};

static const std::vector<int> Scl_mixolydian
{
	Itv_1,
	Itv_2,
	Itv_3,
	Itv_4,
	Itv_5,
	Itv_6,
	Itv_b7
};

static const std::vector<int> Scl_aeolian
{
	Itv_1,
	Itv_2,
	Itv_b3,
	Itv_4,
	Itv_5,
	Itv_b6,
	Itv_b7
};

static const std::vector<int> Scl_locrian
{
	Itv_1,
	Itv_b2,
	Itv_b3,
	Itv_4,
	Itv_b5,
	Itv_b6,
	Itv_b7
};

////////////////////////////////////////////////////////////////

///// Main /////

int main(void)
{
	for (int i = 0; i < Chd_major.size(); i++)
	{
		std::printf("%i\n", Chd_major[i]);
	}

	return 0;
}

////////////////////////////////////////////////////////////////
