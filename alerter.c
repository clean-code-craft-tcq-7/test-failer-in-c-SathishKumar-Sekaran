#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int returnAlertStub = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int testNetworkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return returnAlertStub;
}

void alertInCelcius(float farenheit,int (*fun_ptr_NetworkAlert)(float)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = (*fun_ptr_NetworkAlert)(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
    printf("%d alerts failed.\n", alertFailureCount);
}

int main() {
    returnAlertStub = 200;
    alertInCelcius(400.5,testNetworkAlertStub);
    assert(alertFailureCount == 0);
    returnAlertStub = 500;
    alertInCelcius(303.6,testNetworkAlertStub);
    assert(alertFailureCount == 1);
	returnAlertStub = 200;
    alertInCelcius(250.8,testNetworkAlertStub);
    assert(alertFailureCount == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
