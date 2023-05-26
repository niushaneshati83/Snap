#ifndef TIME_MISSION_H
#define TIME_MISSION_H


#include"mission.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>

using namespace std;

class Time_mission :public mission
{
    private:
    long int target_time_in_minutes=0;
    long int target_time_in_seconds=0;
    public:
    Time_mission(int m_i,long int s_ts=0,long int e_ts=0,long int t_t_i_m=0,long int r_a=0);
     bool check_target_reward(long int target_time,long int reward);
     void set_target(long int target_time_in_minutes);
     void complete_mission(long int start_t,long int end_t,long int distance);

};

#endif