#include "utils.h"

const char* getCityString(City city) {
    switch (city) {
        case Dublin:   return "Dublin";
        case Leinster: return "Excavator";
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