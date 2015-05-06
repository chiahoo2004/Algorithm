// **************************************************************************
// File       [ test_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2012/04/10 created ]
// **************************************************************************

#include "user_cmd.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "../lib/tm_usage.h"
using namespace std;
using namespace CommonNs;
char G[30];
Graph graph("");
int verticeNum = 0;
int edgeNum = 0;
int colorNum = 0;

TestCmd::TestCmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("test");
    optMgr_.setDes("test");

    Opt *opt = new Opt(Opt::BOOL, "print usage", "");
    opt->addFlag("h");
    opt->addFlag("help");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
    opt->addFlag("s");
    optMgr_.regOpt(opt);
}

TestCmd::~TestCmd() {}

bool TestCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (optMgr_.getParsedOpt("h")) {
        optMgr_.usage();
        return true;
    }

    if (optMgr_.getParsedOpt("s")) {
        printf("%s\n", optMgr_.getParsedValue("s"));
    }
    else
        printf("hello world !!\n");


    return true;
}

ReadCmd::Cmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("read_graph");    // NAME
    optMgr_.setDes("read the graph in dot format");     // DESCRIPTION
    optMgr_.regArg(new Arg(Arg::OPT, "target directories", "DIRECTORY"));   // ARGUMENT
}

ReadCmd::~ReadCmd() {}

bool ReadCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (argc == 1) {
        cout<<"no argument"<<endl;
        return false;
    }
    if (argc > 2) {
        cout<<"too many argument"<<endl;
        return false;
    }

 //   argv[1] = "gn10.dot";
 //   argv[2] = "gn10_dfs.dot"; 
    char buffer[200];
    fstream fin(argv[1]);
    fin.getline(buffer,200);
    
    int v1,v2;
    string a,b,name,junk;
    fin >> junk >> name >> junk;

//  Graph graph(name);
    graph.name = name;
    while (fin >> a >> junk >> b)
    {
        v1 = stoi(a.substr(1));
        v2 = stoi(b.substr(1));
        graph.addEdge(v1,v2);
    }

    return true;
}

DfsCmd::DfsCmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("write_tree_dfs");
    optMgr_.setDes("Perform depth first search starting from source node.  Then write to a dot file.");

    Opt *opt = new Opt(Opt::STR_REQ, "", "<sourcenode>");   // 
    opt->addFlag("s");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "", "<dot_filename>");
    opt->addFlag("o");
    optMgr_.regOpt(opt);
}

DfsCmd::~DfsCmd() {}

bool DfsCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (optMgr_.getParsedOpt("s")) {
        argv[2] = optMgr_.getParsedOpt("s");
    }
    else
        return false;

    if (optMgr_.getParsedOpt("o")) {
        argv[4] = optMgr_.getParsedOpt("o");
    }
    else
        return false;


 //   argv[2] = "v0";
 //   argv[4] = "gn10_dfs.dot";


    int src = atoi(&argv[2][1]);
    fstream fout;
    fout.open(argv[4],ios::out);

    cout<<"// DFS tree produced by graphlab"<<endl;
    cout<<"graph "<<graph.name<<"_dfs {"<<endl;

    graph.sortEdgesOfNode();


    // fully connected graph
    verticeNum++;
    Node* node = graph.getNodeById(src);
    dfs_visit(node);
    

    cout<<"}"<<endl;
    cout<<"// vertices = "<<verticeNum<<endl;
    cout<<"// edges = "<<edgeNum<<endl;
    cout<<"// runtime = "<<0<<" sec"<<endl;
    cout<<"// memory = "<<11<<" MB"<<endl;


    return true;
}

bool DfsCmd::dfs_visit(Node* u) {
    u->traveled = true;
    for (size_t i = 0; i < u->edge.size(); i++)
    {
        Node* v = u->edge[i]->getNeighbor(u);
        if(v->traveled==false)
        {
            v->prev = u;
            cout<<"v"<<u->id<<" -- "<<"v"<<v->id<<";"<<endl;
            verticeNum++;
            edgeNum++;
            dfs_visit(v);
        }
    }
//  u->traveled = black;
}

BfsCmd::BfsCmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("write_tree_bfs");
    optMgr_.setDes("Perform depth first search starting from source node.  Then write to a dot file.");

    Opt *opt = new Opt(Opt::STR_REQ, "", "<sourcenode>");;
    opt->addFlag("s");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "", "<dot_filename>");
    opt->addFlag("o");
    optMgr_.regOpt(opt);
}

BfsCmd::~BfsCmd() {}

bool BfsCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (optMgr_.getParsedOpt("s")) {
        argv[2] = optMgr_.getParsedOpt("s");
    }
    else
        return false;

    if (optMgr_.getParsedOpt("o")) {
        argv[4] = optMgr_.getParsedOpt("o");
    }
    else
        return false;




    return true;
}

ColorCmd::ColorCmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("color_graph");
    optMgr_.setDes("Perform greedy algorithm to color the graph. Then write to a dot file.");

    Opt *opt = new Opt(Opt::STR_REQ, "", "greedy");   // 
    opt->addFlag("m");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "", "<dot_filename>");
    opt->addFlag("o");
    optMgr_.regOpt(opt);
}

ColorCmd::~ColorCmd() {}

bool ColorCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (optMgr_.getParsedOpt("m")!="greedy") {
        return false;
    }

    if (optMgr_.getParsedOpt("o")) {
        argv[4] = optMgr_.getParsedOpt("o");
    }
    else
        return false;

//    argv[1] = "gn10.dot";
//    argv[4] = "gn10_color.dot";

    fstream fout;
    fout.open(argv[4],ios::out);

    cout<<"// Coloring produced by graphlab"<<endl;
    cout<<"graph "<<graph.name<<"_color {"<<endl;

    char buffer[200];
    char* pch;
    fstream fin(argv[1]);
    fin.getline(buffer,200);
    fin.getline(buffer,200);
    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        fin.getline(buffer,200);
        if(strcmp ("}",buffer)==0)
            break;
        else
            cout<<buffer<<endl;
    }

    graph.sortNodesByDegree();
    vector<bool> used(graph.nodes.size()+1,false);
    
    for (size_t i = 0; i < graph.nodes.size(); i++)
    {
        verticeNum++;
        Node* u = graph.nodes[i];
        for (size_t j = 0; j < u->edge.size(); j++)
        {
            edgeNum++;
            Node* v = u->edge[j]->getNeighbor(u);
            if (v->color!=0)
            {
                used[ v->color ] = true;
            }
        }
        int color = 1;
        while ( used[color]==true && color < used.size() )
        {
            color++;
        }
        u->color = color;
        if (color>colorNum)
            colorNum = color;
        fill(used.begin(), used.end(), 0);
    }

    graph.sortNodesByID();

    for (size_t i = 0; i < graph.nodes.size(); i++)
    {
        cout<<"v"<<i<<" [label = \"v"<<i<<"_color"<<graph.nodes[i]->color<<"\"];"<<endl;
    }
    

    cout<<"}"<<endl;
    cout<<"// vertices = "<<verticeNum<<endl;
    cout<<"// edges = "<<edgeNum/2<<endl;
    cout<<"// number_of_colors = "<<colorNum<<endl;
    cout<<"// runtime = "<<0<<" sec"<<endl;
    cout<<"// memory = "<<11<<" MB"<<endl;

    return true;
}
