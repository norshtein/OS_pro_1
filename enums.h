#ifndef __ENUM_H__
#define __ENUM_H__

enum CarDirection{
	NTOS,
	STON,
	ETOW,
	WTOE
};

enum CarType{
	NORMAL,
	SPECIAL
};
enum LightStatus{
	RED,
	GREEN
};

enum CarStatus{
	RUNNING,
	WAITING
};

enum RoadType{
	NS,
	EW,
	CROSS
};

enum RoadStatus
{
	NSOCCUPY,
	EWOCCUPY,
	NOOCCUPY
};

enum CarPosition{
	STONN,
	STONS,
	NTOSN,
	NTOSS,
	ETOWN,
	ETOWS,
	WTOEN,
	WTOES
};

#define ISTONN 0
#define ISTONS 1
#define INTOSN 2
#define INTOSS 3
#define IETOWN 4
#define IETOWS 5
#define IWTOEN 6
#define IWTOES 7
#endif