#ifndef GETDATE_TIMEZONES_H
#define GETDATE_TIMEZONES_H

/*
**  An entry in the lexical lookup table.
*/
typedef struct _TABLE {
    char *name;
    int	type;
    time_t value;
} TABLE;


extern TABLE const MilitaryTable[];
extern TABLE const TimezoneTable[];

#define HOUR(x)		((time_t)(x) * 60)
#endif
