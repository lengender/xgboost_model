#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include "xgboost/c_api.h"
#include <map>
#include <list>
#include <sys/time.h>
using namespace std;
#define MAX_LEN 500000

int main()
{
	
	BoosterHandle h_booster;
    XGBoosterCreate(0, 0, &h_booster);
    XGBoosterSetParam(h_booster, "nthread", "1"); //TODO: change the nthread here. Bigger nthread causes more cost time.
    XGBoosterLoadModel(h_booster,"xgb_sample.model");

	float test[1][3];
	test[0][0] = 1;
	test[0][1] = 60;
	test[0][2] = 38;

    DMatrixHandle h_test[1];
	XGDMatrixCreateFromMat((float*)test, 1, 3, -1, &h_test[0]);
	
    bst_ulong out_len;
    const float *f;
    XGBoosterPredict(h_booster, h_test[0], 0, 0, &out_len, &f);
    for (unsigned int i = 0; i<out_len; i++)
        std::cout << "prediction[" << i << "]=" << f[i] << std::endl;
    
	// free xgboost internal structures
	XGDMatrixFree(h_test[0]);
	XGBoosterFree(h_booster);
	return 1;
}
