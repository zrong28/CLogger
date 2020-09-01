#include <iostream>
#include "clogger.h"
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
    CLogger logger;
    logger.init("./log/test.log",8192,3);
    while(1){
        usleep(5*100000);
        logger.write_log(LOGS_LEVEL::LOG_DEBUG,"ADFASDFASDFASDFASDFASDFAS");
    }
    return 0;
}
