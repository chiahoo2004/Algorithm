// **************************************************************************
// File       [ test_cmd.h ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2012/04/10 created ]
// **************************************************************************

#ifndef _TEST_CMD_H_
#define _TEST_CMD_H_

#include "../lib/cmd.h"
#include "graph.h"

class TestCmd : public CommonNs::Cmd {
public:
         TestCmd(const char * const name);
         ~TestCmd();

    bool exec(int argc, char **argv);
};

class ReadCmd : public CommonNs::Cmd {
public:
         ReadCmd(const char * const name);
         ~ReadCmd();

    bool exec(int argc, char **argv);
};

class DfsCmd : public CommonNs::Cmd {
public:
         DfsCmd(const char * const name);
         ~DfsCmd();

    bool exec(int argc, char **argv);
    bool dfs_visit(Node* u, fstream& fout);
};

class BfsCmd : public CommonNs::Cmd {
public:
         BfsCmd(const char * const name);
         ~BfsCmd();

    bool exec(int argc, char **argv);
};

class ColorCmd : public CommonNs::Cmd {
public:
         ColorCmd(const char * const name);
         ~ColorCmd();

    bool exec(int argc, char **argv);
};

#endif
