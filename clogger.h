#ifndef CLOGGER_H
#define CLOGGER_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdarg.h>
#include "mythread/locker.h"

using std::cout;
using std::endl;
using std::string;

enum LOGS_LEVEL{
    LOG_DEBUG=0,
    LOG_INFO,
    LOG_WARNNING,
    LOG_ERROR,
    LOG_GETPACKAGE
};

//日志操作类
class CLogger{
public:
    typedef struct LogsNode{
        string s_time;
        string s_level;
		string s_log_text;
    }LogsNode;

    //    enum LOGS_SAVE{
    //        TEXT_FILE_SAVE=0,
    //        DB_FILE_SAVE,
    
    //    };

public:

//    static CLogger* getInstance(){
//        static CLogger instance;
//        return &instance;
//    }

    CLogger();
    virtual ~CLogger();

    virtual bool init(const char* file_name,int log_buf_size=8192,int split_lines=5000000); //初始化

    bool setTextFile(const char * _file_name);  //设置存储日志的文本文件
    virtual void write_log(LOGS_LEVEL level,const char * format,...);   //日志写入

    void flush(void);
protected:

    //private:

    pthread_mutex_t *m_mutex;

    char dir_name[1024];
    char log_name[1024];
    std::string log_file_name;
    int m_split_lines;
    int m_log_buf_size;
    long long m_count;
    int m_today;
    FILE *m_fp;
    char *m_buf;

}; // CLogger

#endif // CLOGGER_H
