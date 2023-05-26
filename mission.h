#ifndef MISSION_H
#define MISSION_H
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>
using namespace std;
class mission
{
    protected:
    int mission_id=0;
    long int start_timestamp=0;
    long int end_timestmp=0;
    long int reward_amount=0;
    long int end_time_trip=0;
    string status="ongoing";
    public:
    int get_mission_id();
    bool check_mission_id(vector<mission*>missions,int mission_id);
    bool check_time(long int start_time,long int end_time);
    virtual void complete_mission(long int start_t=0,long int end_t=0,long int distance=0)=0;
    string get_status();
    long int get_start_time();
    long int get_end_time_trip();
    long int get_reward();
};
#endif
