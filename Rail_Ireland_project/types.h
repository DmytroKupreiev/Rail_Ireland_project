#pragma once

#define MAX_USERS 3
#define MAX_STRING 100
#define PASSWORD_LEN 6

#define PASSENGERS_PATH "passengers.txt"
#define DB_PATH			"database.txt"


typedef enum City {
	Dublin		= 1,
	Leinster	= 2,
	Connacht	= 3,
	Ulster		= 4,
	Munster		= 5,
} City;

typedef enum TravelClass {
	Economy = 1,
	First	= 2,
} TravelClass;

typedef enum TravelFreq {
	LESS_THAN_TREE = 1,
	LESS_THAN_FIVE = 2,
	MORE_THAN_FIVE = 3,
} TravelFreq;

typedef struct Passenger {
	int			PPS_ID;
	char		firstName[MAX_STRING];
	char		secondName[MAX_STRING];
	int			yearBorn;
	char		email[MAX_STRING];
	City		cityOfDeparture;
	TravelClass travelClass;
	TravelFreq  travelFrequency;
} Passenger;

typedef struct User {
	char username[MAX_STRING];
	char password[PASSWORD_LEN];
} User;