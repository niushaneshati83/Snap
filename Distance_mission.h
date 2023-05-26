#ifndef DISTANCE_MISSION_H
#define DISTANCE_MISSION_H
#include "mission.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<malloc.h>
#include<fstream>
#include<algorithm>
using namespace std;

class Distance_mission :public mission 
{
    private:
    int target_distance_in_meters=0;
    long int distance_m=0;
    public:
    Distance_mission(int m_i,long int s_ts=0,long int e_ts=0,long int t_d_i_m=0,long int r_a=0);
    bool check_target_reward(long int target_distance,long int reward);
    void complete_mission(long int start_t,long int end_t,long int distance);
    long int get_distance_m();
};
#endif