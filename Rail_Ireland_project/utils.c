#include "utils.h"

#include <string.h>

const char* getCityString(City city) {
    switch (city) {
        case Dublin:   return "Dublin";
        case Leinster: return "Leinster";
        case Connacht: return "Connacht";
        case Ulster:   return "Ulster";
        case Munster:  return "Munster";
        default:       return "Unknown";
    }
}

const char* getTravelClassString(TravelClass tc) {
    switch (tc) {
        case Economy:  return "Economy";
        case First:    return "First";
        default:       return "Unknown";
    }
}

const char* getTravelFreqString(TravelFreq tf) {
    switch (tf) {
    case LESS_THAN_THREE: return "Less than three";
    case LESS_THAN_FIVE:  return "Less than five";
    case MORE_THAN_FIVE:  return "More than five";
    default:              return "Unknown";
    }
}

int validatePassenger(const Passenger* p) {
    
    if (p->PPS_ID <= 0) return ERROR_PPS;
    if (strcmp(p->email, ".@.com") == 0) return ERROR_EMAIL;
    if (p->yearBorn <= 1900 && p->yearBorn > 2025) return ERROR_YEAR;
    if (strlen(p->firstName) <= 0) return ERROR_FIRSTNAME;
    if (strlen(p->secondName) <= 0) return ERROR_SECONDNAME;

    return VALIDATION_OK;
}

const char* getValidationString(ValidationResult result) {
    const char* errors[] = {
        "\n(+) All fields are valid",
        "\n(-) Error: PPS ID is required!",
        "\n(-) Error: Year must be between 1900 and 2025!",
        "\n(-) Error: Email is required!",
        "\n(-) Error: First name is required!",
        "\n(-) Error: Second name is required!",
    };

    return errors[result];
}