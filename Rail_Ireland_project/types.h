#pragma once

#define MAX_USERS 3
#define MAX_STRING 100
#define PASSWORD_LEN 7

#define USER_PATH	"login.txt"
#define DB_PATH		"passengers.txt"


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
	LESS_THAN_THREE = 1,
	LESS_THAN_FIVE = 2,
	MORE_THAN_FIVE = 3,
} TravelFreq;

typedef enum ValidationResult {
	VALIDATION_OK = 0,
	ERROR_PPS = 1,
	ERROR_YEAR = 2,
	ERROR_EMAIL = 3,
	ERROR_FIRSTNAME = 4,
	ERROR_SECONDNAME = 5,
} ValidationResult;

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