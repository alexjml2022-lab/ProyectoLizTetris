#include "colors.h"
#include <iostream>
using namespace std;
const Color neruGrey = {69, 70, 65, 255};
const Color neruYellow = {242, 188, 87, 255};
const Color neruOrange = {217, 146, 59, 255};
const Color neruCremita = {242, 196, 155, 255};
const Color neruLiteGrey = {158, 152, 140, 255};
const Color mikuCyan = {134, 206, 203, 255};
const Color mikuDarkCyan = {19, 122, 127, 255};
const Color mikuFiusha = {225, 40, 133, 255};

vector<Color> GetCellColors()
{
    return {
        neruGrey,
        mikuFiusha,
        neruYellow,
        mikuDarkCyan,
        neruOrange,
        mikuCyan,
        neruCremita,
        neruLiteGrey,
    };
}