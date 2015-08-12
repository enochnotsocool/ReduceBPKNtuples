#ifndef ConstantNumbers_H
#define ConstantNumbers_H

//const float LUMINOSITY       = 5145.6999999999998; 
//const float LUMINOSITY       = 1421.2; 
//const float LUMINOSITY       = 3512.0; 
//const float LUMINOSITY       = 2752.0; 
const float LUMINOSITY       = 16609; 	//193752-208686
const double ELECTRON_MASS   = 0.0005109989;
const double MUON_MASS       = 0.105658;
const double Z_MASS          = 91.1876;
const double W_MASS          = 80.398;
const double b_MASS          = 4.19;
const double top_MASS        = 172.9;

enum RunStatus{
    Normal,
    UncXsecPlus,
    UncXsecMinus,
    UncPUPlus,
    UncPUMinus,
    RunStatusSize
};

string RunStatusNames[RunStatusSize] = {
    "",
    "UncXsecPlus",
    "UncXsecMinus",
    "UncPUPlus",
    "UncPUMinus"
};

#endif
