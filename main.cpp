// TESTING_ON
#define TESTING_OFF

#include "gtest/gtest.h"

#ifdef TESTING_ON

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

#else
#include "mainwindow.h"

const bool RUNNER_MODE = true;

#include <QApplication>
#include "fileiorunner.h"

int main(int argc, char *argv[])
{
    if (RUNNER_MODE) {
        FileIoRunner().execute();
    } else {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}

#endif

//id=22501,val2=11,meta_val1=51,val3=12
//id=22502,val2=22,meta_val1=52,val3=22
//id=22503,val2=31,meta_val1=53,val3=32
//id=22504,val2=42,meta_val1=82,val3=42
//id=22505,val2=51,meta_val1=70,val3=52


//<?xml version="1.0"?>
//<castellions>
//	<castellion id="22501" val2="11" meta_val1="51" val3="12" />
//</castellions>
